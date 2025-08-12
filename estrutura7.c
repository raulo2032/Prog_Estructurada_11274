#include<stdio.h>

typedef struct{
	char calle[78];
	char depto[12];
	int numero_calle;
	int numero_depto;
}capital;

int main(void){
	capital *punteroaraul;
	capital raul;
    punteroaraul = &raul;
	strcpy(punteroaraul->calle, "viamonte");
    strcpy(punteroaraul->depto, "\"A\"");
	punteroaraul->numero_calle=2207;
	punteroaraul->numero_depto=7;

	printf("%s\n%s\t%i\n\t\t\t%i%s", "Raul vive en: ",
		                   punteroaraul->calle,
		                   punteroaraul->numero_calle,
		                   punteroaraul->numero_depto,
		                   punteroaraul->depto  );
	return 0;
}
