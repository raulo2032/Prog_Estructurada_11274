


#include<stdio.h>
#include<string.h>
#define MAX 100

 int toupper();
 int reverse(char s[]);


 int main(){
	 int l, i, j, k, c;
     char prueba[MAX];
	 char cadenaal[MAX];
	 printf("%s\n","este prueba imprimir la cadena ingresada por teclado:");
	 printf("%s\n","Y luego la imprime en mayusculas");
	 fgets(prueba, MAX, stdin);  
     printf("%s\n%s", "la cedana original es:", prueba);
     printf("%s\n", "la cadena en mayusculas es:");
     for(i=0; i<MAX; i++)
		 if(prueba[i]!='\0')
		 putchar(toupper(prueba[i]));
	 prueba[strlen(prueba)-1]='\0';
	 l=strlen(prueba);
	 printf("%s%d\n", "la longitud de la cadena util es igual a ", l);
     printf("%s\n", "y la cadena alreves es:");
     strcpy(cadenaal, prueba);

	 for(k=0, j=strlen(cadenaal)-1; k<j; k++, j--){
		 c=cadenaal[k];
		 cadenaal[k]=cadenaal[j];
		 cadenaal[j]=c;
	 }
	 printf("%s", cadenaal);
	 
	 return 0;
	 }

