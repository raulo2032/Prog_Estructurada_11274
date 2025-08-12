/*****esta anda bien con  las opciones*******/

#include<stdio.h>
#define CELCIUS_OPT 'c'
#define FAHR_OPT    'f'


 typedef enum{celcius, fahrenheit}tescala;
 typedef float tdato;

 int main(void)
 {  tdato valor;
    tescala escala;

    printf("%s", "temperatura a convertir?  ");
    scanf("%f", &valor);    getchar();        /****limpia el buffer*****/
    printf("%s", "unidad de destino (c/f):  ");
    switch(getchar())
    {   case CELCIUS_OPT: escala=celcius;	
                                              break;
        case FAHR_OPT: escala=fahrenheit;
       	                                      break;
	   
        default:
	            printf("%s", " ERROR");
                    return 1;
     }
     printf("%s%2.2f","\nla temperatura ingresada fue ", valor);
     switch(escala)
     {   case celcius: escala=celcius;	
                           printf("%s"," grados celcius");                                                                                                  break;
        case fahrenheit: escala=fahrenheit;
       	                   printf("%s"," grados fahrenheit");
                           break;
     }
     printf("%s","\n\ny es igual a ");
     switch(escala)
     {   case celcius: valor=(float) 5/9*(valor-32);
	               printf("%2.2f%s\n\n", valor , " grados celcius");
                                    	       break;
         case fahrenheit: valor=32+(float)9/5*valor;
                       printf("%2.2f%s\n\n",valor," grados fahrenheit"); 
                                               break;
         default: 
                      return 0;
       }
      return 0;
   }
