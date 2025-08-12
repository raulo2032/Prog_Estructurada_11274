#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 256

typedef char string[MAX];

typedef struct{
	string    calle;
	int       numero_calle;
	string    depto;
}estructura_domicilio;

typedef struct{
	string				 nombre;
	string				 apellido;
	int					 dni;
	estructura_domicilio *domicilio;
}estructura_de_datos;

int main(void){
	estructura_de_datos    estructura_raul;
	estructura_domicilio   *p_domicilio;
	estructura_domicilio   domicilio;
	FILE                   *fin;

	fin=fopen("estrucutraprueba","rb");
    if(fin==NULL)		return EXIT_FAILURE;

	fread(&estructura_raul, sizeof(estructura_de_datos), 1, fin);

	printf("%s%s\n%s%s\n%s%i\n",
		"nombre:   ", estructura_raul.nombre,
		"apellido: ", estructura_raul.apellido,
		"dni:      ", estructura_raul.dni);
	fread(&domicilio, sizeof(estructura_domicilio), 1, fin);
	printf("%s%s\n", "calle :", domicilio.calle);

	if(fclose(fin)==EOF)  return 1;


	return 0;
}
