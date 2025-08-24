#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAMANIO 10

int main(void) {

    int vector[TAMANIO], i;
    srand(time(NULL));

    printf("\n El valor de los elementos del vector se carga aleatoriamente ");
    for ( i = 0; i < TAMANIO; i++){
        vector[i] = rand()%100; /* aleatorio entre 0 y 99*/  //        vector[i]= rand() % 10;  carga con elementos entre 0 y 10
        printf("enteros[%d] = %d \n", i, vector[i]);
        
    }

    printf("El vector ingresado es: ");
    for ( i = 0; i < TAMANIO; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    
    
    return 0;
}
