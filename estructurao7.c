#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define   MAX 256

typedef char string[MAX];
typedef struct{
	string  apellido;
	int     userID;
	float   saldo;
}factura;

int main(void){

	FILE* f;
	factura cliente;
	string buffer;
	char opcion;
	char *temporal;

	
	f=fopen("saldrabien", "rb");
	if(f==NULL){printf(" no se termino de abrir el archivo");return 1;	}
	

	while(!feof(f)){

		fread(&cliente, sizeof(factura), 1, f);

		printf("%s%s%s%i\n%s%f\n",
			"apellido  :", cliente.apellido,
			"userID    :", cliente.userID,
			"saldo     :", cliente.saldo);

	}
	if(fclose(f)==EOF){		printf("error");		return 1;
	}
	return 0;
}
	