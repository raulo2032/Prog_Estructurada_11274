#include<stdio.h>
#include<stdlib.h>
#define CUOTA         50

char* readline(FILE *f);
char* strdup(char *s);

  int main(void)
  { char *str;
    int c;
    char aux[10000];
    gets(aux);

    while((c=getchar())!=EOF)
    {     str=readline(stdin);
          if(str==NULL) 
              fprintf(stderr,"Memoria insuficiente\n");
          else
              printf("%s%s\n", "Leido:\n\n", str);
              *aux=strdup(str);
              printf("%s\n", "La copia de lo leido con strdup es :\n");
              printf("%s", aux);
         
    }
    return 0;
 }  /* fin main  */

 char * readline(FILE *f)
 { int c;
   unsigned int alloc_size ;
   unsigned int used_size = 0 ;
   char *p, *q;
   if((p=(char*)malloc(sizeof(char)*CUOTA))==NULL)  return NULL;
   alloc_size=CUOTA;

   while((c=fgetc(f))!=EOF && c!='\n')
   {  if(used_size==alloc_size -1)
      { q=(char*)realloc(p, alloc_size+CUOTA);
        if(q==NULL){ free(p);
                     return NULL;   
                    }
      p=q;
      alloc_size+=CUOTA;
      } /* fin del realloc */
      p[used_size++]=c;
    }      /* fin del while  */
    p[used_size]='\0';
    return p;
  }  /* fin de readline() */

  char* strdup(char *s)
  {  char *p;
     unsigned int l;
     if(s==NULL)   return NULL;
     l=strlen(s);
     p=(char*)malloc((l+1)*sizeof(char));
     if(p==NULL)   return NULL;
     strcpy(p,s);
     return p;
   }