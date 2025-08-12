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
	string documento, numero_calle;
	char *aux;
	factura persona;
	factura *puntero_a_datos;
	puntero_a_datos= &persona;
    
	printf("%s", "ingrese los siuientes datos:\n");
    printf("%s", "ingrese su nombre             : ");
	  gets(puntero_a_datos->nombre); 
	printf("%s", "ingrese su apellido           : ");
	  gets(puntero_a_datos->apellido); 
	printf("%s", "ingrese su numero de documento: ");
	  gets(documento); 
      puntero_a_datos->dni=strtol(documento, &aux, 10);
	printf("%s", "ingrese su domicilio          : ");
	printf("%s", "\n\t\tcalle         : ");
	  gets(persona.domicilio->calle);
    printf("%s", "numero de calle               : ");
	  gets(numero_calle);
	  persona.domicilio->numero=strtol(numero_calle, &aux, 10);

	printf("\n\n--------------Sus datos son los siguientes-----------");
	printf("\n\n\n");
	printf("%s%s\n", "nombre  : ", puntero_a_datos->nombre);
	printf("%s%s",   "apellido: ", persona.apellido);
	printf("%s%i\n", "dni     : ", puntero_a_datos-> dni);
    printf("%s%s",   "calle   : ", persona.domicilio->calle);
    printf("\t%i",                 persona.domicilio->numero);

	return 0;
}
