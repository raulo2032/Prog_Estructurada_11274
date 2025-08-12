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
	t_domicilio *domicilio;
}factura;


int main(void){
	string documento;
	char *aux;
	factura persona;
	factura *puntero_a_datos;
	puntero_a_datos= &persona;

	printf("ingrese los siuientes datos:\n");
    printf("ingrese su nombre: ");
	  gets(puntero_a_datos->nombre); 
	printf("ingrese su apellido: ");
	  fgets(puntero_a_datos->apellido, MAX, stdin); 
	printf("ingrese su numero de documento: ");
	  fgets(documento, MAX, stdin); 
      puntero_a_datos->dni=strtol(documento, &aux, 10);
	printf("sus datos son los siguientes\n\n\n");
	printf("%s%s\n", "nombre  : ", puntero_a_datos->nombre);
	printf("%s%s",   "apellido: ", persona.apellido);
	printf("%s%i\n", "dni     : ", puntero_a_datos-> dni);

	return 0;
}
