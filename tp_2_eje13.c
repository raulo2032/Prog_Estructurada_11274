//  función que reciba un vector con n elementos numéricos y 
//  retorne la cantidad de números negativos que se encuentran en el vector.

#include <stdio.h>

#define TAMANIO 10

void cuenta_negativos(int [], int, int[]);


int main(void){
    int vector[TAMANIO]={2,5,-5,-6,-5,3,-8,9,10};
    int i, cantidades[3]; 
    
    printf("El vector original es: \n[");
    for(i=0; i<TAMANIO; i++){
        printf("%d ", vector[i]);
        if(i<TAMANIO-1) printf(", ");
    }
    printf("]\n");
    
    
    cuenta_negativos(vector, TAMANIO, cantidades);
    
    
    printf("La cantidad de numeros negativos es < %d > \n", cantidades[0]);
    printf("La cantidad de numeros positivos es < %d > \n", cantidades[1]);
    printf("La cantidad de numeros ceros es < %d > \n", cantidades[2]);
    
    
    
}

void cuenta_negativos(int vector[], int tamanio, int cantidades[]){
    int cont_neg = 0, cont_pos =0, cont_ceros=0;
    
    for(int i=0; i<tamanio; i++){
        if(vector[i]<0){
            cont_neg ++;
        }
        else if(vector[i]>0){
            cont_pos ++;
        }
        else if(vector[i]==0){
            cont_ceros ++;
        }
    }
    cantidades[0]=cont_neg;
    cantidades[1]=cont_pos;
    cantidades[2]=cont_ceros;

    

    
}
