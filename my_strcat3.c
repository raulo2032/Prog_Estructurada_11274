/* esta mierda no anda*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

typedef char string[256];

char* my_strcat(char*, char*);
string str1, str2;

int main(int argc, char *argv[]){


	printf("%s", "ingrese las cadenas a concatenar\n");
	fgets(str1, 256, stdin);
	str1[strlen(str1)-1]='\0';
	fgets(str2, 256, stdin);

	printf("%s%s", "las cadenas concatenadas son:\n", my_strcat(str1, str2));
	
	return 0;
}

char* my_strcat(char fuente[], char final[]){
/* esto no andaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa*/
int i=0, j;
	string aux;
	while(fuente[i]!='\0')
		aux[i++]=fuente[i];
	while(final[j]!='\0')
		*(aux+i)=*(final+j);
	*(aux+i)='\0';
	fuente=aux;
	return fuente;
}