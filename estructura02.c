#include<stdio.h>
#include<stdlib.h>
#define MAX 128

typedef struct{
	char      nombre[MAX];
	int       dni;
	float     saldo;
}factura;

int main(void){
	factura     *pu_cliente;
	factura     cliente;
    pu_cliente = &cliente;
    char       *str_dni[MAX];
	char       *str_saldo[MAX];
	char*       temporal;

	printf("Nombre de cliente: ");
    	fgets(cliente->nombre, MAX, stdin);
	printf("DNI              :");
	    fgets(str_dni, MAX, stdin);
	    cliente->dni=strtol(str_dni, &temporal, 10);
	printf("saldo acumulado  :");
	    fgets(str_saldo, MAX, stdin);
		cliente->saldo=strtod(str_saldo, &temporal);
	printf("%s%s%s%i%s%f", 
		                 "El senior ",
		                 cliente->nombre,
		                 "  ",
		                 cliente->dni,
		                 "\tdebe un monto de",
		                 cliente->saldo);
	return 0;
}
