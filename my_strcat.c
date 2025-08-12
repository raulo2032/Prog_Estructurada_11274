#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef char string[502];

void my_strcat(char s[], char t[]);

int main(int argc, char *argv[]){
	int i=0, d=0;
	char *p1, *p2;
	string cadena1, cadena2;

	p1=cadena1;
	p2=cadena2;

	
	printf("ingrese las cadenas a concatenar:\n");

	fgets(cadena1, 256, stdin);
	fgets(cadena2, 128, stdin);

	while(cadena1[i++])
		d++;
	while(*(cadena2+d))
		cadena1[i++]=cadena2[d++];
	*(cadena1+d)='\0';

	printf("%s%s", "las cedenas concatenadas son:\n", cadena1);
	
	return 0;
}
