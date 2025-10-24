#include <stdio.h>

#include <string.h>

 

#define LONGTEXTO 32

 

typedef struct regCliente

{

	int codigo ;

	char nombre[LONGTEXTO];

	float saldo ;

}regCliente;

 

int menu(void);

void ingreseEntero(const char * , int *);

void ingreseTexto(const char * , char *);

void ingreseFlotante(const char * , float *);

 

void agregarRegistro(regCliente *);

int buscarRegistro(int, regCliente *);

void leerArchivo(void);
int main(void)

{

    int opcion ;

    while((opcion = menu()))

    {

    	switch(opcion)

    	{

    		case 1 :

    			     {

    			     	regCliente reg;

    			     	ingreseEntero("Ingrese codigo (0 sale) ",&reg.codigo);

    			     	while(reg.codigo)

    			     	{

	                      ingreseTexto("Ingrese nombre ",reg.nombre);

	                      ingreseFlotante("Ingrese saldo ",&reg.saldo);

	                     // printf(" %d %s %.2f",reg.codigo,reg.nombre,reg.saldo);

						  agregarRegistro(&reg);

    			     	  ingreseEntero("Ingrese codigo (0 sale) ",&reg.codigo);

    			        }

						 break;

					 }
case 2 :

    			     {

    			     	regCliente reg;

    			     	ingreseEntero("Ingrese codigo (0 sale) ",&reg.codigo);

    			     	int pos = buscarRegistro(reg.codigo , &reg);

	                    if (pos >= 0) 

                          		    printf(" posicion %d [%d %s %.2f]\n",pos , reg.codigo,reg.nombre,reg.saldo);

                        else

                          		    printf(" NO EXISTE o ERROR fread\n");

                     	break ;

					}

			case 3 :

                    leerArchivo(); 

				    break;

		}

	}

	return 0 ;

}

void agregarRegistro(regCliente * reg)

{

    //abrir archivo

    FILE * fd = fopen("clientes","ab");

    if (fd != NULL)

    {

    	int err = fwrite(reg,sizeof(regCliente),1,fd);

    	printf(" err %d \n",err);

    	fclose(fd);

	}

	else

	   printf("ERROR fopen\n");

}

int buscarRegistro(int codigo, regCliente * reg)

{

    //abrir archivo

    FILE * fd = fopen("clientes","rb");

    int pos = -1 ;

    if (fd != NULL)

    {

    	int err;

    	while((err=fread(reg,sizeof(regCliente),1,fd)) > 0 && reg->codigo != codigo);

    	if (err > 0 && reg->codigo == codigo)

    	     pos = ftell(fd) - sizeof(regCliente);

    	fclose(fd);

	}

	return pos ;   

}
void leerArchivo(void)

{

    //abrir archivo

    FILE * fd = fopen("clientes","rb");

    if (fd != NULL)

    {

    	regCliente reg ;

    	while(fread(&reg,sizeof(reg),1,fd) )

    		    printf(" [%d %s %.2f]\n",reg.codigo,reg.nombre,reg.saldo);

		fclose(fd);

	}

	else

	   printf("ERROR fopen\n");

}

void ingreseEntero(const char * etiqueta, int * dato)

{

	printf("[%s]: ",etiqueta);

	scanf("%d",dato);

	fflush(stdin);

}

 

void ingreseTexto(const char * etiqueta, char * dato)

{

	printf("[%s]: ",etiqueta);

	fgets(dato,LONGTEXTO,stdin);

	dato[strlen(dato)-1]='\0';

	fflush(stdin);

}

 

void ingreseFlotante(const char * etiqueta, float * dato)

{

	printf("[%s]: ",etiqueta);

	scanf("%f",dato);

	fflush(stdin);

}

int menu(void)

{

	printf(" MENU DE OPCIONES \n");

	printf(" 1) agregar registros \n");

	printf(" 2) buscar registros \n");

	printf(" 3) mostrar todos los registros \n");

	printf(" 0) salir \n");

    int opcion;

	ingreseEntero("Ingrese opcion ",&opcion);

	return opcion;

}