/* intercambia mediante la burbuja cadenas*/

#include <stdio.h>
#include<string.h>
typedef char string[256];
typedef enum{TRUE, FALSE}bool;
void swap_str(string*, string*);
void burbuja_string(string *v, int n);

int main(void){
	int i;
	string vector[]={"las vida","asdfasdf","pasdtfha","aaaasdsfgdf"};
	for(i=0; i<4; i++)
		printf("\t%s\n", vector[i]);
	printf("\n\n");
	burbuja_string(vector, 4);
	for(i=0; i<4; i++)
		printf("\t%s\n", vector[i]);
	
	return 0;
}
void burbuja_string(string *v, int n){
	int i, j;
	bool flag;
	for(i=0; i<n; i++){
		flag=FALSE;
		for(j=0; j<n-1; j++){
			if(strcmp(v[i], v[j])<0){
				swap_str(&v[i], &v[j]);
				flag=TRUE;
			}
		}
		if(flag==FALSE)
			return;
	}
}
 void swap_str(string *x , string *y){
	 string aux;
	 strcpy(aux, *x);
	 strcpy(*x , *y);
	 strcpy(*y, aux);
 }