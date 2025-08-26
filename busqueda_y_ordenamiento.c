#include <stdio.h>
#define TAMANIO 10
int busca_binaria(int , int [], int );
void mostrar_arreglo(int []);
void orden_seleccion(int [], int );
void ordena_burbuja(int [], int);


int main(void) {
    int vector[TAMANIO]={5,8,6,9,4,2,3,6,1,9};
    printf("El arreglo original es\n");

    mostrar_arreglo(vector);
    // ordena_burbuja( vector, TAMANIO);
    //  orden_seleccion(vector, TAMANIO);
    ordena_insercion(int vector[], int largo){


    mostrar_arreglo(vector);

    printf("El numero 1 se encuentra en la posicion nro %d\n", busca_binaria(1, vector, TAMANIO));

    return 0;
}

void ordena_insercion(int vector[], int largo){
    int i, key, j;
    for (i = 1; i < largo; i++){
        key = vector[i];
        j = i--;
        
        // Mover los elementos del array que son mayores que key 
        // a una posición adelante de su posición actual

        while (j >= 0 && vector[j] > key){
            vector[j + 1] = vector[j];
            j = j - 1;
        }
        vector[j + 1] = key;
    }
}

void orden_seleccion(int VEC[], int largo){
    int i, j, min, aux;
    for(i = 0; i < largo-1; i++){
        min = i;

        /* búsqueda de mínimo */
        for(j = i+1; j < largo; j++){
            if(VEC[j] < VEC[min]){
                min = j;
            }
        }

        aux = VEC[i];
        VEC[i] = VEC[min];
        VEC[min] = aux;
    }
}
void mostrar_arreglo(int vector[]){
    printf("[");
    for (int i = 0; i < TAMANIO; i++){
        printf("%d", vector[i]);
        if(i<TAMANIO-1)printf(",");
    }
    printf("]\n");
    
}
int busca_binaria(int clave, int vector[], int largo){
    int inferior, superior, centro;
    inferior = 0;
    superior = largo-1;

    while ((inferior <= superior)){
        centro = (inferior + superior) / 2;
        if (clave == vector[centro]){
            return centro;
        }
        else
            if (clave < vector[centro]){
                superior = centro - 1;
            }
        else
            inferior = centro + 1;
    }
    return largo;
}

void ordena_burbuja(int vector[], int largo){
    int i, j, aux;
    for (i = largo-1; i > 0; i--){
        for (j = 1; j <= i; j++){
            
            if (vector[j-1] > vector[j]){
                               
                aux = vector[j];
                vector[j] = vector[j-1];
                vector[j-1] = aux;
            }
        }
    }
}
