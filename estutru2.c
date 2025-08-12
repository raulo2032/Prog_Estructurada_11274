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
	factura persona;
	FILE *fo;

	if((fo=fopen("archivoestructura", "rb"))==NULL)  return 1;

	fread(&persona, sizeof(factura), 1, fo);
		printf("sus datos son los siguientes\n\n\n");
		printf("%s%s\n", "nombre  : ", persona.nombre);
		printf("%s%s\n", "apellido: ", persona.apellido);
		printf("%s%i\n", "dni     : ", persona.dni);
	
	if(fclose(fo)==EOF)  return 1;

	return 0;
}
