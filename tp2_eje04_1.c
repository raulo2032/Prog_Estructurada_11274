#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define TAMANIO 5
void mostrar_vector(int[], int);
void swap(int *, int *);
void rotar_vector(int[], int);
void rellenar_vector(int [], int);

int main(){
    int vector[TAMANIO];
    int tamanio = TAMANIO;
    rellenar_vector(vector, TAMANIO);
    printf("El vector original es el siguiente:\n");
   
    mostrar_vector(vector, TAMANIO);
    printf("\n");
    rotar_vector(vector, tamanio);
   
    //swap(vector[0], vector[5]);
    printf("\n");
    printf("El vector desplazado a la derecha queda:");
    mostrar_vector(vector, TAMANIO);
   
    return 0;
}

void mostrar_vector(int vector[], int tamanio){
    int i;
    for(i=0; i<tamanio; i++){
        printf("%d", vector[i]);
    }
}

void swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void rotar_vector(int vector[], int tamanio){
    int auxiliar, i;
    auxiliar=vector[tamanio-1];
   
    for(i=tamanio-1; i>=0; i--){
        swap(&vector[i],&vector[i-1]);
       
    }
    vector[0]=auxiliar;
}
