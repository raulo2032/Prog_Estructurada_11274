 /***************************pag 70*********************************/

                                 /* itoa : convirte n a caracteres en s  */
# include <stdio.h>

main ( ) 
{
void itoa(int n, char s[])
 { int i, sing;
    if ((sing = n) < 0 )   /* registra el signo  */
         n = -n;              /* vuelve a n positivo */
    i = 0;
     do {       /*genera digitos en orden inverso*/
            s[i++] = n % 10 + '0' ; /* tona el,siguiente digito*/
           }   while ((n /= 10) > 0);   /*borralo*/
                     if (sing < 0 )
                        s[i++] = '-';
                     s[i] = '\0';
                     reverse ( s );
  }                
            
  /* reverse :  invierte la cadena s en el mismo lugar */

void reverse(char s[])
 {  int c, i, j;
    for ( i=0 , j = strlen (s) - 1 ; i<j ;  i++,  j-- )
   {  c = s[i];
      s[i] = s[j] ;
      s[j] = c ;
   }
return (s);  }

}

  
