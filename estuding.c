#include <stdio.h>
#define MAX 256

typedef char string[MAX];

int main(int argc, char *argv[])
{
	string cadena;
	printf("Ingrese una cadena decaracteres\n");
	fgets(cadena, MAX, stdin);
	printf("%s\n%s\n", " la cadena ingresada fue: ",cadena);

	
	return 0;
}
