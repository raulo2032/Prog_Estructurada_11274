/******orden por intercambio, algoritmo de la burbuja    optimizado*******************/
/*******va comparando consecutivamente los elementos *******************************/

#include<stdio.h>
#define MAX 5

void burbuja_optimizada(int *vec, int cant);
 
int main(void){
	
	int vector[MAX];
 
    vector[0]=1;
    vector[1]=22;
    vector[2]=31;
    vector[3]=15;
    vector[4]=4;

	printf("%s", " El arreglo sin ordenar es el siguiente:\n");

	for(i=0; i<MAX; i++)
		printf("%i%c", vector[i], '\n');

	printf("%s", " El arreglo ordenado es el siguiente:\n");


    burbuja_optimizada (vector, MAX);
    return 0;
}


void burbuja_optimizada(int *vec, int cant){
	int t, i, j, intercambio;
    i=0;
    do{
		intercambio=0;
		for(j=i; j<(cant-1); j++){
			if(vec[j]>vec[j++]){
				intercambio=1;
				t=vec[j];
				vec[j++]=t;
				vec[j++]=t;
			}
		}
		i++;
	}
	while(intercambio==1);

    for(i=0; i<cant; i++)
		printf("%d\n", vec[i]);
  }