#include <stdio_ext.h>
#include <stdlib.h>

#define MAXLONG 5
#define LINEA printf("-----------------\n")

void inicia_vector(int[], int);
void cargar_vector(int[], int);
void mostrar_vector(int[], int);

int menu(void);

int main( int argc, char * argv[]){
    int vec[MAXLONG];
    int opcion;
    while ((opcion = menu())){
        switch(opcion){
            case 1: { inicia_vector(vec, MAXLONG); break;}
            case 2: { cargar_vector(vec, MAXLONG); break;}
            case 3: { mostrar_vector(vec, MAXLONG); break;}
        }
    }

return 0;
}

void inicia_vector(int vec[], int longvec){
    int i;
    for (i = 0; i < longvec; i++)
    
    {   vec[i] = 0;
        /* code */
    };
    
}
void cargar_vector(int vec[], int longvec){
    int i;
    for (i = 0; i < longvec; i++)
    
    {   vec[i] = 0;
        /* code */
    };
}
void mostrar_vector(int vec[], int longvec){
    int i;
    for (i = 0; i < longvec; i++)
    
    {   vec[i] = 0;
        /* code */
    };
}

int menu(void){
    int opcion;
    printf("MENU DE OPCIONES\n");
    printf("1 INICIO\n");

    printf("2 CARGAR\n");
    printf("3 MOSTRAR\n");
    printf("0 SALIR\n");
    LINEA;
    printf("Ingrese una opcion \n");
    scabf("%d", &opcion);
    __fpurge(stdin);
    LINEA;
    return opcion;

}

/*
ver tema de agregar bien las funciones fantasma
fflush    en windows
purge en linux
*/
