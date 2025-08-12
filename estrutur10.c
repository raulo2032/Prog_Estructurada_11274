#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_CALLE 100
#define MAX_NOMBRE 60


typedef struct{
	char nombre[MAX_NOMBRE];
	char calle[MAX_CALLE];
	char depto[3];
	int numero_calle;
	int numero_depto;
}domicilio;
void mostrar_datos(domicilio *persona);

	domicilio *puntero_persona;
int main(void){
	char s[MAX_CALLE];
	int i;
	char *punteroaux;
	domicilio puntero;
	puntero_persona = &puntero;
	printf("ingrese su nombre:\n");
	gets(puntero_persona->nombre);
	printf("ingrese el nombre de la calle\n");
	gets(puntero_persona->calle);
	printf("ingrese la letra de depto\n");
    gets(puntero_persona->depto);
	printf("ingrese le numero de la calle\n");
    fgets(s, 5, stdin);
    i=strtol(s, &punteroaux, 10);
    puntero_persona->numero_calle=i;
	printf("ingrese el numero de dpto\n");
	scanf("%i", &puntero_persona->numero_depto);
    
	mostrar_datos(puntero_persona);
	return 0;
}

void mostrar_datos(domicilio *persona){
	printf("%s%s\t%s\t%i\t\t%i%s",
		puntero_persona->nombre,
		" vive en: ",
		puntero_persona->calle,
		puntero_persona->numero_calle,
		puntero_persona->numero_depto,
		puntero_persona->depto  );
	return;
}