/*  Escribir una función que acepte como parámetro un vector que contiene números positivos, 
    que puede contener valores duplicados, y reemplace cada elemento repetido por -1 (menos uno).  
    El procedimiento debe retornar el vector modificado y la cantidad de veces que fue modificado.      */

//  leo el vector, pero antes armo uno auxiliar
//  el elemento que leo lo busco en el auxiliar, si no esta, aux(elemento leido)=0, si esta, vector(pos_elem_leido = -1),
//  y sumo un contador de modificaciones

#include <stdio.h>
#define TAMANIO  10

void mostrar_vector(int[], int);
int busco_y_reemplazo( int[], int);
//  si aparece el número 7, marcamos vistos[7] = 1.
//  Si vuelve a aparecer 7, reemplazamos por -1.

int main(void){
    int vector_[TAMANIO] = {2, 5, 3, 5, 7, 3, 8, 7, 9, 7};
    
    mostrar_vector(vector_, TAMANIO);
    
    int cambios = busco_y_reemplazo(vector_, TAMANIO);

    mostrar_vector(vector_, TAMANIO);
    printf("Se realizaron %d cambios", cambios);


    return 0;
}
int busco_y_reemplazo( int vector_a_estudiar[], int tamanio){
    int modificaciones=0, i, vector_de_modificaciones[tamanio + 1], auxiliar;
    for(i=0; i<tamanio; i++){
        auxiliar=vector_a_estudiar[i];
        if(vector_de_modificaciones[auxiliar]==0){
            // primera vez que aparece
            vector_a_estudiar[i]=-1;
            modificaciones ++;
        }
        else{
            // se supone que aparecio
            vector_de_modificaciones[auxiliar]=1;
        }
        
    }
    return modificaciones;
}

void mostrar_vector(int vector[], int tamanio){
    for(int i=0; i<tamanio; i++){
        printf("[%d, ]", vector[i]);
    }
    printf("]\n");
}
