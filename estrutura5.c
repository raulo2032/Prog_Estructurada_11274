#include<stdio.h>

typedef struct{
	char calle[78];
	char depto[12];
	int numero_calle;
	int numero_depto;
}capital;

int main(void){
	capital raul;
	strcpy(raul.calle, "viamonte");
    strcpy(raul.depto, "\"A\"");
	raul.numero_calle=2207;
	raul.numero_depto=7;

	printf("%s\n%s\t%i\n\t\t\t%i%s", "Raul vive en: ",
		                   raul.calle,
		                   raul.numero_calle,
		                   raul.numero_depto,
		                   raul.depto);
	return 0;
}
