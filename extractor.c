/*Programa por CLA para obtener un determinado campo de un archivo CSV, y guardarlo en uno nuevo*/
/*Autor: Ivan Perez*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARGUMENTS_NUMBER	3
#define DELIMITTER			','
#define CHOP				32

typedef enum{ERROR, OK}		tstatus;
typedef enum{FALSE, TRUE}	boolean;
typedef enum{NORMAL, ERROR_INVOCACION, ERROR_LECTURA, ERROR_ESCRITURA, CAMPO_INVALIDO, CAMPO_NO_POSITIVO, CARACTER_INVALIDO}	terrortype;

/*prototipos*/
tstatus validate_arguments(int, char**);
int convert_arguments(char*);
FILE *open_file_r(char*);
FILE *open_file_w(char*);
tstatus print_fields(FILE *, FILE *, int);
/*prototipos*/

int main(int argc, char *argv[]){
	
	FILE *input;
	FILE *output;
		
	int fieldchoose;
	
	terrortype errortype = NORMAL;
	boolean evaluate = TRUE;
	
	
	/*validate arguments*/
	if((errortype = validate_arguments(argc, argv))!= NORMAL) evaluate = FALSE;
	/*convert arguments*/
	if((fieldchoose = convert_arguments(argv[2])) && evaluate == TRUE){
		errortype = CAMPO_NO_POSITIVO;
		evaluate = FALSE;
	}
	/*open archive*/
	if(((input = open_file_r(argv[1])) == NULL) && evaluate == TRUE){
		errortype = ERROR_LECTURA;
		evaluate = FALSE;
	}
	if(((output = open_file_w(argv[3])) == NULL) && evaluate == TRUE){
		errortype = ERROR_ESCRITURA;
		evaluate = FALSE;
	}
		
	/*print_fields*/
	if((print_fields(input, output, fieldchoose) == ERROR) && evaluate == TRUE)	errortype = ERROR_ESCRITURA;
	
	/*close archive*/
	if((fclose(input)== EOF) && evaluate == TRUE) errortype = ERROR_ESCRITURA;
	if((fclose(output)==EOF) && evaluate == TRUE) errortype = ERROR_ESCRITURA;
	
		
	switch(errortype){
		case NORMAL:				printf("%s", "La operacion se realizo exitosamente.");
			return EXIT_SUCCESS;
		case ERROR_INVOCACION:		printf("%s", "Uso del programa: extractor.exe <archivo de entrada> <numero de campo> <archivo de salida>");
			return EXIT_SUCCESS;
		case ERROR_LECTURA:			fprintf(stderr, "%s%s", "ERROR: Hubo un problema al intentar abir el archivo: ",argv[1]);
			return EXIT_FAILURE;
		case ERROR_ESCRITURA:		fprintf(stderr, "%s%s", "ERROR: Hubo un problema al intentar guardar en el archivo: ", argv[3]);
			return EXIT_FAILURE;
		case CARACTER_INVALIDO:		fprintf(stderr, "%s", "Caracter invalido");
			return EXIT_FAILURE;
		case CAMPO_INVALIDO:		fprintf(stderr, "%s", "Numero de campo invalido");
			return EXIT_FAILURE;
		case CAMPO_NO_POSITIVO:		fprintf(stderr, "%s", "Error en el numero de campo elegido");
			return EXIT_SUCCESS;
	}
	return EXIT_SUCCESS;
}/*end main*/


terrortype validate_arguments(int a, char **s){
	unsigned int i=0;
	if(a!= ARGUMENTS_NUMBER + 1) return ERROR_INVOCACION;
	for(i=0; i<strlen(s[1]); i++) if(isalpha(s[1][i]) && ispunct(s[1][i])) return CARACTER_INVALIDO;
	for(i=0; i<strlen(s[2]); i++) if(isdigit(s[2][i])) return CAMPO_INVALIDO; 		/*creo que aca la estoy pifeando*/
	for(i=0; i<strlen(s[3]); i++) if(isalpha(s[3][i]) && ispunct(s[1][i])) return CARACTER_INVALIDO;
	return NORMAL;
}

int convert_arguments(char *s){				/*algo funciona mal con esta funcion, que ironia*/
	int option;
	if((option = atoi(s))<= 0) return 0;	/*la funcion devuelve 0 si el campo elegido es <0*/
	else return option;						/*de lo contrario devuelve el campo :-)*/
}
/*tengo ganas de complicarme*/
FILE *open_file_r(char *s){
	return fopen(s, "rt");
}
FILE *open_file_w(char *s){
	return fopen(s, "wt");
}

tstatus print_fields(FILE *in, FILE *out, int option){
	int i=1;
	boolean leer;
	int c;	
		
	while((c = fgetc(in))!= EOF){
		
		leer = TRUE;
		
		if(c == DELIMITTER){
			i++; 			/*incremento el campo*/
			c = fgetc(in);	/*leo el siguiente, que sera un espacio*/
			leer = FALSE;	/*pero no se tendra en cuenta :-)*/
		}
		if(i != option && c!='\n' && leer == TRUE) leer = FALSE;
		
		if(leer == TRUE) if((fprintf(out, "%c", c))<0) return ERROR;
				
		if(c == '\n'){
			if((fprintf(out, "%c", c))<0) return ERROR;	/*paso a la linea siguiente*/
			i=1;										/*reset de campo*/
		}
	}	/*end while*/
	
	return OK;
}