#include<stdio.h>
#include<string.h>
#define MAX   100

int main(void)
{  unsigned char ascii[MAX]={ 'á', 'ñ'};
   char *iso[MAX]={"&aacute;","&ntilde;"};
   char cadena[MAX];
   char c;
   int i=0, j;

   while((c=getchar())!=EOF)
   {   cadena[i]=c;
       if(c!='\0')
       for(j=0; j<MAX; j++)
       { if(cadena[i]==ascii[j])
          printf("%s", iso[j]);
          break;
       }
       if(j==MAX)
          printf("%c", cadena[i]);
          i++;
   }
   return 0;

}