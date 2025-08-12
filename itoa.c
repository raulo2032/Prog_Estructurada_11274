 /***************************pag 70*********************************/

                                 /* itoa : convirte n a caracteres en s  */
# include <stdio.h>

void itoa(int n, char s[])
 { int i, sing;
   if ((sing = n) < 0 )   /* regostra el signo  */
       n = -n;              /* vuelve a n positivo */
   i = 0;
   do {       /*genera digitos en orden inverso*/
        s[i++] = n % 10 + '0' ; /* tona el,siguiente digito*/
       }   while ((n /= 10) > 0);   /*borralo*/
             if (sing < 0 )
                s[i++] = '-';
             s[i] = '\0';
             reverse(s);
  }                
            

  
