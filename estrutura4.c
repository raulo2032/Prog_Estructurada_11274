#include <stdio.h>
typedef struct agenda{          /* defino un tipo nuevo, el tipo es  agenda */
		int i;
		int g;
		char apellido[200];
	    char nombre[50];
	    char calle[88];
	    int numero;
		}agenda;
	
int main(void)
{  agenda raul;   /* declaro un agenda, llamado raul*/

	raul.i= 254;
	raul.g=900;
	raul.numero=1018;
	
	strcpy(raul.apellido, "aggio");
	strcpy(raul.nombre, "raul");
    strcpy(raul.calle, "las heras");
	
	printf("%i\n%i\t%s", raul.i, raul.g, raul.apellido);
	printf("\n\t\t%s\n", raul.nombre);
	printf("%s\t%i", raul.calle, raul.numero);
return 0;
}
