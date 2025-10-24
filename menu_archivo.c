
#include <stdio_ext.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

// Variable global para limpiar el buffer de teclado

// Ya que fflush(stdin) no me funciona

char nada[200];

void pausa(void)
{

    getc(stdin);

    printf(" \n\n\n \t\t\t\t Presione enter para continuar");

    fgets(nada, 100, stdin);
}

// Saca el salto de linea del ingreso con fgets

void sacafl(char *nombre)
{

    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {

        nombre[strlen(nombre) - 1] = '\0';
    }
}

// Crea el archivo vacio

// void crear(char nom_arch[],char modo[]){

void crear(char nom_arch[])
{

    char modo[] = "w";

    FILE *arch;

    arch = fopen(nom_arch, modo);

    fclose(arch);
}

// Lee el archivo de texto caracter a carcter

void xcaracter(char nom[], char modo[])
{

    FILE *archi;

    archi = fopen(nom, modo);

    if (archi == NULL)
    {

        perror("Error de apertura");
    }

    char car;

    while (feof(archi) == 0)
    {

        car = fgetc(archi);

        printf("%c ", car);
    }

    fclose(archi);

    printf(" \n Se termino de leer el archivo");
}

// Cargar automatico

void cargarau(char nom_arch[], char modo[])
{

    FILE *arch;

    arch = fopen(nom_arch, modo);

    int i, dia;

    float tmax, tmin;

    for (i = 1; i < 30; i++)
    {

        dia = i;

        tmax = -10 + rand() % (41 + 10) + (rand() % 100) / 100.0;

        tmin = tmax - rand() % 13 + (rand() % 100) / 100.0;

        fprintf(arch, "%i %.2f %.2f\n", dia, tmax, tmin);
    }

    fclose(arch);
}

// Cargar a mano

void cargaram(char nom_arch[], char modo[])
{

    FILE *arch = fopen(nom_arch, modo);

    int i, dia;

    double tmax, tmin;

    // 2 - Crear Archivo para variables

    for (i = 0; i < 3; i++)
    {

        fflush(stdin);

        printf("Ingrese el día: ");

        scanf("%i", &dia);

        printf("Ingrese Temp Max: ");

        scanf("%lf", &tmax);

        printf("Ingrese Temp MIN: ");

        scanf("%lf", &tmin);

        fprintf(arch, "%i %.2lf %.2lf\n", dia, tmax, tmin);

        // fprintf(arch,"%i%lf%lf\t", dia,tmax,tmin);
    }

    fclose(arch);
}
// Leer por variables

void leer(char nom[], char modo[])
{

    FILE *archi = fopen(nom, modo);

    int dia;

    double tmax, tmin;

    // fscanf(archi,"%i%lf%lf", &dia,&tmax,&tmin);

    while (feof(archi) == 0)
    {

        fscanf(archi, "%i%lf%lf", &dia, &tmax, &tmin);

        printf("%i %f %f %i\n", dia, tmax, tmin, feof(archi));
    }

    fclose(archi);

    printf(" \n Se termino de leer el archivo");
}

// Principal

int main()
{

    char arch[] = "prueba1.txt"; // para leerlo x caracter

    char arch2[] = "prueba2.txt"; // variables

    /* char arch3[]="prueba2024.txt"; // variables

    char arch4[]="prueba4.txt"; // variables int opcion=0;

    crear(arch3);

    cargaram(arch3,"a");

    pausa();

    cargaram(arch3,"a");

    pausa();

    cargarau(arch4,"a");

    pausa();

    */

    int opcion = 0;

    do
    {

        system("clear");

        printf("\t\t\t\t Menú \n\n");

        printf("\t\t1 - Leer archivo de texto caracter x caracter \n");

        printf("\t\t2 - Crear Archivo para variables\n");

        printf("\t\t3 - Cargar automático con variables\n");

        printf("\t\t4 - Cargar a mano con variables\n");

        printf("\t\t5 - Leer Archivo con variables.\n");

        printf("\n\t\t\t Ingrese su opcion (0-Salir): ");

        scanf("%i", &opcion);

        switch (opcion)
        {

        case 0:

            system("clear");

            printf("\n\n\n\t\t\t Hasta la próxima");

            pausa();

            break;

        case 1:

            system("clear");

            xcaracter(arch, "r");

            pausa();

            break;

        case 2:

            system("clear");

            // crear(arch2,"w");

            crear(arch2);

            pausa();

            break;

        case 3:

            system("clear");

            cargarau(arch2, "w");

            pausa();

            break;

        case 4:

            system("clear");

            cargaram(arch2, "a");

            pausa();

            break;

        case 5:

            system("clear");

            leer(arch2, "r");

            pausa();

            break;
        }

    } while (opcion != 0);

    return 0;
}
