
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
	estructura_domicilio   domicilio_part;
	string                 numero_dni;
    string                 str_numero_calle;
	char                   *temporal;
	FILE                   *fin;
	p_domicilio         =  &domicilio_part;


	fin=fopen("estrucutraprueba","rb");

    if(fin==NULL) return EXIT_FAILURE;

	fread(&estructura_raul, sizeof(estructura_de_datos), 1, fin);
	printf("\n\n%s\n\n%s%s\t%s%s%s%i\n%s%s\t%i\t%s\n\n",
		"----------------Datos de la persona-------------------",
		"Nombre      : ", estructura_raul.nombre," ", estructura_raul.apellido,
		"DNI         : ", estructura_raul.dni,
		"Domicilio   : ", p_domicilio->calle,
		                  p_domicilio->numero_calle,
		                  p_domicilio->depto);

	


	return 0;
}
