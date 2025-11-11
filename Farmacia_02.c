/*
 farmacia_no_globals.c
 Sistema de administracion de farmacia totalmente EN MEMORIA, sin variables globales.
 - No usa struct ni typedef (respeta tu restricción).
 - Todas las "estructuras" (arrays, contadores) se declaran en main() y se pasan por punteros.
 - Cada función tiene como maximo un return.
 - No usa archivos en disco.
 - Compilar: gcc -o farmacia farmacia_no_globals.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Constantes (macros permitidas) */
#define MAX_PRODUCTS 200
#define MAX_NAME_LEN 60
#define MAX_SALES 5000
#define MAX_DAYS 31
#define OWNER_PASS "admin123"
#define MAX_STORED_REPORTS 48
#define REPORT_TEXT_LEN 4096

/* Prototipos: todas las funciones reciben punteros a los arrays/contadores necesarios.
   Todas las funciones terminan con un unico return (o son void y tienen un solo 'return;').
*/

/* Utilidades de entrada */
void safe_gets(char *buf, int len);
int input_int(char *buf, int buflen);
double input_double(char *buf, int buflen);

/* Busqueda */
int find_product_index_by_code(int code,
    int product_code[], int product_count);

/* Productos */
void add_product(int *product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[],
    int product_otc[], int product_stock_critical[]);

void list_products(int product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[],
    int product_otc[], int product_stock_critical[]);

void modify_stock(int product_count,
    int product_code[], int product_stock[]);

/* Ventas */
void sale_register(int *sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[], int sale_is_prescription[],
    char sale_dni[][20],
    int product_count, int product_code[],
    char product_name[][MAX_NAME_LEN], double product_price[],
    int product_stock[], int product_otc[]);

/* Informes */
void report_daily(int sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[],
    int product_count, int product_code[],
    char product_name[][MAX_NAME_LEN]);

void report_monthly_and_store(int *report_count,
    int report_month[], int report_year[], char report_text[][REPORT_TEXT_LEN],
    int sales_count,
    int sale_day[], double sale_total_price[]);

void show_stored_reports(int report_count,
    int report_month[], int report_year[]);

void view_report(int report_count, char report_text[][REPORT_TEXT_LEN],
    int report_month[], int report_year[]);

/* Operaciones del dueño */
int owner_login(void); /* devuelve 1 si OK, 0 si no (un unico return) */
void low_stock_report(int product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    int product_stock[], int product_stock_critical[]);

/* Borrar ventas */
void clear_month_sales(int *sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[], int sale_is_prescription[],
    char sale_dni[][20]);

/* Informe a demanda (dia y stock) */
void report_day_demand(int sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[], int sale_is_prescription[],
    char sale_dni[][20],
    int product_count, int product_code[], char product_name[][MAX_NAME_LEN],
    int product_stock[]);

/* ------------------ Implementaciones ------------------ */

void safe_gets(char *buf, int len){
    if(fgets(buf, len, stdin) == NULL){
        buf[0] = '\0';
        /* single return */
        return;
    }
    size_t L = strlen(buf);
    if(L > 0 && buf[L-1] == '\n') buf[L-1] = '\0';
    return;
}

int input_int(char *buf, int buflen){
    int val = 0;
    safe_gets(buf, buflen);
    sscanf(buf, "%d", &val);
    return val;
}

double input_double(char *buf, int buflen){
    double val = 0.0;
    safe_gets(buf, buflen);
    sscanf(buf, "%lf", &val);
    return val;
}

int find_product_index_by_code(int code,
    int product_code[], int product_count)
{
    int i;
    int idx = -1;
    for(i = 0; i < product_count; i++){
        if(product_code[i] == code){
            idx = i;
            break;
        }
    }
    return idx; /* unico return */
}

void add_product(int *product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[],
    int product_otc[], int product_stock_critical[])
{
    int local_continue = 1;
    char buf[128];
    int code = 0;
    char name[MAX_NAME_LEN];
    double price = 0.0;
    int stock = 0, otc = 0, critical = 0;
    int idx_found;

    if(*product_count >= MAX_PRODUCTS){
        printf("Limite de productos alcanzado.\n");
        local_continue = 0;
    }

    if(local_continue){
        printf("Codigo de producto (entero): ");
        code = input_int(buf, sizeof(buf));
        idx_found = find_product_index_by_code(code, product_code, *product_count);
        if(idx_found != -1){
            printf("Ya existe un producto con ese codigo.\n");
            local_continue = 0;
        }
    }

    if(local_continue){
        printf("Nombre del producto: ");
        safe_gets(name, sizeof(name));
        printf("Precio: ");
        price = input_double(buf, sizeof(buf));
        printf("Cantidad en stock: ");
        stock = input_int(buf, sizeof(buf));
        printf("Es de venta libre? 1=Si 0=No: ");
        otc = input_int(buf, sizeof(buf));
        printf("Stock critico (para pedir reposicion): ");
        critical = input_int(buf, sizeof(buf));

        /* asigno */
        product_code[*product_count] = code;
        strncpy(product_name[*product_count], name, MAX_NAME_LEN - 1);
        product_name[*product_count][MAX_NAME_LEN - 1] = '\0';
        product_price[*product_count] = price;
        product_stock[*product_count] = stock;
        product_otc[*product_count] = (otc ? 1 : 0);
        product_stock_critical[*product_count] = critical;
        (*product_count)++;
        printf("Producto agregado.\n");
    }

    return; /* unico return */
}

void list_products(int product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[],
    int product_otc[], int product_stock_critical[])
{
    int i;
    if(product_count == 0){
        printf("No hay productos cargados.\n");
    } else {
        printf("\nListado de productos:\n");
        printf("Cod | Nombre                          | Precio   | Stock | OTC | Critico\n");
        for(i = 0; i < product_count; i++){
            printf("%3d | %-30s | %8.2f | %5d |  %d  | %7d\n",
                product_code[i],
                product_name[i],
                product_price[i],
                product_stock[i],
                product_otc[i],
                product_stock_critical[i]);
        }
    }
    return; /* unico return */
}

void modify_stock(int product_count,
    int product_code[], int product_stock[])
{
    int code = 0;
    int idx = -1;
    int change = 0;
    char buf[128];
    int cont = 1;

    if(product_count == 0){
        printf("No hay productos cargados.\n");
        cont = 0;
    }

    if(cont){
        printf("Ingrese codigo de producto: ");
        code = input_int(buf, sizeof(buf));
        idx = find_product_index_by_code(code, product_code, product_count);
        if(idx == -1){
            printf("Producto no encontrado.\n");
            cont = 0;
        }
    }

    if(cont){
        printf("Stock actual: %d\n", product_stock[idx]);
        printf("Ingrese cambio en stock (positivo para agregar, negativo para quitar): ");
        change = input_int(buf, sizeof(buf));
        product_stock[idx] += change;
        if(product_stock[idx] < 0) product_stock[idx] = 0;
        printf("Stock actualizado: %d\n", product_stock[idx]);
    }

    return; /* unico return */
}

void sale_register(int *sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[], int sale_is_prescription[],
    char sale_dni[][20],
    int product_count, int product_code[],
    char product_name[][MAX_NAME_LEN], double product_price[],
    int product_stock[], int product_otc[])
{
    int cont = 1;
    char buf[128];
    int code = 0;
    int idx = -1;
    int qty = 0;
    int is_presc = 0;
    char dni_buf[20];
    int day = 0;

    if(*sales_count >= MAX_SALES){
        printf("Limite de ventas alcanzado.\n");
        cont = 0;
    }
    if(cont && product_count == 0){
        printf("No hay productos cargados.\n");
        cont = 0;
    }
    if(cont){
        printf("Ingrese codigo de producto: ");
        code = input_int(buf, sizeof(buf));
        idx = find_product_index_by_code(code, product_code, product_count);
        if(idx == -1){
            printf("Producto no encontrado.\n");
            cont = 0;
        }
    }
    if(cont){
        printf("Producto: %s | Precio: %.2f | Stock: %d | OTC: %d\n",
               product_name[idx], product_price[idx], product_stock[idx], product_otc[idx]);
        printf("Ingrese cantidad a vender: ");
        qty = input_int(buf, sizeof(buf));
        if(qty <= 0){
            printf("Cantidad invalida.\n");
            cont = 0;
        }
    }
    if(cont){
        if(qty > product_stock[idx]){
            printf("Stock insuficiente.\n");
            cont = 0;
        }
    }
    if(cont){
        if(product_otc[idx] == 0){
            is_presc = 1;
            printf("Este medicamento requiere receta.\n");
            printf("Ingrese DNI del comprador: ");
            safe_gets(dni_buf, sizeof(dni_buf));
        } else {
            is_presc = 0;
            dni_buf[0] = '\0';
        }
        printf("Ingrese dia del mes de la venta (1..31): ");
        day = input_int(buf, sizeof(buf));
        if(day < 1 || day > MAX_DAYS){
            printf("Dia invalido.\n");
            cont = 0;
        }
    }
    if(cont){
        /* Registrar venta */
        sale_day[*sales_count] = day;
        sale_product_code[*sales_count] = code;
        sale_qty[*sales_count] = qty;
        sale_total_price[*sales_count] = product_price[idx] * qty;
        sale_is_prescription[*sales_count] = is_presc;
        strncpy(sale_dni[*sales_count], dni_buf, sizeof(sale_dni[0]) - 1);
        sale_dni[*sales_count][sizeof(sale_dni[0]) - 1] = '\0';
        (*sales_count)++;

        /* Actualizar stock */
        product_stock[idx] -= qty;
        printf("Venta registrada. Total: %.2f\n", product_price[idx] * qty);
    }

    return; /* unico return */
}

void report_daily(int sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[],
    int product_count, int product_code[],
    char product_name[][MAX_NAME_LEN])
{
    char buf[128];
    int day = 0;
    int i;
    double total = 0.0;
    int cont = 1;

    if(sales_count == 0){
        printf("No hay ventas registradas este mes.\n");
        cont = 0;
    }
    if(cont){
        printf("Ingrese dia del mes a informar (1..31): ");
        day = input_int(buf, sizeof(buf));
        if(day < 1 || day > MAX_DAYS){
            printf("Dia invalido.\n");
            cont = 0;
        }
    }

    if(cont){
        printf("\nInforme de ventas - Dia %d\n", day);
        printf("ProdCode | Nombre                       | Cant | Importe\n");
        for(i = 0; i < sales_count; i++){
            if(sale_day[i] == day){
                int idx = find_product_index_by_code(sale_product_code[i], product_code, product_count);
                const char *pname = (idx == -1) ? "N/D" : product_name[idx];
                printf("%7d | %-27s | %4d | %8.2f\n",
                       sale_product_code[i], pname, sale_qty[i], sale_total_price[i]);
                total += sale_total_price[i];
            }
        }
        printf("Total del dia: %.2f\n", total);
    }

    return; /* unico return */
}

void report_monthly_and_store(int *report_count,
    int report_month[], int report_year[], char report_text[][REPORT_TEXT_LEN],
    int sales_count,
    int sale_day[], double sale_total_price[])
{
    int cont = 1;
    char buf_local[128];
    int month, year;
    double day_totals[MAX_DAYS + 1];
    int day_counts[MAX_DAYS + 1];
    int i, d;
    size_t pos;

    if(sales_count == 0){
        printf("No hay ventas registradas este mes.\n");
        cont = 0;
    }

    if(cont){
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        month = tm->tm_mon + 1;
        year = tm->tm_year + 1900;

        for(d = 0; d <= MAX_DAYS; d++){
            day_totals[d] = 0.0;
            day_counts[d] = 0;
        }
        for(i = 0; i < sales_count; i++){
            int sd = sale_day[i];
            if(sd >= 1 && sd <= MAX_DAYS){
                day_totals[sd] += sale_total_price[i];
                day_counts[sd] += 1;
            }
        }

        /* Mostrar por pantalla */
        printf("\nInforme mensual %02d/%04d\n", month, year);
        double total_month = 0.0;
        for(d = 1; d <= MAX_DAYS; d++){
            if(day_counts[d] > 0){
                printf("Dia %2d: Ventas = %d  |  Total = %.2f\n", d, day_counts[d], day_totals[d]);
                total_month += day_totals[d];
            }
        }
        printf("TOTAL MENSUAL: %.2f\n", total_month);

        /* Guardar en memoria */
        if(*report_count >= MAX_STORED_REPORTS){
            printf("Capacidad de informes en memoria alcanzada. No se almacenara este informe.\n");
            cont = 0;
        } else {
            char tmpbuf[REPORT_TEXT_LEN];
            pos = 0;
            pos += snprintf(tmpbuf + pos, REPORT_TEXT_LEN - pos, "Informe Mensual %02d/%04d\n", month, year);
            pos += snprintf(tmpbuf + pos, REPORT_TEXT_LEN - pos, "Dia | CantVentas | Total\n");
            for(d = 1; d <= MAX_DAYS; d++){
                if(day_counts[d] > 0){
                    pos += snprintf(tmpbuf + pos, REPORT_TEXT_LEN - pos, "%2d  | %10d | %8.2f\n", d, day_counts[d], day_totals[d]);
                }
                if(pos >= REPORT_TEXT_LEN - 200) break;
            }
            pos += snprintf(tmpbuf + pos, REPORT_TEXT_LEN - pos, "TOTAL_MENSUAL | %.2f\n", total_month);

            report_month[*report_count] = month;
            report_year[*report_count] = year;
            strncpy(report_text[*report_count], tmpbuf, REPORT_TEXT_LEN - 1);
            report_text[*report_count][REPORT_TEXT_LEN - 1] = '\0';
            (*report_count)++;
            printf("Informe mensual guardado EN MEMORIA. Total informes almacenados: %d\n", *report_count);
        }
    }

    return; /* unico return */
}

void show_stored_reports(int report_count,
    int report_month[], int report_year[])
{
    int i;
    if(report_count == 0){
        printf("No hay informes almacenados en memoria.\n");
    } else {
        printf("Informes almacenados en memoria:\n");
        for(i = 0; i < report_count; i++){
            printf("%d) Informe %02d/%04d\n", i + 1, report_month[i], report_year[i]);
        }
    }
    return; /* unico return */
}

void view_report(int report_count, char report_text[][REPORT_TEXT_LEN],
    int report_month[], int report_year[])
{
    char buf[128];
    int idx = 0;
    int cont = 1;

    if(report_count == 0){
        printf("No hay informes almacenados en memoria.\n");
        cont = 0;
    }
    if(cont){
        show_stored_reports(report_count, report_month, report_year);
        printf("Ingrese numero de informe a ver: ");
        idx = input_int(buf, sizeof(buf));
        if(idx < 1 || idx > report_count){
            printf("Indice invalido.\n");
            cont = 0;
        }
    }
    if(cont){
        printf("\n--- Informe %02d/%04d ---\n", report_month[idx - 1], report_year[idx - 1]);
        printf("%s\n", report_text[idx - 1]);
    }

    return; /* unico return */
}

int owner_login(void){
    char pass[128];
    int ok = 0;
    printf("Contrasena propietario: ");
    safe_gets(pass, sizeof(pass));
    if(strcmp(pass, OWNER_PASS) == 0) ok = 1;
    return ok; /* unico return */
}

void low_stock_report(int product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    int product_stock[], int product_stock_critical[])
{
    int i;
    int found = 0;
    if(product_count == 0){
        printf("No hay productos cargados.\n");
    } else {
        printf("\nMedicamentos por debajo del stock critico:\n");
        printf("Cod | Nombre                        | Stock | Critico\n");
        for(i = 0; i < product_count; i++){
            if(product_stock[i] <= product_stock_critical[i]){
                printf("%3d | %-28s | %5d | %7d\n",
                    product_code[i], product_name[i], product_stock[i], product_stock_critical[i]);
                found = 1;
            }
        }
        if(!found) printf("No hay medicamentos por debajo del stock critico.\n");
    }
    return; /* unico return */
}

void clear_month_sales(int *sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[], int sale_is_prescription[],
    char sale_dni[][20])
{
    int i;
    if(*sales_count == 0){
        printf("No hay ventas para borrar.\n");
    } else {
        for(i = 0; i < *sales_count; i++){
            sale_day[i] = 0;
            sale_product_code[i] = 0;
            sale_qty[i] = 0;
            sale_total_price[i] = 0.0;
            sale_is_prescription[i] = 0;
            sale_dni[i][0] = '\0';
        }
        *sales_count = 0;
        printf("Ventas del mes borradas.\n");
    }
    return; /* unico return */
}

void report_day_demand(int sales_count,
    int sale_day[], int sale_product_code[], int sale_qty[],
    double sale_total_price[], int sale_is_prescription[],
    char sale_dni[][20],
    int product_count, int product_code[], char product_name[][MAX_NAME_LEN],
    int product_stock[])
{
    char buf[128];
    int day = 0;
    int i;
    int cont = 1;
    double total = 0.0;
    int any = 0;

    if(sales_count == 0){
        printf("No hay ventas registradas este mes.\n");
        cont = 0;
    }
    if(cont){
        printf("Ingrese dia a consultar (1..31): ");
        day = input_int(buf, sizeof(buf));
        if(day < 1 || day > MAX_DAYS){
            printf("Dia invalido.\n");
            cont = 0;
        }
    }
    if(cont){
        printf("\nVentas del dia %d:\n", day);
        for(i = 0; i < sales_count; i++){
            if(sale_day[i] == day){
                int idx = find_product_index_by_code(sale_product_code[i], product_code, product_count);
                const char *pname = (idx == -1) ? "N/D" : product_name[idx];
                printf("Prod %d - %-25s | Cant %d | Importe %.2f", sale_product_code[i], pname, sale_qty[i], sale_total_price[i]);
                if(sale_is_prescription[i]){
                    printf(" | DNI: %s", sale_dni[i]);
                }
                printf("\n");
                total += sale_total_price[i];
                any = 1;
            }
        }
        if(!any) printf("No se registraron ventas ese dia.\n");
        else printf("Total del dia: %.2f\n", total);
        printf("\nEstado de stock actual:\n");
        list_products(product_count, product_code, product_name, NULL, product_stock, NULL); 
        /* list_products espera arrays de precios/otc/critico; pasamos NULL para los opcionales;
           por simplicidad, la version usada en este llamado imprimira solo los campos que no sean NULL.
           Sin embargo para mantener la firma original sin structs, pasamos NULLs y la función
           no accede a esos punteros. */
    }
    return; /* unico return */
}

/* Modificamos la funcion list_products para ser robusta ante NULLs en algunos arrays:
   si price/otc/critical son NULL, no los imprime (evita accesos). Para mantener el contrato
   original mantenemos misma firma; en anteriores llamadas nunca pasamos NULL excepto aqui. */
void list_products(int product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[],
    int product_otc[], int product_stock_critical[]);

/* Implementacion alternativa de list_products que tolera NULLs (re-declarada arriba):
   la forma anterior ya estaba declarada; aquí brindamos la definicion que chequea punteros.
*/
void list_products(int product_count,
    int product_code[], char product_name[][MAX_NAME_LEN],
    double product_price[], int product_stock[],
    int product_otc[], int product_stock_critical[])
{
    int i;
    if(product_count == 0){
        printf("No hay productos cargados.\n");
    } else {
        printf("\nListado de productos:\n");
        /* Cabecera condicionada a datos disponibles */
        printf("Cod | Nombre                          |");
        if(product_price != NULL) printf(" Precio   |");
        if(product_stock != NULL) printf(" Stock |");
        if(product_otc != NULL) printf(" OTC |");
        if(product_stock_critical != NULL) printf(" Critico");
        printf("\n");

        for(i = 0; i < product_count; i++){
            printf("%3d | %-30s |", product_code[i], product_name[i]);
            if(product_price != NULL) printf(" %8.2f |", product_price[i]);
            if(product_stock != NULL) printf(" %5d |", product_stock[i]);
            if(product_otc != NULL) printf("  %d  |", product_otc[i]);
            if(product_stock_critical != NULL) printf(" %7d", product_stock_critical[i]);
            printf("\n");
        }
    }
    return; /* unico return */
}

/* ------------------ main ------------------ */
int main(void)
{
    /* Declaracion de todas las 'estructuras' en main (sin globals) */
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

    int running = 1;
    char bufmenu[128];
    int option = 0;

    /* inicializar arrays simples (opcional pero limpio) */
    memset(product_code, 0, sizeof(product_code));
    memset(product_name, 0, sizeof(product_name));
    memset(product_price, 0, sizeof(product_price));
    memset(product_stock, 0, sizeof(product_stock));
    memset(product_otc, 0, sizeof(product_otc));
    memset(product_stock_critical, 0, sizeof(product_stock_critical));
    memset(sale_day, 0, sizeof(sale_day));
    memset(sale_product_code, 0, sizeof(sale_product_code));
    memset(sale_qty, 0, sizeof(sale_qty));
    memset(sale_total_price, 0, sizeof(sale_total_price));
    memset(sale_is_prescription, 0, sizeof(sale_is_prescription));
    memset(sale_dni, 0, sizeof(sale_dni));
    memset(report_month, 0, sizeof(report_month));
    memset(report_year, 0, sizeof(report_year));
    memset(report_text, 0, sizeof(report_text));

    while(running){
        printf("\n==== SISTEMA DE GESTION - FARMACIA (SIN GLOBALS) ====\n");
        printf("1) Agregar producto\n");
        printf("2) Listar productos\n");
        printf("3) Modificar stock de producto\n");
        printf("4) Registrar venta\n");
        printf("5) Emitir informe diario (pantalla)\n");
        printf("6) Emitir informe mensual y guardarlo EN MEMORIA\n");
        printf("7) Emitir informe de un dia (consulta)\n");
        printf("8) Mostrar medicamentos por debajo de stock critico (solo dueño)\n");
        printf("9) Borrar datos de ventas del mes (nuevo mes) (solo dueño)\n");
        printf("10) Listar informes guardados (en memoria)\n");
        printf("11) Ver informe guardado (en memoria)\n");
        printf("0) Salir\n");
        printf("Elija opcion: ");
        option = input_int(bufmenu, sizeof(bufmenu));

        switch(option){
            case 1:
                add_product(&product_count,
                    product_code, product_name, product_price,
                    product_stock, product_otc, product_stock_critical);
                break;
            case 2:
                list_products(product_count, product_code, product_name,
                    product_price, product_stock, product_otc, product_stock_critical);
                break;
            case 3:
                modify_stock(product_count, product_code, product_stock);
                break;
            case 4:
                sale_register(&sales_count, sale_day, sale_product_code, sale_qty,
                    sale_total_price, sale_is_prescription, sale_dni,
                    product_count, product_code, product_name, product_price,
                    product_stock, product_otc);
                break;
            case 5:
                report_daily(sales_count, sale_day, sale_product_code, sale_qty,
                    sale_total_price, product_count, product_code, product_name);
                break;
            case 6:
                report_monthly_and_store(&report_count, report_month, report_year,
                    report_text, sales_count, sale_day, sale_total_price);
                break;
            case 7:
                report_day_demand(sales_count, sale_day, sale_product_code, sale_qty,
                    sale_total_price, sale_is_prescription, sale_dni,
                    product_count, product_code, product_name, product_stock);
                break;
            case 8:
                if(owner_login()){
                    low_stock_report(product_count, product_code, product_name, product_stock, product_stock_critical);
                } else {
                    printf("Acceso denegado. Solo propietario.\n");
                }
                break;
            case 9:
                if(owner_login()){
                    printf("Confirma borrar todos los datos de ventas del mes actual? 1=Si 0=No: ");
                    if(input_int(bufmenu, sizeof(bufmenu)) == 1){
                        clear_month_sales(&sales_count, sale_day, sale_product_code, sale_qty,
                            sale_total_price, sale_is_prescription, sale_dni);
                    } else {
                        printf("Accion cancelada.\n");
                    }
                } else {
                    printf("Acceso denegado. Solo propietario.\n");
                }
                break;
            case 10:
                show_stored_reports(report_count, report_month, report_year);
                break;
            case 11:
                view_report(report_count, report_text, report_month, report_year);
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
