#include<stdio.h>

  unsigned int d factroial(int a);

  int main(void)
 { int a;
   
   printf("Este programa le permite calcular el factorial de un numero\n");
   printf( "ingrese numero:");
   factorial(a);

   return 0;
  }

   unsigned int d factroial(int a)
   { int i;
     scanf("%i", &d)
      while(d<0)
        fprintf(stderr, "%s", "Error, numero invalido para el calculo");
      if(d=0)  
      {  a=1;
         return a;
      }
      else
         a=1;
         for(i=2; i<=a; i++)
               d=d*i;
         a=d;
         return a; 
         
    }