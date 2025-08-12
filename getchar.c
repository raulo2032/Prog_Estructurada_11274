/*******devuelve la cadena ingresada en mauyusculas****************/


#include<stdio.h>
  int main(void)
  {
    int c;
    c = getchar();                 /*  1* version    */
                                     /* pag 17*/
    while (c!= EOF)
    { putchar(c);               
      c = getchar();
    }
    return 0;
    }







