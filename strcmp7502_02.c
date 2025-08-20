/******     anda perfecto, con punteros                 ******/
/******           strcmp()    for( ,   ,   )            ******/
#include <stdio_ext.h>
#include<stdio.h>

#define MAX 128

  int main(){
	  int i, f;
      char fuente1[MAX], fuente2[MAX];
      char *f1, *f2;
      f1=&fuente1[0];
      f2=&fuente2[0];
      printf("%s","Ingrese la cadena para que este programa le devuelva ");
      printf("%s","como resultado la comparacion lexicograficamente de las cadenas\n");
     
      printf("%s","\n ingrese la primer cadena:\n");
       fgets(f1, MAX, stdin);
       __fpurge(stdin); // limpia el buffer de entrada
      printf("%s","\n ingrese la segunda cadena:\n");
       fgets(f2, MAX, stdin);
       __fpurge(stdin); // limpia el buffer de entrada
      
	  for(i=0; ((*(f1+i)==*(f2+i)))!='\0'; i++)
		  ;
	   f=((*(f1+i)-*(f2+i)));
	  if(f==0)  printf("%s\n", "las cadenas son iguales");
      else if(f>0)   printf("%s\n", "la segunda cadena es menor que la primera");
      else if(f<0)   printf("%s\n", "la segunda cadena es mayor que la primera") ;
      
      return 0;
   }
     