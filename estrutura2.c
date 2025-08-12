#include <stdio.h>
typedef struct {
	char calle[88];
	int numero;
	}domiciliof;    /* el dato es de tipo domicilio y es global */

int main(void)
{  struct agenda{          /* el tipo es "struct agenda" */
		int i;
		int g;
		char apellido[200];
	    char nombre[50];
		};
	struct agenda raul;         /*declaro un struc agenda, llamado raul */
    domiciliof pedro;            /* declaro, cosas del tipo domicilio*/

	raul.i= 254;
	raul.g=900;
	strcpy(raul.apellido, "aggio");
	strcpy(raul.nombre, "raul");
    printf("%i\n%i\t%s", raul.i, raul.g, raul.apellido);
	printf("\n\t\t%s\n", raul.nombre);

	
    pedro.numero=666;
    strcpy(pedro.calle, "las heras");
	printf("%s\t%i", pedro.calle, pedro.numero);
return 0;
}
