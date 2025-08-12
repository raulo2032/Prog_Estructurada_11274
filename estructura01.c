#include<stdio.h>
#include<stdlib.h>
#define MAX 123

typedef char string[MAX];

typedef struct{
	string calle;
	int numero;
}t_domicilio;

typedef struct{
	string nombre;
	string apellido;
	int dni;
	t_domicilio domicilio;
}factura;


int main(void){
	string documento;
	char *aux;
	int docum;
	factura persona;
	factura *puntero_a_datos;
	puntero_a_datos= &persona;
	FILE *fo;

	printf("ingrese los siuientes datos:\n");
    printf("ingrese su nombre: ");
	  gets(puntero_a_datos->nombre); 
	printf("ingrese su apellido: ");
	  fgets(puntero_a_datos->apellido, MAX, stdin); 
	printf("ingrese su numero de documento: ");
	  fgets(documento, MAX, stdin); 
	  docum=strtol(documento, &aux, 10);
	  (*puntero_a_datos).dni=docum;

	  if((fo=fopen(archivoestructura, "rw"))==NULL)  return 1;

	  fwrite(&persona, sizeof(factura), 1, fo);
	return 0;
}
