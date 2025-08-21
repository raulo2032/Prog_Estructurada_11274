// Dados dos vectores A y B de igual cantidad de elementos 
// cargados con la función del punto 1, 
// obtener el producto escalar: Σ A(i) * B(i).

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>    // time()

#define LARGO 5

void carga_vector(int[], int[], int, int, int);
void muestra_vector(int[], int);
int producto_escalar(int[], int[], int);

int main(void) {
    int vector_a[64], vector_b[64], producto;

    printf("Los vectores quedan \n");
    carga_vector(vector_a, vector_b, LARGO, 0,9);
    muestra_vector(vector_a, LARGO);
    muestra_vector(vector_b, LARGO);

    
    producto = producto_escalar(vector_a, vector_b, LARGO);
    printf("El producto escalar da : %d\n", producto);
    return 0;
}

void carga_vector(int vector1[], int vector2[], int largo, int min, int max){
    srand(time(NULL));      // para tener una semilla distinta cada vez
    int i;
    for ( i = 0; i < largo; i++){
        vector1[i]= min + rand() % (max - min + 1);
        vector2[i]= min + rand() % (max - min + 1);
        
    }
    

}

void muestra_vector(int vector[], int largo){
    int i;
    
    printf("Vector \n[");
    for ( i = 0; i < largo; i++){
        printf("%d", vector[i]);
        if(i<largo-1) printf(", ");
    
    }
    printf("] \n");
    

}

int producto_escalar(int vector_a[], int vector_b[], int largo){
    int sumandos=0, i;
    for ( i = 0; i < largo; i++){
        sumandos += vector_a[i]*vector_b[i];
        
    }
    

    return sumandos;
}
