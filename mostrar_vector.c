#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 5

void mostrar_vector(int [], int);
void cargar_vector(int []);

int main(void){

    int vector[TAMANIO];
    cargar_vector(vector);
    mostrar_vector(vector, TAMANIO);
}


void cargar_vector(int vector[]){
    int i=0;
    srand(time(NULL));
    for(i=0; i<TAMANIO; i++){
        vector[i]= rand() % 10;
    }
    
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
