//  función que reciba un vector con n elementos numéricos y 
//  retorne la cantidad de números negativos que se encuentran en el vector.

#include <stdio.h>

#define TAMANIO 10

int cuenta_negativos(int [], int);

int main(void){
    int vector[TAMANIO]={2,5,-5,-6,-5,3,-8,9,10};
    int i, cantidad_neg;

    printf("El vector original es: \n[");
    for(i=0; i<TAMANIO; i++){
        printf("%d, ", vector[i]);
    }
    printf("]\n");
    cantidad_neg = cuenta_negativos(vector, TAMANIO);

    printf("La cantidad de numeros negativos es < %d > \n", cantidad_neg);


}

int cuenta_negativos(int vector[], int tamanio){
    int contador = 0;
    for(int i=0; i<tamanio; i++){
        if(vector[i]<0){
            contador ++;
        }
    }
    return contador;
}
