#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Constantes */
#define MAX_PRODUCTS 200
#define MAX_NAME_LEN 60
#define MAX_SALES 5000
#define MAX_DAYS 31
#define OWNER_PASS "admin123"
#define MAX_STORED_REPORTS 48
#define REPORT_TEXT_LEN 4096

/* ==== PROTOTIPOS ==== */
int find_product_index_by_code(int *product_code, int product_count, int code);


void low_stock_report(
    int product_count,
    int product_code[],
    char product_name[][MAX_NAME_LEN],
    int product_stock[],
    int product_stock_critical[]
);




void add_product(int *product_code, char product_name[][MAX_NAME_LEN], double *product_price,
                 int *product_stock, int *product_otc, int *product_stock_critical, int *product_count);
void list_products(int *product_code, char product_name[][MAX_NAME_LEN], double *product_price,
                   int *product_stock, int *product_otc, int *product_stock_critical, int product_count);
void modify_stock(int *product_code, int *product_stock, int product_count);
void sale_register(int *product_code, char product_name[][MAX_NAME_LEN], double *product_price,
                   int *product_stock, int *product_otc, int product_count,
                   int *sale_day, int *sale_product_code, int *sale_qty,
                   double *sale_total_price, int *sale_is_prescription, char sale_dni[][20],
                   int *sales_count);
void report_daily(int *product_code, char product_name[][MAX_NAME_LEN], double *product_price,
                  int *sale_day, int *sale_product_code, int *sale_qty, double *sale_total_price,
                  int sales_count, int product_count);
void report_monthly_and_store(int *sale_day, double *sale_total_price, int sales_count,
                              int *report_month, int *report_year, char report_text[][REPORT_TEXT_LEN],
                              int *report_count);
void clear_month_sales(int *sale_day, int *sale_product_code, int *sale_qty,
                       double *sale_total_price, int *sale_is_prescription,
                       char sale_dni[][20], int *sales_count);
int owner_login();
void report_day_demand(int *product_code, char product_name[][MAX_NAME_LEN],
                       double *product_price, int *sale_day, int *sale_product_code,
                       int *sale_qty, double *sale_total_price, int *sale_is_prescription,
                       char sale_dni[][20], int sales_count, int product_count);
void show_stored_reports(int *report_month, int *report_year, char report_text[][REPORT_TEXT_LEN], int report_count);
void view_report(int *report_month, int *report_year, char report_text[][REPORT_TEXT_LEN], int report_count);
int input_int();
double input_double();
void safe_gets(char *buf, int len);

/* ==== FUNCION PRINCIPAL ==== */
int main() {
    int product_code[MAX_PRODUCTS];
    char product_name[MAX_PRODUCTS][MAX_NAME_LEN];
    double product_price[MAX_PRODUCTS];
    int product_stock[MAX_PRODUCTS];
    int product_otc[MAX_PRODUCTS];
    int product_stock_critical[MAX_PRODUCTS];
    int product_count = 0;

    int sale_day[MAX_SALES];
    int sale_product_code[MAX_SALES];
    int sale_qty[MAX_SALES];
    double sale_total_price[MAX_SALES];
    int sale_is_prescription[MAX_SALES];
    char sale_dni[MAX_SALES][20];
    int sales_count = 0;

    int report_month[MAX_STORED_REPORTS];
    int report_year[MAX_STORED_REPORTS];
    char report_text[MAX_STORED_REPORTS][REPORT_TEXT_LEN];
    int report_count = 0;

    int running = 1, option = 0;

    while (running) {
        printf("\n==== SISTEMA DE GESTION - FARMACIA (SIN VARIABLES GLOBALES) ====\n");
        printf("1) Agregar producto\n");
        printf("2) Listar productos\n");
        printf("3) Modificar stock de producto\n");
        printf("4) Registrar venta\n");
        printf("5) Emitir informe diario (pantalla)\n");
        printf("6) Emitir informe mensual y guardarlo EN MEMORIA\n");
        printf("7) Emitir informe de un dia (consulta)\n");
        printf("8) Mostrar medicamentos bajo stock critico (solo dueño)\n");
        printf("9) Borrar datos de ventas (nuevo mes) (solo dueño)\n");
        printf("10) Listar informes guardados (en memoria)\n");
        printf("11) Ver informe guardado\n");
        printf("0) Salir\n");
        printf("Elija opcion: ");
        option = input_int();

        switch (option) {
            case 1:
                add_product(product_code, product_name, product_price, product_stock,
                            product_otc, product_stock_critical, &product_count);
                break;
            case 2:
                list_products(product_code, product_name, product_price, product_stock,
                              product_otc, product_stock_critical, product_count);
                break;
            case 3:
                modify_stock(product_code, product_stock, product_count);
                break;
            case 4:
                sale_register(product_code, product_name, product_price, product_stock,
                              product_otc, product_count, sale_day, sale_product_code, sale_qty,
                              sale_total_price, sale_is_prescription, sale_dni, &sales_count);
                break;
            case 5:
                report_daily(product_code, product_name, product_price, sale_day,
                             sale_product_code, sale_qty, sale_total_price, sales_count, product_count);
                break;
            case 6:
                report_monthly_and_store(sale_day, sale_total_price, sales_count,
                                         report_month, report_year, report_text, &report_count);
                break;
            case 7:
                report_day_demand(product_code, product_name, product_price, sale_day,
                                  sale_product_code, sale_qty, sale_total_price, sale_is_prescription,
                                  sale_dni, sales_count, product_count);
                break;
            case 8:
                if (owner_login())
                    low_stock_report(product_code, product_name, product_stock,
                                     product_stock_critical, product_count);
                else
                    printf("Acceso denegado.\n");
                break;
            case 9:
                if (owner_login()) {
                    printf("Confirma borrar todas las ventas? 1=Si 0=No: ");
                    if (input_int() == 1)
                        clear_month_sales(sale_day, sale_product_code, sale_qty,
                                          sale_total_price, sale_is_prescription,
                                          sale_dni, &sales_count);
                } else
                    printf("Acceso denegado.\n");
                break;
            case 10:
                show_stored_reports(report_month, report_year, report_text, report_count);
                break;
            case 11:
                view_report(report_month, report_year, report_text, report_count);
                break;
            case 0:
                running = 0;
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    }
    printf("Saliendo...\n");
    return 0;
}

/* ==== FUNCIONES AUXILIARES ==== */
int find_product_index_by_code(int *product_code, int product_count, int code) {
    int i, found = -1;
    for (i = 0; i < product_count; i++) {
        if (product_code[i] == code)
            found = i;
    }
    return found;
}

/* Agregar producto */
void add_product(int *product_code, char product_name[][MAX_NAME_LEN], double *product_price,
                 int *product_stock, int *product_otc, int *product_stock_critical, int *product_count) {
    int continuar = 1;
    if (*product_count >= MAX_PRODUCTS) {
        printf("Limite de productos alcanzado.\n");
        continuar = 0;
    }

    if (continuar) {
        int code, stock, otc, critical;
        double price;
        char name[MAX_NAME_LEN];

        printf("Codigo: ");
        code = input_int();
        if (find_product_index_by_code(product_code, *product_count, code) != -1) {
            printf("Ya existe.\n");
            continuar = 0;
        }

        if (continuar) {
            printf("Nombre: ");
            safe_gets(name, MAX_NAME_LEN);
            printf("Precio: ");
            price = input_double();
            printf("Stock: ");
            stock = input_int();
            printf("Venta libre? (1=Si 0=No): ");
            otc = input_int();
            printf("Stock critico: ");
            critical = input_int();

            product_code[*product_count] = code;
            strncpy(product_name[*product_count], name, MAX_NAME_LEN - 1);
            product_price[*product_count] = price;
            product_stock[*product_count] = stock;
            product_otc[*product_count] = otc;
            product_stock_critical[*product_count] = critical;
            (*product_count)++;
            printf("Producto agregado.\n");
        }
    }
}

/* Listar productos */
void list_products(int *product_code, char product_name[][MAX_NAME_LEN], double *product_price,
                   int *product_stock, int *product_otc, int *product_stock_critical, int product_count) {
    int i;
    if (product_count == 0)
        printf("No hay productos cargados.\n");
    else {
        printf("\nCod | Nombre                         | Precio | Stock | OTC | Critico\n");
        for (i = 0; i < product_count; i++) {
            printf("%3d | %-30s | %7.2f | %5d |  %d  | %7d\n",
                   product_code[i], product_name[i], product_price[i],
                   product_stock[i], product_otc[i], product_stock_critical[i]);
        }
    }
}

/* (Las demás funciones continúan igual que en la versión anterior, adaptadas a punteros y con un solo return por función) */




// ====================== CONTINÚA EL PROGRAMA ======================



void make_sale(
    int *product_count, int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[], int product_otc[], 
    int product_stock_critical[], int sales_day[], int sales_qty[],
    double sales_amount[], int *sales_count, int recipe_dni[], 
    int *recipe_count
){
    int code, qty, day, i, found = -1, continuar = 1;

    printf("\n=== REGISTRAR VENTA ===\n");
    printf("Código del producto: ");
    scanf("%d", &code);

    for (i = 0; i < *product_count; i++) {
        if (product_code[i] == code) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Producto no encontrado.\n");
        continuar = 0;
    }

    if (continuar == 1) {
        printf("Cantidad: ");
        scanf("%d", &qty);
        printf("Día del mes (1-31): ");
        scanf("%d", &day);

        if (qty > product_stock[found]) {
            printf("Stock insuficiente.\n");
            continuar = 0;
        }

        if (continuar == 1) {
            product_stock[found] -= qty;
            sales_day[*sales_count] = day;
            sales_qty[*sales_count] = qty;
            sales_amount[*sales_count] = qty * product_price[found];
            (*sales_count)++;

            if (product_otc[found] == 0) { // requiere receta
                int dni;
                printf("Medicamento bajo receta. Ingrese DNI comprador: ");
                scanf("%d", &dni);
                recipe_dni[*recipe_count] = dni;
                (*recipe_count)++;
            }

            printf("Venta registrada exitosamente.\n");
        }
    }
    return;
}

// -------------------------------------------------------------------

void report_day(
    int sales_day[], int sales_qty[], double sales_amount[], int sales_count
){
    int day, i;
    double total_dia = 0;
    int cantidad_ventas = 0;

    printf("\nIngrese día del mes a consultar: ");
    scanf("%d", &day);

    for (i = 0; i < sales_count; i++) {
        if (sales_day[i] == day) {
            total_dia += sales_amount[i];
            cantidad_ventas++;
        }
    }

    if (cantidad_ventas == 0) {
        printf("No hubo ventas ese día.\n");
    } else {
        printf("Total vendido el día %d: $%.2f (%d ventas)\n",
               day, total_dia, cantidad_ventas);
    }
    return;
}

// -------------------------------------------------------------------

void report_month(
    int sales_day[], double sales_amount[], int sales_count
){
    double total_mes = 0;
    int ventas_por_dia[31] = {0};
    int i;

    for (i = 0; i < sales_count; i++) {
        total_mes += sales_amount[i];
        if (sales_day[i] >= 1 && sales_day[i] <= 31)
            ventas_por_dia[sales_day[i] - 1]++;
    }

    printf("\n=== INFORME MENSUAL ===\n");
    for (i = 0; i < 31; i++) {
        if (ventas_por_dia[i] > 0)
            printf("Día %d: %d ventas\n", i + 1, ventas_por_dia[i]);
    }
    printf("TOTAL DEL MES: $%.2f\n", total_mes);
    return;
}

// -------------------------------------------------------------------

void low_stock_report(
    int product_count,
    int product_code[],
    char product_name[][MAX_NAME_LEN],
    int product_stock[],
    int product_stock_critical[]
) {
    int i, hay_bajo = 0;
    printf("\n=== STOCK CRÍTICO ===\n");
    for (i = 0; i < product_count; i++) {
        if (product_stock[i] < product_stock_critical[i]) {
            printf("%d - %s (stock: %d, crítico: %d)\n",
                   product_code[i], product_name[i],
                   product_stock[i], product_stock_critical[i]);
            hay_bajo = 1;
        }
    }
    if (!hay_bajo)
        printf("No hay productos con stock crítico.\n");
    return;
}


// -------------------------------------------------------------------

void reset_month(
    int *sales_count, int *recipe_count
){
    *sales_count = 0;
    *recipe_count = 0;
    printf("\nSe reiniciaron los datos del mes.\n");
    return;
}

// ====================== FIN DEL PROGRAMA ======================
