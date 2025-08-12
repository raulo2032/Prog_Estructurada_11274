/* lee la linea y la copia abajo*/


#include<stdio.h>
#include<ctype.h>
  int main(void)
  { int c;
    c = getchar( );
    while ( c != EOF)
    { putchar(c);
      c = getchar();
    }
  return 0;
  }