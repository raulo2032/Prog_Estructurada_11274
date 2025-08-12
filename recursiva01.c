/***ver esto con la funcion que me dice el tiempo de ejecucion   */

#include <stdio.h>
void print(char* s);    /*funcion recursiva para invertir una cadena */
void reverse(char *);   /* funcion que recive una cadena como parametro
                           y la devuelve alreves*/
int main(void){

	char *cadena="anita lava la tina";
	printf("%s%s%s", "Esta es la cadena original\n\t",
	             cadena,
	             "\n\nEsta es la cadena invertida con una funcion recursiva\n\t");
    print(cadena);
    reverse(cadena);
	printf("%s%s", "\nY esta esta invertida con la funcion reverse\n\t",
		           cadena);
	return 0;
}


void print(char *s){
	if(*s)
		print(s+1);
	printf("%c", *s);
}


 void reverse(char * prueba){
	 int j, k, c;
	 for(k=0, j=strlen(prueba)-1; k<j; k++, j--){
		 c=prueba[k];
		 prueba[k]=prueba[j];
		 prueba[j]=c;
		 }
	 return;
	 }
