#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 5

void cargar_vector(int[], int);
void mostrar_vector(int[], int);
int busca_maximo(int [], int);
int main(void){
    int vector[TAMANIO], largo = TAMANIO;

    cargar_vector(vector, largo);
    mostrar_vector(vector, largo);
    printf("El valor maximo del vector es %d", busca_maximo(vector, largo));

    return 0;
}

void cargar_vector(int vector[], int largo){
    int i;
    srand(time(NULL));
    for(i=0; i<largo; i++){
        vector[i]=rand()%10;
    }
}
void mostrar_vector(int vector[], int largo){
    int i;

    printf("El vector es :\n[");
    for ( i = 0; i < largo; i++){
        printf("%d", vector[i]);
        if(i<largo-1){
            printf(",");
        }
    }

    printf("]\n");
    
}
int busca_maximo(int vector[], int largo){

    int i, maximo = 0;
    for(i=0; i<largo; i++){
        if(vector[i]>maximo){
            maximo=vector[i];
        }
    }
    return maximo;

}
