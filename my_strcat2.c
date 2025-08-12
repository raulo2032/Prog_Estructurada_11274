#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef char string[256];

string str1, str2;

int main(int argc, char *argv[]){


	printf("%s", "ingrese las cadenas a concatenar\n");
	fgets(str1, 256, stdin);
	str1[strlen(str1)-1]='\0';
	fgets(str2, 256, stdin);

	printf("%s%s", "las cadenas concatenadas son:\n", strcat(str1, str2));
	
	return 0;
}

