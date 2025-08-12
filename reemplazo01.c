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
 
  void replace(char *s,char nuevo,char viejo){         /*  Funcion de reemplazo */
	  for( ;(*s)!='\0';s++){
		  if(*s==viejo)
			  *s=nuevo;
      }

	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  }