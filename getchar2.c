/* conteo de lineas pero mas compacto, ( con c=get.. dentro del while*/

#include<stdio.h>
#include<ctype.h>
  int main(void)
  { int c;
    while((c=getchar()) != EOF)
      putchar(c);
  return 0;
  }