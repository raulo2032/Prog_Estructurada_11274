#include <stdio.h>

int main(void)
{  struct agenda{          /* el tipo es "struct agenda" */
		int i;
		int g;
		char apellido[200];
	    char nombre[50];
	    char calle[88];
	    int numero;
		};
	struct agenda raul;         /*declaro un struc agenda, llamado raul */

	raul.i= 254;
	raul.g=900;
	strcpy(raul.apellido, "aggio");
	strcpy(raul.nombre, "raul");
    printf("%i\n%i\t%s", raul.i, raul.g, raul.apellido);
	printf("\n\t\t%s\n", raul.nombre);

	
    raul.numero=1018;
    strcpy(raul.calle, "las heras");
	printf("%s\t%i", raul.calle, raul.numero);
return 0;
}
