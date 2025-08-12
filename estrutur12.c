#include<stdio.h>
#include<stdlib.h>

#define MAX_CALLE 100
#define MAX_NOMBRE 60
/* estructuras*/
typedef struct{
	char nombre[MAX_NOMBRE];
	char calle[MAX_CALLE];
	char depto[3];
	int numero_calle;
	int numero_depto;
}datos;
/*    prototipos   */

datos* mostrar_datos(datos *);
datos* ingresar_datos(datos *);
/* variables globales  */

datos *persona;   /* persona es un puntero a una estructura 
                             definida como tipo datos          */
datos agenda;   /* agenda es una  estructura */

int main(void){
	persona = &agenda;   /* agenda apunta a persona, es decir, apunta a la 
                            estructura de la persona    */
	ingresar_datos(persona);
	mostrar_datos(persona);

	return 0;
}

datos* mostrar_datos(datos *datos){
	printf("%s%s\t%s\t%i\t\t%i%s",
		persona->nombre,
		" vive en: ",
		persona->calle,
		persona->numero_calle,
		persona->numero_depto,
		persona->depto  );
	return persona;
}


datos* ingresar_datos(datos *puntero_persona){
   	char s[MAX_CALLE];
	int i;
	char *punteroaux;

	printf("ingrese su nombre:\n");
	gets(persona->nombre);
	printf("ingrese el nombre de la calle\n");
	gets(persona->calle);
	printf("ingrese la letra de depto\n");
    gets(persona->depto);
	printf("ingrese le numero de la calle\n");
    fgets(s, 5, stdin);
     i=strtol(s, &punteroaux, 10);
     persona->numero_calle=i;
	printf("ingrese el numero de dpto\n");
	scanf("%i", &persona->numero_depto);

	return persona;
}


