/* Hacer una función que reciba dos vectores A y B de números enteros de n cantidad de elementos,
  siendo n un número par, 
  y retorne la suma de los elementos que ocupan las posiciones pares del primero 
  con los elementos que ocupan las impares del segundo. Cero es un número par.   */

  #include <stdio.h>
  
  #define TAMANIO 5

  int sumatoria(int[], int[], int);
  int main(void) {

    int vector_a[TAMANIO], vector_b[TAMANIO], suma, tamanio;

    tamanio = TAMANIO;

    printf("Hello, world!\n");
    suma = sumatoria(vector_a, vector_b, tamanio);
    return 0;
  }


  int sumatoria(int vec_a[], int vec_b[], int tamanio){
    int i,suma = 0;
    for(i = 0; i < tamanio; i++){

        if((i%2)==0){
            suma += vec_a[i];
        }
        suma += vec_b[i];
        
    }
    
    return suma;
  }