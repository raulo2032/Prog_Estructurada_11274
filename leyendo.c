#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

#define  MAX_CLA          10
#define  MAX_STR_CLA      3
#define  MAX_STR          256
#define  ANCHO_CAMPO      7
#define  COMILLAS         '"'
#define  COMA             ','

/*-----------------------declaracion de typedefs-----------------------------*/

typedef char string[MAX_STR];
typedef enum{OK, MAL}t_estado;
typedef enum{OFF, ON}t_argumento;

float*   leer_datos(FILE* p, int *max);

float cadena_entrada[MAX_STR];
float *entrada=&cadena_entrada[0];


int main( int argc, char *argv[]){

	float *entrada;
	int max_elem=0, i;
	
    entrada=leer_datos(stdin, &max_elem);
	for(i=0; i<max_elem; i++)
		printf("%3.3f\n", entrada[i]); /* ver el campo del numero */


	return 0;
  }

  float* leer_datos(FILE* p, int *max){
	  float i;
	  int k, c;
	  char cadena[MAX_STR],*temporal;
      
	  p=stdin;
	  c=getchar();
	  for(k=0; c!=EOF; k++){
		  ungetc(c, stdin);
		  fgets(cadena,ANCHO_CAMPO , stdin);
		  i=strtod(cadena, &temporal);
		  cadena_entrada[k]=i;
		  c=getchar();

	  }
	  *max=k;
	  return cadena_entrada;
  }
