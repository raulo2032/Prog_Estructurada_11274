/*************anda perfecto, con ounteros                          */
/*******************           strcmp()         while******************/

#include<stdio.h>
#define MAX 128

  int main(){
	  int i, d;
      char fuente1[MAX], fuente2[MAX];
      char *f1, *f2;
      f1=&fuente1[0];
      f2=&fuente2[0];
      printf("%s","Ingrese la cadena para que este programa le devuelva ");
      printf("%s","como resultado la comparacion lexicograficamente de las cadenas\n");
     
      printf("%s","\n ingrese la primer cadena:\n");
       fgets(f1, MAX, stdin);
      printf("%s","\n ingrese la segunda cadena:\n");
       fgets(f2, MAX, stdin); 
     
     while(*(f2+i)==*(f1+i))
     {   if(*(f2+i)=='\0')
         { printf("%s", "las cadenas son iguales");
           return 1;
         }
         i++;
     }
             
     d=*(f2+i)-*(f1+i);
     if(d<0)      printf("%s", "la primer cadena es mayor que la segunda");
     else         printf("%s","la primer cadena es menor que la segunda");

     return 0;
   }
                           