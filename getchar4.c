/* lee la linea y la copia abajo*/


#include<stdio.h>
#include<ctype.h>
  int main (void)
  { int c;
   for(c = getchar( ); c!= EOF; c = getchar())
        putchar(toupper(c));
  return 0;
  }