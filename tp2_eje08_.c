#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAMANIO 10

void carga_vector(int[], int);
void copia_vector(int[], int[], int);
void compara_vector(int[], int[], int);
void muestra_vector(int[], int);
int comparacion = 8;

int main(void){
    srand(time(NULL));
    int vector_a[TAMANIO], vector_b[TAMANIO]={3 ,2 ,1 ,1 ,2 ,0 ,6 ,5 ,1 ,7 };

    carga_vector(vector_a, TAMANIO);
    
    printf("Los vectores originales son: \n");

    // carga_vector(vector_b, TAMANIO);


    muestra_vector(vector_a, TAMANIO);
    muestra_vector(vector_b, TAMANIO);

    compara_vector(vector_a, vector_b, TAMANIO);

    if(comparacion == 1){
        printf("Los vectores son iguales !!!");
    }
    else
        printf("Los vectores son distintos :-(");


}

void carga_vector(int vector[], int tamanio){
    int i;
    srand(time(NULL));
    for(i=0; i<tamanio; i++){
        vector[i]= rand() % 10;
        
    }

}
void copia_vector(int vector_a[], int vector_b[], int tamanio){
    int i;
    for(i=0; i<tamanio; i++){
        // vector_b[i]=vector_a[i];
        
    }
}
void compara_vector(int vector_a[], int vector_b[], int tamanio){
    int i;
    for(i=0; i<tamanio; i++){
        if(vector_a[i]==vector_b[i]){
            comparacion = 1;
        }
        else    
            comparacion = 0;

    }

}
void muestra_vector(int vector[], int tamanio){
    int i;
    printf("El vector es : [");
    for(i=0; i<tamanio; i++){
        printf("%d ,", vector[i]);
    }
    printf("]\n");

}
