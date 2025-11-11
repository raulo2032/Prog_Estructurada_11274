/* farmacia.c
Sistema simple de administración de farmacia sin usar structs.

* Control de stock
* Registro de ventas (medicamentos OTC y con receta)
* Informes diarios y mensuales (se guardan en carpeta reports/)
* Reporte de stock crítico (acceso solo para dueño)
* Todas las ventas del mes en memoria; al finalizar mes se puede emitir informe y borrar ventas
  Restricciones respetadas: no se usan estructuras (struct), se usan arrays y bucles for/while/switch.
  Compilar: gcc -o farmacia farmacia.c
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 200
#define MAX_NAME_LEN 60
#define MAX_SALES 5000
#define MAX_DAYS 31
#define REPORTS_DIR "reports"
#define OWNER_PASS "admin123"

int product_code[MAX_PRODUCTS];
char product_name[MAX_PRODUCTS][MAX_NAME_LEN];
double product_price[MAX_PRODUCTS];
int product_stock[MAX_PRODUCTS];
int product_otc[MAX_PRODUCTS]; /* 1 = venta libre, 0 = requiere receta */
int product_stock_critical[MAX_PRODUCTS];
int product_count = 0;

/* Ventas del mes (arrays paralelos) */
int sale_day[MAX_SALES]; /* dia del mes (1..31) */
int sale_product_code[MAX_SALES];
int sale_qty[MAX_SALES];
double sale_total_price[MAX_SALES];
int sale_is_prescription[MAX_SALES]; /* 1 si fue con receta */
char sale_dni[MAX_SALES][20];        /* DNI del comprador si fue con receta */
int sales_count = 0;

/* Prototipos */
void ensure_reports_dir();
int find_product_index_by_code(int code);
void add_product();
void list_products();
void modify_stock();
void sale_register();
void report_daily();
void report_monthly();
void save_monthly_report_to_file(int month, int year);
void clear_month_sales();
int owner_login();
void low_stock_report();
void report_day_demand();
void press_enter_to_continue();
int input_int();
double input_double();
void safe_gets(char *buf, int len);

/* main: menú */
int main()
{
    int option;
    int running = 1;
    ensure_reports_dir();
    while (running)
    {
        printf("\n==== SISTEMA DE GESTION - FARMACIA ====\n");
        printf("1) Agregar producto\n");
        printf("2) Listar productos\n");
        printf("3) Modificar stock de producto\n");
        printf("4) Registrar venta\n");
        printf("5) Emitir informe diario (pantalla)\n");
        printf("6) Emitir informe mensual y guardar en carpeta\n");
        printf("7) Emitir informe de un dia (guardado/consulta)\n");
        printf("8) Mostrar medicamentos por debajo de stock critico (solo dueño)\n");
        printf("9) Borrar datos de ventas del mes (nuevo mes) (solo dueño)\n");
        printf("0) Salir\n");
        printf("Elija opcion: ");
        option = input_int();
        switch (option)
        {
        case 1:
            add_product();
            break;
        case 2:
            list_products();
            break;
        case 3:
            modify_stock();
            break;
        case 4:
            sale_register();
            break;
        case 5:
            report_daily();
            break;
        case 6:
            report_monthly();
            break;
        case 7:
            report_day_demand();
            break;
        case 8:
            if (owner_login())
                low_stock_report();
            else
                printf("Acceso denegado. Solo propietario.\n");
            break;
        case 9:
            if (owner_login())
            {
                printf("Confirma borrar todos los datos de ventas del mes actual? 1=Si 0=No: ");
                if (input_int() == 1)
                {
                    clear_month_sales();
                    printf("Ventas del mes borradas.\n");
                }
                else
                    printf("Accion cancelada.\n");
            }
            else
                printf("Acceso denegado. Solo propietario.\n");
            break;
        case 0:
            running = 0;
            break;
        default:
            printf("Opcion invalida.\n");
        }
    }
    printf("Saliendo...\n");
    return 0;
}

/* Crear directorio reports si no existe */
void ensure_reports_dir()
{
/* Uso de system para crear carpeta (portable en sistemas Unix/Windows con mkdir) */
#ifdef _WIN32
    system("mkdir reports 2>nul");
#else
    system("mkdir -p " REPORTS_DIR " 2>/dev/null");
#endif
}

/* Buscar índice de producto por código, -1 si no existe */
int find_product_index_by_code(int code)
{
    int i;
    for (i = 0; i < product_count; i++)
    {
        if (product_code[i] == code)
            return i;
    }
    return -1;
}

/* Agregar producto nuevo */
void add_product()
{
    if (product_count >= MAX_PRODUCTS)
    {
        printf("Limite de productos alcanzado.\n");
        return;
    }
    int code;
    char name[MAX_NAME_LEN];
    double price;
    int stock, otc, critical;
    printf("Codigo de producto (entero): ");
    code = input_int();
    if (find_product_index_by_code(code) != -1)
    {
        printf("Ya existe un producto con ese codigo.\n");
        return;
    }
    printf("Nombre del producto: ");
    safe_gets(name, MAX_NAME_LEN);
    printf("Precio: ");
    price = input_double();
    printf("Cantidad en stock: ");
    stock = input_int();
    printf("Es de venta libre? 1=Si 0=No: ");
    otc = input_int();
    printf("Stock critico (para pedir reposicion): ");
    critical = input_int();

    product_code[product_count] = code;
    strncpy(product_name[product_count], name, MAX_NAME_LEN - 1);
    product_name[product_count][MAX_NAME_LEN - 1] = '\0';
    product_price[product_count] = price;
    product_stock[product_count] = stock;
    product_otc[product_count] = (otc ? 1 : 0);
    product_stock_critical[product_count] = critical;
    product_count++;
    printf("Producto agregado.\n");
}

/* Listar productos */
void list_products()
{
    int i;
    if (product_count == 0)
    {
        printf("No hay productos cargados.\n");
        return;
    }
    printf("\nListado de productos:\n");
    printf("Cod | Nombre                          | Precio   | Stock | OTC | Critico\n");
    for (i = 0; i < product_count; i++)
    {
        printf("%3d | %-30s | %8.2f | %5d |  %d  | %7d\n",
               product_code[i],
               product_name[i],
               product_price[i],
               product_stock[i],
               product_otc[i],
               product_stock_critical[i]);
    }
}

/* Modificar stock (sumar o restar) */
void modify_stock()
{
    int code = 0;
    int idx, change;
    printf("Ingrese codigo de producto: ");
    code = input_int();
    idx = find_product_index_by_code(code);
    if (idx == -1)
    {
        printf("Producto no encontrado.\n");
        return;
    }
    printf("Stock actual: %d\n", product_stock[idx]);
    printf("Ingrese cambio en stock (positivo para agregar, negativo para quitar): ");
    change = input_int();
    product_stock[idx] += change;
    if (product_stock[idx] < 0)
        product_stock[idx] = 0;
    printf("Stock actualizado: %d\n", product_stock[idx]);
}

/* Registrar venta */
void sale_register()
{
    if (sales_count >= MAX_SALES)
    {
        printf("Limite de ventas alcanzado.\n");
        return;
    }
    int code, idx, qty, is_presc;
    char dni_buf[20];
    int day;
    printf("Ingrese codigo de producto: ");
    code = input_int();
    idx = find_product_index_by_code(code);
    if (idx == -1)
    {
        printf("Producto no encontrado.\n");
        return;
    }
    printf("Producto: %s | Precio: %.2f | Stock: %d | OTC: %d\n",
           product_name[idx], product_price[idx], product_stock[idx], product_otc[idx]);
    printf("Ingrese cantidad a vender: ");
    qty = input_int();
    if (qty <= 0)
    {
        printf("Cantidad invalida.\n");
        return;
    }
    if (qty > product_stock[idx])
    {
        printf("Stock insuficiente.\n");
        return;
    }
    if (product_otc[idx] == 0)
    {
        /* Requiere receta: pedir DNI y almacenar */
        is_presc = 1;
        printf("Este medicamento requiere receta.\n");
        printf("Ingrese DNI del comprador: ");
        safe_gets(dni_buf, sizeof(dni_buf));
    }
    else
    {
        is_presc = 0;
        dni_buf[0] = '\0';
    }
    printf("Ingrese dia del mes de la venta (1..31): ");
    day = input_int();
    if (day < 1 || day > MAX_DAYS)
    {
        printf("Dia invalido.\n");
        return;
    }

    /* Registrar venta */
    sale_day[sales_count] = day;
    sale_product_code[sales_count] = code;
    sale_qty[sales_count] = qty;
    sale_total_price[sales_count] = product_price[idx] * qty;
    sale_is_prescription[sales_count] = is_presc;
    strncpy(sale_dni[sales_count], dni_buf, sizeof(sale_dni[0]) - 1);
    sale_dni[sales_count][sizeof(sale_dni[0]) - 1] = '\0';
    sales_count++;

    /* Actualizar stock */
    product_stock[idx] -= qty;
    printf("Venta registrada. Total: %.2f\n", product_price[idx] * qty);
}

/* Informe diario: muestra totales por producto y total del dia */
void report_daily()
{
    int day, i;
    double total = 0.0;
    if (sales_count == 0)
    {
        printf("No hay ventas registradas este mes.\n");
        return;
    }
    printf("Ingrese dia del mes a informar (1..31): ");
    day = input_int();
    if (day < 1 || day > MAX_DAYS)
    {
        printf("Dia invalido.\n");
        return;
    }
    printf("\nInforme de ventas - Dia %d\n", day);
    printf("ProdCode | Nombre                       | Cant | Importe\n");
    for (i = 0; i < sales_count; i++)
    {
        if (sale_day[i] == day)
        {
            int idx = find_product_index_by_code(sale_product_code[i]);
            const char *pname = (idx == -1) ? "N/D" : product_name[idx];
            printf("%7d | %-27s | %4d | %8.2f\n",
                   sale_product_code[i], pname, sale_qty[i], sale_total_price[i]);
            total += sale_total_price[i];
        }
    }
    printf("Total del dia: %.2f\n", total);
}

/* Genera informe mensual por días y total mensual. guarda en archivo */
void report_monthly()
{
    if (sales_count == 0)
    {
        printf("No hay ventas registradas este mes.\n");
        return;
    }
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    int month = tm->tm_mon + 1;
    int year = tm->tm_year + 1900;
    double day_totals[MAX_DAYS + 1];
    int day_counts[MAX_DAYS + 1];
    int i, d;
    for (d = 0; d <= MAX_DAYS; d++)
    {
        day_totals[d] = 0.0;
        day_counts[d] = 0;
    }
    for (i = 0; i < sales_count; i++)
    {
        int sd = sale_day[i];
        if (sd >= 1 && sd <= MAX_DAYS)
        {
            day_totals[sd] += sale_total_price[i];
            day_counts[sd] += 1;
        }
    }
    printf("\nInforme mensual %02d/%04d\n", month, year);
    double total_month = 0.0;
    for (d = 1; d <= MAX_DAYS; d++)
    {
        if (day_counts[d] > 0)
        {
            printf("Dia %2d: Ventas = %d  |  Total = %.2f\n", d, day_counts[d], day_totals[d]);
            total_month += day_totals[d];
        }
    }
    printf("TOTAL MENSUAL: %.2f\n", total_month);
    save_monthly_report_to_file(month, year);
}

/* Guardar informe mensual en archivo en carpeta reports/ */
void save_monthly_report_to_file(int month, int year)
{
    char fname[256];
    int i, d;
    double day_totals[MAX_DAYS + 1];
    int day_counts[MAX_DAYS + 1];
    FILE *f;
    for (d = 0; d <= MAX_DAYS; d++)
    {
        day_totals[d] = 0.0;
        day_counts[d] = 0;
    }
    for (i = 0; i < sales_count; i++)
    {
        int sd = sale_day[i];
        if (sd >= 1 && sd <= MAX_DAYS)
        {
            day_totals[sd] += sale_total_price[i];
            day_counts[sd] += 1;
        }
    }
    snprintf(fname, sizeof(fname), REPORTS_DIR "/monthly_%02d_%04d.txt", month, year);
    f = fopen(fname, "w");
    if (!f)
    {
        printf("Error al crear archivo de informe: %s\n", fname);
        return;
    }
    fprintf(f, "Informe Mensual %02d/%04d\n", month, year);
    fprintf(f, "Dia | CantVentas | Total\n");
    double total_month = 0.0;
    for (d = 1; d <= MAX_DAYS; d++)
    {
        if (day_counts[d] > 0)
        {
            fprintf(f, "%2d  | %10d | %8.2f\n", d, day_counts[d], day_totals[d]);
            total_month += day_totals[d];
        }
    }
    fprintf(f, "TOTAL_MENSUAL | %.2f\n", total_month);
    fclose(f);
    printf("Informe mensual guardado en: %s\n", fname);
}

/* Borrar datos de ventas del mes (pero no productos) */
void clear_month_sales()
{
    int i;
    for (i = 0; i < sales_count; i++)
    {
        sale_day[i] = 0;
        sale_product_code[i] = 0;
        sale_qty[i] = 0;
        sale_total_price[i] = 0.0;
        sale_is_prescription[i] = 0;
        sale_dni[i][0] = '\0';
    }
    sales_count = 0;
}

/* Login simple de propietario */
int owner_login()
{
    char pass[80];
    printf("Contrasena propietario: ");
    safe_gets(pass, sizeof(pass));
    if (strcmp(pass, OWNER_PASS) == 0)
        return 1;
    return 0;
}

/* Lista medicamentos por debajo de stock critico (solo dueño) */
void low_stock_report()
{
    int i, found = 0;
    printf("\nMedicamentos por debajo del stock critico:\n");
    printf("Cod | Nombre                        | Stock | Critico\n");
    for (i = 0; i < product_count; i++)
    {
        if (product_stock[i] <= product_stock_critical[i])
        {
            printf("%3d | %-28s | %5d | %7d\n",
                   product_code[i], product_name[i], product_stock[i], product_stock_critical[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No hay medicamentos por debajo del stock critico.\n");
}

/* Informe a demanda: ventas de cualquier dia y estado de stock */
void report_day_demand()
{
    int day;
    printf("Ingrese dia a consultar (1..31): ");
    day = input_int();
    if (day < 1 || day > MAX_DAYS)
    {
        printf("Dia invalido.\n");
        return;
    }
    /* Mostrar ventas del dia */
    printf("\nVentas del dia %d:\n", day);
    int i, any = 0;
    double total = 0.0;
    for (i = 0; i < sales_count; i++)
    {
        if (sale_day[i] == day)
        {
            int idx = find_product_index_by_code(sale_product_code[i]);
            const char *pname = (idx == -1) ? "N/D" : product_name[idx];
            printf("Prod %d - %-25s | Cant %d | Importe %.2f", sale_product_code[i], pname, sale_qty[i], sale_total_price[i]);
            if (sale_is_prescription[i])
            {
                printf(" | DNI: %s", sale_dni[i]);
            }
            printf("\n");
            total += sale_total_price[i];
            any = 1;
        }
    }
    if (!any)
        printf("No se registraron ventas ese dia.\n");
    else
        printf("Total del dia: %.2f\n", total);

    /* Mostrar estado de stock */
    printf("\nEstado de stock actual:\n");
    list_products();
}

/* Pausa */
void press_enter_to_continue()
{
    printf("Presione ENTER para continuar...");
    while (getchar() != '\n')
    { /* vacio */
    }
}

/* Lecturas seguras y auxiliares */
int input_int()
{
    char buf[64];
    int val = 0;
    safe_gets(buf, sizeof(buf));
    sscanf(buf, "%d", &val);
    return val;
}
double input_double()
{
    char buf[64];
    double val = 0.0;
    safe_gets(buf, sizeof(buf));
    sscanf(buf, "%lf", &val);
    return val;
}
void safe_gets(char *buf, int len)
{
    if (fgets(buf, len, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }
    size_t L = strlen(buf);
    if (L > 0 && buf[L - 1] == '\n')
        buf[L - 1] = '\0';
}
