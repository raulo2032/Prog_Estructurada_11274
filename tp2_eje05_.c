#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO 30

void mostrar_vector(char [], int);
void crgar_vector(char [], int);
int aleatorio(int, int);

int main()
{
    int tamanio = TAMANIO, a, b, maximo=tamanio, minimo=0;
    char vector[tamanio];
   
    printf("Se genera un vector\n");
    crgar_vector(vector, tamanio);
   
    mostrar_vector(vector, tamanio);
   
    srand(time(NULL));      // para tener una semilla distinta cada vez
    int valora;
    valora = minimo + rand() % (31);
    int valorb = minimo + rand() % (maximo - minimo + 1);
   
    printf("a=%d, b=%d\n", valora,valorb);
   
    if(valora!=valorb){
        vector[valora]='A';
        vector[valorb]='B';
    }
    mostrar_vector(vector, tamanio);

    return 0;
}

void mostrar_vector(char vector[], int tamanio){
    printf("El vector cargado queda: \n[");
    for(int i = 0; i<tamanio; i++){
        printf("%c, ", vector[i]);
    }
    printf("]\n");
}
void crgar_vector(char vector[], int tamanio){
    for(int i=0; i<tamanio; i++){
        vector[i]='x';
    }
}
int aleatorio(int minimo, int maximo){
    srand(time(NULL));      // para tener una semilla distinta cada vez
    int valor;
    valor = minimo + rand() % (maximo - minimo + 1);
    printf("a=%d", valor);
       
    return valor;
}
