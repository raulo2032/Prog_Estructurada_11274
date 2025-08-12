   #include<stdio.h>
   #include<string.h>
   #include<stdlib.h>
   #define MAX_VOCALES            11  
   #define MAX_CONSONANTES        58
   #define MAX_PUNTUACION         5
   #define MAX_ASCII_EXTENDIDO    4
   #define MAX_SIMBOLOS           10   /*cant de caracteres que tiene un iso_8859_1*/
   #define MAX_DIGITOS            11
   #define DELIM_FIN_ISO          ';'  /*caracter que indica fin del simbolo iso   */
   #define DELIM_COMIENZO_ISO     '&'  /*caracter que indica comienzo del simbolo  */ 
   #define DELIM_HTML_IZQ         '<'  /*delimitador de html izquierdo             */ 
   #define DELIM_HTML_DER         '>'  /*delimitador de html derecho               */
   #define END_OF_FILE            "\nEl archivo estaba vacio.\n\n"
   #define CUOTA                  20
  
   typedef enum{VERDADERO, FALSO} t_estado;
  /*------------------------PROTOTIPOS DE FUNCIONES--------------------------------*/
   void salida(int h);
   void salida_mal(void);
 char* readline(FILE *f);
 /*-------------------------VARIABLES GLOBALES------------------------------------*/
   unsigned int n_vocal=0;               /*--contador de vocales-------------------*/
   unsigned int n_vocal_ac=0;            /*--contador de vocales acentuadas--------*/
   unsigned int n_vocal_dier=0;          /*--contador de vocales con dieresis------*/
   unsigned int n_consona=0;             /*--contador de consonantes---------------*/
   unsigned int n_puntua=0;              /*--contador de caracteres de puntuacion--*/
   unsigned int n_ascii_exten=0;         /*--contador de ascii extendidos----------*/
   unsigned int n_digitos=0;             /*--contador de digitos-------------------*/
   unsigned int cantidad_t=0;            /*--contador de cantidad total------------*/
 /*********************************************************************************/
  int main(void)
  { enum {ASCII, ISO_8859_1}tipo ;
  /*---------------------VARIABLES GENERALES AL PROGRAMA---------------------------*/
    int c;                           /*--caracteres que va a ir leyendo de a uno---*/
    unsigned int h=0;
    register int i, j=0;             /*--contadores de ciclos for y while----------*/
   /*-------------------DICCIONARIO DE VARIABLES A REGISTRAR------------------------*/
   char voca_natu[MAX_VOCALES]={"aeiouAEIOU"};
    char consona[MAX_CONSONANTES]={"bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ" }; 
    char digitos[MAX_DIGITOS]={"0123456789"};
    char puntuacion[MAX_PUNTUACION]={".,:;"};
    char *voc_acentu[MAX_VOCALES]={ "&aacute;","&eacute;","&iacute;","&oacute;",
                                    "&uacute;","&Aacute;","&Eacute;","&Iacute;",
                                    "&Oacute;","&Uacute;"};
    char *voc_diere[MAX_VOCALES]={  "&auml;","&euml;","&iuml;","&ouml;", "&uuml;",
                                    "&Auml;","&Euml;","&Iuml;","&Ouml;","&Uuml;" };
    char *ascii_ext[MAX_ASCII_EXTENDIDO]={ "&iquest;",
                                           "&iexcl;"   };
    char simbolo[MAX_SIMBOLOS];  
   int  r;
   char  *f;
 char *pcadena;
    char **pn;
    char **pindice;
    int tamanio;
    int tope;
    int x;

    t_estado descartar;    /*--defino un enumerativo para empezar descartando-----*/    
    descartar=FALSO;       /*--hasta que el caracter no este esntre delimitadores */
                           /*--HTML, para asi comenzar la clasificaion------------*/

  /********************************************************************************/
  /*----------------------------COMIENZO DEL PROGRAMA-----------------------------*/
   

  /*----------------------ETAPA DE ANALISIS PARA NO CONTAR------------------------*/
                                   
  f=readline(stdin);
     if(f==NULL)                  /* destruye todas las cadenas*/
      {  for(x=0; x<=tamanio; x++) /* y luego destruye el arreglo que contenia a */
         {  free(f[x]);          /* todos los punteros, poniendole un NULL*/
            f[x]=NULL;           /* en todas las posociones*/
         }
      }
      if(tope==tamanio-1)           /* me quede sin lugar para guardar el puntero*/
      {  pn=(char**)realloc(pindice, (tamanio+CUOTA)*sizeof(char*));
         if(pn==NULL){

                     }
         pindice=pn;
         tamanio+=CUOTA;
       }
   

    for(r=0; *f ; r++)
    
    {   if(descartar==FALSO && c==DELIM_HTML_IZQ)
        {    descartar=VERDADERO;               
             continue;
        }
        if(descartar==VERDADERO && c==DELIM_HTML_DER)
        {    descartar=FALSO;            /*--cuando entre en esta condicion,------*/      
             continue;                   /*--el descarte habra finalizado---------*/
        }                                /*--y entra a la etapa de comparar-------*/    
        if(descartar==VERDADERO)         /*              |                        */
             continue;                   /*              |                        */
                                         /*              |                        */
        /*            ___________________________________/                        */      
        /*           |                                                            */
        /*           |                                                            */
        /*          \ /                                                           */
        /*           V                                                            */

        if(c!=DELIM_COMIENZO_ISO)  
              tipo=ASCII;
        else
              tipo=ISO_8859_1;
                                   
        
        switch(tipo)
        {    case ASCII:
                       for(i=0; i<MAX_VOCALES; i++)
                           if(c==(voca_natu[i]))
                           {    h=n_vocal++;
                                break;
                                continue;
                           }
                       for(i=0;  i<MAX_CONSONANTES; i++)
                           if(c==(consona[i]))
                           {    h=n_consona++;
                                break;
                                continue;
                           }                           
                       for(i=0; i<MAX_DIGITOS; i++)
                           if(c==(digitos[i]))
                           {    h=n_digitos++;
                                break;
                                continue;
                           }                           
                       for(i=0; i<MAX_PUNTUACION; i++)
                           if(c==(puntuacion[i]))
                           {    h=n_puntua++;
                                break;
                           }                                      
                           break;

                       default: ;

             case ISO_8859_1:
                            j=0;
                            c=DELIM_COMIENZO_ISO;
                            while( c!=EOF && c!=DELIM_FIN_ISO)
                            {  simbolo[j++]=c;
                               c=getchar();
                               if( j>MAX_SIMBOLOS ){ salida_mal();
                                                      return 1;
                                                    }
                            }
                        
                            simbolo[j++]=DELIM_FIN_ISO;
                            simbolo[j]='\0';
             
                            for(i=0; i<MAX_VOCALES; i++)
                            {   if(!strcmp(simbolo,*(voc_acentu+i)) )
                                {   h=n_vocal_ac++;
                                    continue;
                                }
                                if(!strcmp(simbolo,*(voc_diere+i)) )                                                                                                                                                              
                                {   h=n_vocal_dier++;
                                    continue;
                                }
                            }
                            for(i=0; i<MAX_ASCII_EXTENDIDO; i++)
                                if(!strcmp(simbolo,*(ascii_ext+i)) )
                                    h=n_ascii_exten++;
                             
                            break;
                   
                       
        }  /*--salida for()-----*/       
    }      /*--salida del while()--*/  
           
    cantidad_t = n_consona + n_digitos + n_puntua + n_vocal+
                 n_vocal_ac + n_vocal_dier + n_ascii_exten;
 
    if(cantidad_t<=0){ printf(END_OF_FILE);
                       return 0;
                     }
    salida(h);
              
    return 0;
                                         
                                     
  }    /* FIN DEL PROGRAMA*/		                                  
  
  /*-----la funcion salida, muestra por pantalla la salida del programa -----*/
  /*-----en una ejecucion normal---------------------------------------------*/      
  
  
  void salida(int r)
  { 
    printf("\n%s%8.8d\n"," El total de caracteres leidos fue de:   ", cantidad_t);
    printf("\n%s%8d"," El total de vocales fue de:                      ", n_vocal);
    printf("%s%3.1f%s\n"," (", (n_vocal)*(100.0)/cantidad_t, " %)");
    printf("%s"," El total de vocales acentuadas fue de:           ");
    printf("%8d", n_vocal_ac);
    printf("%s%3.1f%s\n"," (",(n_vocal_ac)*(100.0)/cantidad_t, " %)");
    printf("%s"," El total de vocales con dieresis fue de:         ");
    printf("%8d", n_vocal_dier);
    printf("%s%3.1f%s\n"," (",(n_vocal_dier)*(100.0)/cantidad_t, " %)");
    printf("%s%8d"," El total de consonantes fue de:                  ", n_consona);
    printf("%s%3.1f%s\n"," (",(n_consona)*(100.0)/cantidad_t, " %)");
    printf("%s%8d"," El total de caracteres de puntuacion fue de:     ", n_puntua);
    printf("%s%3.1f%s\n", " (",(n_puntua)*(100.0)/cantidad_t, " %)");
    printf("%s"," El total de cartacteres ASCII extendidos fue de: ");                   
    printf("%8d", n_ascii_exten);
    printf("%s%3.1f%s\n", " (",(n_ascii_exten)*(100.0)/cantidad_t, " %)");
    printf("%s", " El total de digitos fue de:                      ");
    printf("%8d", n_digitos);
    printf("%s%3.1f%s\n", " (",(n_digitos)*(100.0)/cantidad_t, " %)");
    
  }

  /*------------------------la funcion salida_mal()--------------------------*/
  /*-------------muestra al usuario que el programa fue abosrtado------------*/
      
  void salida_mal(void)
  {  fprintf(stderr,"%s","\nEl programa ha sido abortado.\nSe encontro");
     fprintf(stderr,"%s"," con un simbolo mal formado.\nPodra ejecutar");
     fprintf(stderr, "%s", " nuevamente  el programa, solo si arregla dicho");
     fprintf(stderr, "%s", " simbolo.\n\n");
         
  }  
char* readline(FILE *f)
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
    }   /* fin del while  */
    p[used_size]='\0';
    return p;
  }  /* fin de readline() */
