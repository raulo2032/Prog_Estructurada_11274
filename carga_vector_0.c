#include <stdio.h>
#define TAMANIO 10

int main(void) {

    int vector[TAMANIO], i;
    for ( i = 0; i < TAMANIO; i++){

        printf("\n Ingrese el valor del elemento %d del vector : ", i);
        scanf("%d", &vector[i]);
        
    }

    printf("El vector ingresado es: ");
    for ( i = 0; i < TAMANIO; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    
    
    return 0;
}