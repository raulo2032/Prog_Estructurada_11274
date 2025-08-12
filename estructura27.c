#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 256

typedef char string[MAX];

typedef struct{
	string      calle;
	int         numero_calle;
	string      depto;
}estructura_domicilio;

typedef struct{
	string                nombre;
	int                   dni;
	estructura_domicilio  *domicilio;

}estructura_de_datos;

int main(void){
	estructura_de_datos    estructura_raul;
	estructura_domicilio   estructura_domicilio_de;
	estructura_domicilio   *p_domicilio;
	p_domicilio    =       &estructura_domicilio_de;
	
	strcpy(estructura_raul.nombre,"Raul");
   	estructura_raul.dni=30647289;
	strcpy(p_domicilio->calle, "Viamonte"); /* notacion de ->      */
	p_domicilio->numero_calle= 2207;
	strcpy((*p_domicilio).depto, "\"A\"");  /* notacion de punteros*/
	
	printf("\n\n%s\n\n\n%s%s\n%s%i\n%s%s\t%i\t%s\n\n",
		"----------------Datos de la persona-------------------",
		"Nombre      : ", estructura_raul.nombre,
		"DNI         : ", estructura_raul.dni,
		"Domicilio   : ", p_domicilio->calle,
		                  p_domicilio->numero_calle,
		                  p_domicilio->depto);

	return 0;
}
