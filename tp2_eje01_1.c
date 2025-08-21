/* Crear una función con cuatro parámetros (v, N, menor, mayor) 
    que cargue un vector v de longitud N  
    con números enteros aleatorios comprendidos entre menor  y mayor.*/


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>    // time()


#define MAX_STR 64
#define LINEA printf("-----------------\n")

void carga_vector(int [], int, int, int);

int main(void) {
    
    int largo_vec, min, max;
    
    srand(time(NULL));          // para generar una semilla distinta cada vez

    
    printf("Ingrese la longitud del vector:\n");
    scanf("%d", &largo_vec);
    __fpurge(stdin);

    int vector[largo_vec];

    printf("Ingrese el limite inferior del vector:\n");
    scanf("%d", &min);
    __fpurge(stdin);

    printf("Ingrese el limite superior del vector:\n");
    scanf("%d", &max);
    __fpurge(stdin);

    carga_vector(vector, largo_vec, min, max);

    LINEA;

    printf("El vector armado queda \n[");

    int i;

    for(i=0; i<largo_vec; i++){
        printf("%d", vector[i]);
        if(i<largo_vec-1) printf(", ");

    }

    printf("]\n");

    LINEA;

        
    
    return 0;
}

void carga_vector(int vector[], int largo, int min, int max){

    int i;

    for ( i=0; i < largo; i++){
        vector[i] = min + rand() % (max - min + 1);
        
    }
    
    
    
}