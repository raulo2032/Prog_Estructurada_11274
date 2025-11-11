#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PRODUCTS 200
#define MAX_NAME_LEN 60
#define MAX_SALES 5000
#define MAX_DAYS 31
#define OWNER_PASS "admin123"
#define MAX_STORED_REPORTS 48
#define REPORT_TEXT_LEN 4096

/******************************************************/
/* Función segura para leer un entero validado */
int leer_entero(const char *mensaje, int minimo, int maximo) {
    int valor;
    char c;
    int valido = 0;
    while (!valido) {
        printf("%s", mensaje);
        if (scanf("%d", &valor) != 1) {
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Entrada inválida. Intente nuevamente.\n");
        } else if ((minimo != 0 || maximo != 0) && (valor < minimo || valor > maximo)) {
            printf("Valor fuera de rango (%d - %d). Intente nuevamente.\n", minimo, maximo);
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            valido = 1;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
    return valor;
}

/******************************************************/
/* Lectura segura de texto */
void leer_cadena(const char *mensaje, char *dest, int len) {
    printf("%s", mensaje);
    if (fgets(dest, len, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    size_t L = strlen(dest);
    if (L > 0 && dest[L - 1] == '\n') dest[L - 1] = '\0';
}

/******************************************************/
/* Buscar índice de producto por código */
int find_product_index_by_code(int code, int *product_code, int product_count) {
    int i;
    int index = -1;  // valor por defecto si no se encuentra el código

    for (i = 0; i < product_count; i++) {
        if (product_code[i] == code) {
            index = i;
            break;  // salimos del bucle, pero sin hacer return directo
        }
    }

    return index;
}
/******************************************************/
/* Agregar producto nuevo */
void add_product(
    int *product_code, char product_name[][MAX_NAME_LEN],
    double *product_price, int *product_stock,
    int *product_otc, int *product_stock_critical, int *product_count
) {
    int continuar = 1;  // bandera para controlar si se sigue o no

    if (*product_count >= MAX_PRODUCTS) {
        printf("Límite de productos alcanzado.\n");
        continuar = 0;
    }

    int code = 0;
    if (continuar) {
        code = leer_entero("Código de producto (entero): ", 1, 999999);
        if (find_product_index_by_code(code, product_code, *product_count) != -1) {
            printf("Ya existe un producto con ese código.\n");
            continuar = 0;
        }
    }

    if (continuar) {
        leer_cadena("Nombre del producto: ", product_name[*product_count], MAX_NAME_LEN);

        printf("Precio: ");
        double price;
        while (scanf("%lf", &price) != 1 || price <= 0) {
            while (getchar() != '\n');
            printf("Precio inválido. Ingrese nuevamente: ");
        }
        while (getchar() != '\n');

        int stock = leer_entero("Cantidad en stock: ", 0, 99999);
        int otc = leer_entero("Es de venta libre? (1=Sí, 0=No): ", 0, 1);
        int critical = leer_entero("Stock crítico (reposición): ", 0, 99999);

        product_code[*product_count] = code;
        product_price[*product_count] = price;
        product_stock[*product_count] = stock;
        product_otc[*product_count] = otc;
        product_stock_critical[*product_count] = critical;
        (*product_count)++;

        printf("Producto agregado con éxito.\n");
    }

    return;
}


/******************************************************/
/* Listar productos */
void list_products(
    int product_count, int *product_code, char product_name[][MAX_NAME_LEN],
    double *product_price, int *product_stock, int *product_otc, int *product_stock_critical
) {
    if (product_count == 0) {
        printf("No hay productos cargados.\n");
        return;
    }
    printf("\nListado de productos:\n");
    printf("Cod | Nombre                          | Precio   | Stock | OTC | Crítico\n");
    for (int i = 0; i < product_count; i++) {
        printf("%3d | %-30s | %8.2f | %5d |  %d  | %7d\n",
               product_code[i], product_name[i], product_price[i],
               product_stock[i], product_otc[i], product_stock_critical[i]);
    }
}

/******************************************************/
/* Modificar stock */
void modify_stock(
    int *product_code, int *product_stock, int product_count
) {
    int code = leer_entero("Ingrese código de producto: ", 1, 999999);
    int idx = find_product_index_by_code(code, product_code, product_count);
    if (idx == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Stock actual: %d\n", product_stock[idx]);
    int change = leer_entero("Ingrese cambio en stock (+/-): ", -99999, 99999);
    product_stock[idx] += change;
    if (product_stock[idx] < 0) product_stock[idx] = 0;
    printf("Stock actualizado: %d\n", product_stock[idx]);
}

/******************************************************/
/* Reporte de stock crítico */
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
        if (product_stock[i] <= product_stock_critical[i]) {
            printf("%d - %s (stock: %d, crítico: %d)\n",
                   product_code[i], product_name[i],
                   product_stock[i], product_stock_critical[i]);
            hay_bajo = 1;
        }
    }
    if (!hay_bajo)
        printf("No hay productos con stock crítico.\n");
}

/******************************************************/
/* Main */
int main() {
    int product_code[MAX_PRODUCTS];
    char product_name[MAX_PRODUCTS][MAX_NAME_LEN];
    double product_price[MAX_PRODUCTS];
    int product_stock[MAX_PRODUCTS];
    int product_otc[MAX_PRODUCTS];
    int product_stock_critical[MAX_PRODUCTS];
    int product_count = 0;

    int opcion = -1;
    int es_duenio = leer_entero("¿Es el dueño? (1=Sí, 0=No): ", 0, 1);

    while (opcion != 0) {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1) Agregar producto\n");
        printf("2) Listar productos\n");
        printf("3) Modificar stock\n");
        printf("4) Mostrar stock crítico (solo dueño)\n");
        printf("0) Salir\n");
        opcion = leer_entero("Opción: ", 0, 4);

        switch (opcion) {
            case 1:
                add_product(product_code, product_name, product_price,
                            product_stock, product_otc, product_stock_critical, &product_count);
                break;
            case 2:
                list_products(product_count, product_code, product_name,
                              product_price, product_stock, product_otc, product_stock_critical);
                break;
            case 3:
                modify_stock(product_code, product_stock, product_count);
                break;
            case 4:
                if (es_duenio)
                    low_stock_report(product_count, product_code, product_name,
                                     product_stock, product_stock_critical);
                else
                    printf("Acceso denegado. Solo para dueño.\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    }

    return 0;
}
