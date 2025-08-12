#include<stdio.h>
#define MAX 50

 void replace(char *,char ,char ); /* prototipo de  funcion */
 char cadena[MAX], vie, nue;
  
 int main(void){
	 printf("%s", "Ingrese la cadena: ");
	 gets(cadena);
	 printf("%s", "Ingrese el caracter que desea reemplazar:             ");
	 scanf("%c",&vie);
	 printf("%s%c%s", "Ingrese el caracter por el cual desea reemplazar a ",vie, ": ");
	 scanf("%s",&nue);
	 replace(cadena,nue,vie);
	 printf("\n%s\n\t\t\t%s", "La nueva cadena es:  ", cadena);

	 return 0;
	 }
  void replace(char *cadena, char nuevo, char viejo){

	  int i;

	  for(i=0; cadena[i]!='\0'; i++)
		  if(cadena[i]==viejo)
		  cadena[i]=nuevo;
  }
	  