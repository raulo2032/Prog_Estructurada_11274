/* 
     Algoritmos y Programación I - 75.02 - Curso Lic. Adriana Echeverría
     Material de clase
     Archivo:     ejemplo51.c
     Descripcion: Formateo de impresion de cadenas con punteros a funciones
     Contenidos:  PUNTEROS A FUNCIONES + HTML
     Comentarios:
     Este programa ilustra el uso de punteros a funciones para llevar a cabo 
     una impresion de contenidos de un array de cadenas. La funcion "principal"
     es la que se encarga de volcar los contenidos del array, i.e. "ImprimirContenidos()",
     pero notar que ImprimirContenidos() NO SABE como se imprimen FISICAMENTE 
     los contenidos, sino que solo a su vez los manda a imprimir de acuerdo 
     al formato que le hayan pasado a ella, a traves del puntero a funcion.
     Esta funcion "imprime", pero el trabajo fino lo hace otro...
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX	100

/* =========================== PROTOTIPOS ======================== */
void ImprimirContenidos(char *[],int,void (*)(char *));
void FmtMayuscula(char *);
void FmtMinuscula(char *);
void FmtHTML(char *);
/* =============================================================== */

int main(void)
{
   char *Textos[MAX]={"Hola mundo","HP-UX 12.0","Compaq Proliant 5500"};
   int  MaxTexto=2;
/* Estos son los contenidos a imprimir */



   ImprimirContenidos(Textos,MaxTexto,FmtMayuscula);
   /* Manda a imprimir los Textos: se encarga de manejar los contenidos, 
   no de COMO hacer la impresion FISICA */

   /* Otras invocaciones validas serian:
	   ImprimirContenidos(Textos,MaxTexto,FmtMinuscula);
   	   ImprimirContenidos(Textos,MaxTexto,FmtHTML);
   */
   return 0;
}

/* Esta funcion imprime los textos contenidos en un array de cadenas, "v",
   que contiene "tope" cadenas, de acuerdo a la forma de imprimir que
   tenga una funcion (pasada como argumento) a traves de un puntero a la misma.
*/
void ImprimirContenidos(char *v[],int tope,void (*pf)(char *))
{
   int i;

   for(i=0;i<=tope;i++) (*pf)(v[i]);
}


/* Realiza la impresion de una cadena de caracteres como Linea en mayusculas */
void FmtMayuscula(char *p)
{
   while((*p)!='\0'){
      printf("%c",toupper(*p));
      p++;
   }
   printf("\n"); 
}


/* Realiza la impresion de una cadena de caracteres como Linea en minusculas */
void FmtMinuscula(char *p)
{
   while((*p)!='\0'){
      printf("%c",tolower(*p));
      p++;
   }
   printf("\n");
}



/* Realiza la impresion de una cadena de caracteres como Linea en formato HTML,
   como "negrita" y "cursiva". Notar que el caracter de fin de linea para HTML
   debe lograrse con el tag <br>, no con el \n tradicional de C.
*/
void FmtHTML(char *p)
{
   printf("%s","<b><i>");
   for(;(*p)!='\0';p++) printf("%c",*p);
   printf("%s","</i></b><br>\n");
}















