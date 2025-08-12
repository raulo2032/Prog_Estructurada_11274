#include <stdio.h>
#include <stdlib.h>
 
int swap (int , int);  /* ESTE ES EL PROTOTIPO */
int main (void)

{  int a , b;
   printf("%s\n\n", "Ojo, este programa pasa por valor los datos, y estoy implementando mal la funcion,pero anda igual, notar eso, no usar el defecto de esta funcion, usar como el programa invierte2.exe ");
   printf("%s", "Ingrese un valor de a : ");
   scanf("%i",&a);
   printf("%s", "Ingrese un valor de b : ");
   scanf("%i",&b);
  
   printf("%s%i\n", "Nuevo valor de a : ", swap(a,b) );
   printf("%s%i\n", "Nuevo valor de b : ", swap(b,a) );
 
return EXIT_SUCCESS;
}
 

int swap (int x , int y)   /* ACA EMPIEZA LA FUNCION */
{
  int aux;
  aux = x;
  x = y;
  y = aux;
  
  return x ;
  return y ;
 
} /* ACA TERMINE DE ESCRIBIR LA FUNCION */