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

	
	f=fopen("saldrabien", "wb");
	if(f==NULL){printf(" no se termino de abrir el archivo");return 1;	}
	
	printf("%s", " Pulse EOF para salir, o enter opara continuar");

	while((opcion=getchar())!=EOF){
		printf("apellido :");
			gets(cliente.apellido);
		printf("userID   :");
			fgets(buffer, MAX, stdin);
		    cliente.userID=strtol(buffer, &temporal, 10);
	    printf("saldo    :");
		    fgets(buffer, MAX, stdin);
			cliente.saldo=strtod(buffer, &temporal);

		fwrite(&cliente, sizeof(factura), 1, f);

        printf("pulse EOF ");
	}
	if(fclose(f)==EOF){		printf("error");		return 1;
	}
	return 0;
}
	