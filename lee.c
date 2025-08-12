#include<stdio.h>
#include<stdlib.h>
#define CUOTA 50

char * readline(FILE *f);

  int main(void)
  {  char *str;
     printf("%s","Ingrese la cadena a leer:\n");
     str=readline(stdin);
     if(str==NULL) 
             fprintf(stderr,"Memoria insuficiente\n");
     else 
             printf("%s%s\n", "Leido:\n\n", str);

     free(str);
     printf("%s", "\nEl programa finalizo ok");
     return 0;
   }      /* main */
/*-----------------------------------------------------*/
 char * readline(FILE *f)
 { int c;
   unsigned int alloc_size;
   unsigned int used_size=0;
   char *p, *q;
   if((p=(char*)malloc(sizeof(char)*CUOTA))==NULL)  return NULL;
   
   alloc_size=CUOTA;

   while((c=fgetc(f))!=EOF && c!='\n')
   {  if(used_size==alloc_size -1)
      { q=(char*)realloc(p, alloc_size+CUOTA);
        if(q==NULL)
        { free(p);
          return NULL;
        }
      p=q;
      alloc_size+=CUOTA;
      } /* fin del realloc*/
      p[used_size++]=c;
    }      /* fin del while  */
    p[used_size]='\0';
    return p;
  }  /* fin de readline() */