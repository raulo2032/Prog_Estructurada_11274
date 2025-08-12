/*este lee la estrcutura grabada por estructura06.c*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define   MAX 256

typedef char string[MAX];
typedef struct{
	string  apellido;
	int     userID;
	float   saldo;
	int     tantos;
}factura;

int main(void){

	FILE* f;
	factura cliente;
	int i;
	
	f=fopen("saldrabien", "rb");
	if(f==NULL){printf(" no se termino de abrir el archivo");
	         	return 1;	}
	for(i=0; i<=(cliente.tantos)  ; i++)
	{fread(&cliente, sizeof(factura), 1, f);


    printf("%s%s\n%s%i\n%s%f\n",
	       "apellido :", cliente.apellido,
		   "userID   :", cliente.userID,
		   "saldo    :", cliente.saldo);
	}
	if(fclose(f)==EOF){
		printf("error");
		return 1;
	}
	return 0;
}
	