#include<stdio.h>

typedef struct{
	char calle[100];
	char depto[3];
	int numero_calle;
	int numero_depto;
}domicilio;

int main(void){
	domicilio *puntero_persona;
	printf("ingrese el nombre de la calle");
	gets(puntero_persona->calle);
	printf("ingrese la letra de depto");
    gets(puntero_persona->depto);
	printf("ingrese le numero de la calle");
	gets(strtod(puntero_persona->numero_calle));
	printf("ingrese el numero de dpto");
	scanf("%i", &puntero_persona->numero_depto);

	printf("%s\n%s\t%i\n\t\t\t%i%s", "Alguien vive en: ",
		                   puntero_persona->calle,
		                   puntero_persona->numero_calle,
		                   puntero_persona->numero_depto,
		                   puntero_persona->depto  );
	return 0;
}
