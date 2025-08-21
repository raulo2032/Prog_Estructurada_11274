/* Crear una función con cuatro parámetros (v, N, menor, mayor) 
    que cargue un vector v de longitud N  
    con números enteros aleatorios comprendidos entre menor  y mayor.*/


#include <stdio.h>
#include <stdio_ext.h>

#define MAX_STR 64
#define LINEA printf("-----------------\n")

int *carga_vector(char[], int, int, int);

int main(void) {
    char nombre_vec[MAX_STR];
    int largo_vec, min, max, vector[largo_vec];

    printf("Ingrese el nombre del vector:\n");
    scanf("%s", nombre_vec);                        //scanf("%49s", nombre_vec); // deja lugar para '\0'
    __fpurge(stdin);                    // otra forma es, dado que fpurge va solo en linux
                                    //        while ((c = getchar()) != '\n' && c != EOF);

    printf("Ingrese la longitud del vector:\n");
    scanf("%d", &largo_vec);
    __fpurge(stdin);

    printf("Ingrese el limite inferior del vector:\n");
    scanf("%d", &min);
    __fpurge(stdin);

    printf("Ingrese el limite superior del vector:\n");
    scanf("%d", &max);
    __fpurge(stdin);

    vector[largo_vec] = carga_vector(nombre_vec, largo_vec, min, max);

    printf("El vector armado queda %d \n", vector);

        
    
    return 0;
}

int *carga_vector(char nombre_vector[], int largo, int min, int max){

    int i;

    for ( i=0; i < largo; i++){
        nombre_vector[i]=0;
        
    }
    
    
    return nombre_vector;
}