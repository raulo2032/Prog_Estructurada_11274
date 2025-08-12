#include <stdio.h>
#include <stdlib.h>
 
void swap (int* , int*);  /* ESTE ES EL PROTOTIPO */

int main(void){
	int a , b;
    printf("%s", "Ingrese un valor de a : ");
    scanf("%i",&a);
    printf("%s", "Ingrese un valor de b : ");
    scanf("%i",&b);
    swap(&a,&b);
	printf("%s%i\n", "Nuevo valor de a : ",  a );
    printf("%s%i\n", "Nuevo valor de b : ",  b );

	return EXIT_SUCCESS;
	}
 
 void swap (int *x , int *y){
	 int aux;
	 aux = *x;
	 *x = *y;
	 *y = aux;

	 }