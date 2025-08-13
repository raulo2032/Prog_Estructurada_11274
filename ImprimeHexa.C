#include<stdio.h>

int main(void)
{ int c;
  

  for( c=0; c<128; c++)
  {
   printf("%d\t", c);
   printf("%x\t", c);
   printf("\n");
  }
   return 0;
}
