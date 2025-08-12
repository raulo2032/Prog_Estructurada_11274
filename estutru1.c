#include<stdio.h>
#include<stdlib.h>
#define MAX 123

typedef char string[MAX];

typedef struct{
	string nombre;
	string apellido;
	int dni;
}factura;


int main(void){
	string documento;
	char *aux;
	int docum;
	factura persona;
	FILE *fo;

	if((fo=fopen("archivoestructura", "wb"))==NULL)  return 1;

	printf("ingrese los siuientes datos:\n");
    printf("ingrese su nombre: ");
	  gets(persona.nombre); 
	printf("ingrese su apellido: ");
	  fgets(persona.apellido, MAX, stdin); 
	printf("ingrese su numero de documento: ");
	  fgets(documento, MAX, stdin); 
	  docum=strtol(documento, &aux, 10);
	  persona.dni=docum;


    fwrite(&persona, sizeof(factura), 1, fo);
	if(fclose(fo)==EOF) return 1;
	return 0;
}
