#include <stdio.h>
#define TAMANIO 5

void mostrar_vector(int [], int);
int main(void){
    int vector[TAMANIO]={5,6,9,2,8};
    mostrar_vector(vector, TAMANIO);
}

void mostrar_vector(int vector[], int){
    int i;

    printf("El vector original es: \n[");
    for(i=0; i<TAMANIO; i++){
        printf("%d ", vector[i]);
        if(i<TAMANIO-1) printf(", ");
    }
    printf("]\n");
}
