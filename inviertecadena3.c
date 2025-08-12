#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100
void reverse(char *);
int l, i, j, k, c;

int main(){
	 char prueba[MAX];
	 printf("%s%s%s\n","este prueba imprimir la cadena ingresada por teclado",
	                    " luego la imprime en \nmayusculas, y finalmente, ",
						"la imprime invertida");
	 fgets(prueba, MAX, stdin);  
     printf("%s\n%s", "la cedana original es:", prueba);
     printf("%s\n", "la cadena en mayusculas es:");
     for(i=0; i<MAX; i++)
		 if(prueba[i]!='\0')
		 putchar(toupper(prueba[i]));
	 prueba[strlen(prueba)-1]='\0';
	 l=strlen(prueba);
	 printf("%s%d\n%s", "la longitud de la cadena util es igual a ", l,
		                "y la cadena alreves es:\n");
     reverse(prueba);
     printf("%s", prueba);

	 return 0;
 }

 void reverse(char * prueba){
	 for(k=0, j=strlen(prueba)-1; k<j; k++, j--){
		 c=prueba[k];
		 prueba[k]=prueba[j];
		 prueba[j]=c;
		 }
	 return;
	 }
