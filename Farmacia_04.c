#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_SALES 1000
#define MAX_NAME_LEN 60

// ==== PROTOTIPOS ====
void add_product(int *product_count, int product_code[], char product_name[][MAX_NAME_LEN],
                 double product_price[], int product_stock[], int product_otc[], int product_stock_critical[]);

void list_products(int product_count, int product_code[], char product_name[][MAX_NAME_LEN],
                   double product_price[], int product_stock[], int product_otc[]);

void make_sale(int *product_count, int product_code[], char product_name[][MAX_NAME_LEN],
               double product_price[], int product_stock[], int product_otc[], int product_stock_critical[],
               int sales_day[], int sales_qty[], double sales_amount[], int *sales_count,
               int recipe_dni[], int *recipe_count);

void report_day(int sales_day[], int sales_qty[], double sales_amount[], int sales_count);
void report_month(int sales_day[], double sales_amount[], int sales_count);

void low_stock_report(int product_count, int product_code[], char product_name[][MAX_NAME_LEN],
                      int product_stock[], int product_stock_critical[]);

void reset_month(int *sales_count, int *recipe_count);

// ==== FUNCION PRINCIPAL ====
int main(void) {
    int product_code[MAX_PRODUCTS];
    char product_name[MAX_PRODUCTS][MAX_NAME_LEN];
    double product_price[MAX_PRODUCTS];
    int product_stock[MAX_PRODUCTS];
    int product_otc[MAX_PRODUCTS];
    int product_stock_critical[MAX_PRODUCTS];
    int product_count = 0;

    int sales_day[MAX_SALES];
    int sales_qty[MAX_SALES];
    double sales_amount[MAX_SALES];
    int sales_count = 0;

    int recipe_dni[MAX_SALES];
    int recipe_count = 0;

    int opcion = 0, es_duenio = 0;

    printf("=== SISTEMA DE FARMACIA ===\n");
    printf("¿Es el dueño? (1=Sí, 0=No): ");
    scanf("%d", &es_duenio);

    while (1) {
        printf("\n--- MENÚ PRINCIPAL ---\n");
        printf("1. Agregar producto\n");
        printf("2. Listar productos\n");
        printf("3. Registrar venta\n");
        printf("4. Informe de ventas por día\n");
        printf("5. Informe mensual\n");
        printf("6. Ver stock crítico (solo dueño)\n");
        printf("7. Reiniciar datos del mes\n");
        printf("8. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                add_product(&product_count, product_code, product_name, product_price,
                            product_stock, product_otc, product_stock_critical);
                break;
            case 2:
                list_products(product_count, product_code, product_name,
                              product_price, product_stock, product_otc);
                break;
            case 3:
                make_sale(&product_count, product_code, product_name, product_price,
                          product_stock, product_otc, product_stock_critical,
                          sales_day, sales_qty, sales_amount, &sales_count,
                          recipe_dni, &recipe_count);
                break;
            case 4:
                report_day(sales_day, sales_qty, sales_amount, sales_count);
                break;
            case 5:
                report_month(sales_day, sales_amount, sales_count);
                break;
            case 6:
                if (es_duenio == 1)
                    low_stock_report(product_count, product_code, product_name,
                                     product_stock, product_stock_critical);
                else
                    printf("Acceso restringido.\n");
                break;
            case 7:
                reset_month(&sales_count, &recipe_count);
                break;
            case 8:
                printf("Saliendo del sistema...\n");
                return 0;
            default:
                printf("Opción inválida.\n");
                break;
        }
    }
    return 0;
}

// ==== FUNCIONES ====

void add_product(int *product_count, int product_code[], char product_name[][MAX_NAME_LEN],
                 double product_price[], int product_stock[], int product_otc[], int product_stock_critical[]) {
    int continuar = 1;
    if (*product_count >= MAX_PRODUCTS) {
        printf("No se pueden agregar más productos.\n");
        continuar = 0;
    }

    if (continuar == 1) {
        printf("Código del producto: ");
        scanf("%d", &product_code[*product_count]);
        printf("Nombre del producto: ");
        scanf(" %[^\n]", product_name[*product_count]);
        printf("Precio: ");
        scanf("%lf", &product_price[*product_count]);
        printf("Stock inicial: ");
        scanf("%d", &product_stock[*product_count]);
        printf("¿Es de venta libre? (1=Sí, 0=No): ");
        scanf("%d", &product_otc[*product_count]);
        printf("Stock crítico: ");
        scanf("%d", &product_stock_critical[*product_count]);

        (*product_count)++;
        printf("Producto agregado correctamente.\n");
    }
    return;
}

// -------------------------------------------------------------------

void list_products(int product_count, int product_code[], char product_name[][MAX_NAME_LEN],
                   double product_price[], int product_stock[], int product_otc[]) {
    int i;
    printf("\n=== LISTA DE PRODUCTOS ===\n");
    for (i = 0; i < product_count; i++) {
        printf("%d - %s | $%.2f | Stock: %d | %s\n",
               product_code[i], product_name[i], product_price[i],
               product_stock[i], product_otc[i] ? "Venta libre" : "Bajo receta");
    }
    if (product_count == 0)
        printf("No hay productos cargados.\n");
    return;
}

// -------------------------------------------------------------------

void make_sale(int *product_count, int product_code[], char product_name[][MAX_NAME_LEN],
               double product_price[], int product_stock[], int product_otc[],
               int product_stock_critical[], int sales_day[], int sales_qty[],
               double sales_amount[], int *sales_count, int recipe_dni[], int *recipe_count) {
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

            if (product_otc[found] == 0) {
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

void report_day(int sales_day[], int sales_qty[], double sales_amount[], int sales_count) {
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

void report_month(int sales_day[], double sales_amount[], int sales_count) {
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

void low_stock_report(int product_count, int product_code[], char product_name[][MAX_NAME_LEN],
                      int product_stock[], int product_stock_critical[]) {
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

void reset_month(int *sales_count, int *recipe_count) {
    *sales_count = 0;
    *recipe_count = 0;
    printf("\nSe reiniciaron los datos del mes.\n");
    return;
}
