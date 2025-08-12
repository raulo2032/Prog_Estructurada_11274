#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	char calle[125];
	int numero;
}domicilio;
typedef struct{
	char nombre[250];
	domicilio*  t_domicilio;
}datos;

int main(void){

	datos       particular;
	domicilio   es_domicilio;
	
	FILE* fin;

	if((fin=fopen("asd", "rb"))==NULL)
		{ printf("error de lectura de asd");
	      return 1;
		}

	fread(&particular, sizeof(datos), 1, fin);
	fread(&es_domicilio, sizeof(domicilio), 1, fin);

	printf("%s%s\n", "nombre:  ",particular.nombre);
	printf("%s%s\n", "calle:   ", es_domicilio.calle);
	printf("%s%i\n",  "numero  :", es_domicilio.numero);

	if(fclose(fin)==EOF){ printf("error al cerrar asd");
	                                  return 1;}



	printf("Hello, world\n");
	
	return 0;
}
