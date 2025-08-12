#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <signal.h>
int main(int argc, char *argv[]){

	int i,j;
	char cadena[127];
	if(argc==1){
		strcpy(cadena, argv[0]);
		printf("%s", cadena);
		strcat(cadena, " *.*");
		printf("%s", cadena);
		system(cadena);

	}
	j=argc;
	for(argc=0; argc<j; argc++){
		for(i=0; argv[argc][i]!='.'; i++)
			putchar(tolower(argv[argc][i]));

		for(; argv[argc][i]!='\0'; i++)
			putchar(toupper(argv[argc][i]));
		putchar('\n');

	}

	
	return 0;
}
