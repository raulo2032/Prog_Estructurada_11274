/* esta tiene burbuja para enteros, anda joya*/

#include <stdio.h>
#include<string.h>

typedef char *string[128];
typedef enum{TRUE, FALSE}bool;
void swap (int*, int*);
void burbuja_enteros(int *v, int n);


int main(void){
	int i;
	int vector[]={2,8,9,4,65,87,25,6};

	printf("%s", "El arreglo sin ordenar es el siguiente:\n");
	for(i=0; i<7; i++)
		printf("%i\t", vector[i]);
	
	printf("\n\n\n\n\n");
	
	burbuja_enteros(vector, 8);

	printf("%s", "El arreglo ordenado es el siguiente:\n");

	for(i=0; i<7; i++)
		printf("%i\t", vector[i]);
	
	return 0;
}

void burbuja_enteros(int *v, int n){
	int i, j;
	bool flag;
	for(i=0; i<n; i++){
		flag=FALSE;
		for(j=0; j<n-1; j++){
			if(v[j]>v[i]){
				swap(&v[j], &v[i]);
				flag=TRUE;
			}
		}
		if(flag==FALSE)
			return;
	}
}
void swap(int *x , int *y){
	int aux;
	aux= *x;
	*x = *y;
	*y = aux;
}