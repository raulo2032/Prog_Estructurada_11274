//  Dado un arreglo de N elementos, 
//  escribir un programa que permita desplazar los elementos del arreglo una posición a la derecha,
//  de tal forma que el primero pase a la segunda posición, el segundo a la tercera y 
//  así sucesivamente.      Ejemplo             A = {5, 7, 4, 9, 3} 
//                                              resultado = {3, 5, 7, 4, 9}          

// sabiendo el valor de N, podemos armar un nuevo arreglo tomando el ultimo original
// lo pongo en el primero 

//  el largo del vector lo conocemos
//  me guardo el ultimo valor, luego voy poniendo el anteultimo en el ultimo leido con un swap
//  el swap lo armo aparte 

#include <stdio.h>
#define TAMANIO 5

void mostrar_vector(int[]);
void swap(int *, int *);

int main(void) {
    int a, b, vector[TAMANIO]={2,5,3,8,4};;

    a = 5;
    b = 8;

    // printf("El valor de 'a' es %d, y el valor de 'b' es %d\n", a, b);
    mostrar_vector(vector);
    
    swap(&vector[0],&vector[1]);

    mostrar_vector(vector);

    // printf("El valor de 'a' es %d, y el valor de 'b' es %d\n", a, b);

    
    return 0;
}

void swap(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void mostrar_vector(int vector_a[]){
    int i;
    printf("[");
    for (i = 0; i < TAMANIO; i++){
        printf("%d, ", vector_a[i]);

    }
    
    
    printf("]");
    
}


