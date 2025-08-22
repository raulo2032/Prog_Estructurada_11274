/* Hacer una función que reciba dos vectores A y B de números enteros de n cantidad de elementos,
  siendo n un número par, 
  y retorne la suma de los elementos que ocupan las posiciones pares del primero 
  con los elementos que ocupan las impares del segundo. Cero es un número par.   */

#include <stdio.h>
#include <time.h>    // time()
#include <stdio_ext.h>
#include <stdlib.h>

#define TAMANIO 6


int sumatoria(int[], int[], int);
void carga_vector(int[], int[], int);
void mostrar_vectores(int []);

int main(void){

  int vector_a[TAMANIO], vector_b[TAMANIO], suma, tamanio;

  tamanio = TAMANIO;

  printf("La suma de los pares de las pos pares del primero y las impares del segundo da:\n");
  carga_vector(vector_a, vector_b, tamanio);

  printf("Los vectores son: \n");
  mostrar_vectores(vector_a);
  mostrar_vectores(vector_b);

  printf("\nLa suma de los valores da: %d\n", sumatoria(vector_a, vector_b,tamanio));


  suma = sumatoria(vector_a, vector_b, tamanio);
  return 0;
}

int sumatoria(int vec_a[], int vec_b[], int tamanio)
{
  int i, suma = 0;
  for (i = 0; i < tamanio; i++){

    if ((i % 2) == 0){
      suma += vec_a[i];
    }
    else suma += vec_b[i];
    
  }

  return suma;
}

 void carga_vector(int vector1[], int vector2[], int largo){
  srand(time(NULL));      // para tener una semilla distinta cada vez
  int i, min, max;
  min = 0;
  max = 9;
  for ( i = 0; i < largo; i++){
    vector1[i]= min + rand() % (max - min + 1);
    vector2[i]= min + rand() % (max - min + 1);
        
  }
}

void mostrar_vectores(int vec[]){
  int i;
  printf("Vector : [");

  for ( i = 0; i < TAMANIO; i++){
    printf("%d,", vec[i]);
  }
  printf("]\n");
  

}