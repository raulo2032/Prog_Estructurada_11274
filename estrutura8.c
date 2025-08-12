#include<stdio.h>

typedef struct{
	char calle[100];
	char depto[3];
	int numero_calle;
	int numero_depto;
}domicilio;

int main(void){
	domicilio *puntero_persona;
	domicilio persona;
    puntero_persona = &persona;
	strcpy(puntero_persona->calle, "Paseo Colon");
    strcpy(puntero_persona->depto, "\"A\"");
	puntero_persona->numero_calle=850;
	puntero_persona->numero_depto=3;

	printf("%s\n%s\t%i\n\t\t\t%i%s", "Alguien vive en: ",
		                   puntero_persona->calle,
		                   puntero_persona->numero_calle,
		                   puntero_persona->numero_depto,
		                   puntero_persona->depto  );
	return 0;
}
