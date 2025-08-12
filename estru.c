#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
	char calle[205];
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

	if((fin=fopen("asd", "wb"))==NULL)
		{ printf("error de lectura de asd");
	      return 1;
		}

	strcpy( particular.nombre, "raul");
	strcpy( es_domicilio.calle, "las heras");
	es_domicilio.numero=1018;

	fwrite(&particular, sizeof(datos), 1, fin);
	fwrite(&es_domicilio, sizeof(domicilio), 1, fin);

	if(fclose(fin)==EOF){ printf("error al cerrar asd");
	                                  return 1;}



	printf("Hello, world\n");
	
	return 0;
}
