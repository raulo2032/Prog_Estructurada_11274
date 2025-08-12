EJEMPLO: TECLADO MATRICIAL



#include <stdio.h>

#define	ERROR	0

/************************** FUNCTION PROTOTYPES**************************************/

void	GetTrueValue(char,char,char *);
char	ScanKeyboard(char *,char *);
char	GetKeyName(char,char);

/*	*********************************************************************************/



/*	********************************************************************************
	Esta funci�n simula la presi�n f�sica de una tecla del teclado matricial.
	Recibe como par�metros la variable "x" que representa en hexadecimal el n�mero
	de fila de la matriz, ie., del puerto de salida. La variable "MaskY" representa la columna
	que est� siendo le�da (va al puerto de entrada). De la combinaci�n de x, MaskY, y el estado
	de la tecla presionada, se devuelve el estado estimado de la tecla.
	****************************************************************************************/
void	GetTrueValue(char x,char MaskY,char *py)
{

	char estado;

	printf("%s%i%s%i%s","Ingrese el estado de la tecla cuyas coordenada hexadecimales son X=",x," Y=",MaskY,": ");
	estado=getchar();
	printf("\n");
	if((estado=='S')||(estado=='s')) *py=MaskY;	//si se presion� la tecla, codificar su valor
	else *py=0;
}

/*	**********************************************************************************	*/




/*	**********************************************************************************
	Esta funci�n barre secuencial y matricialmente todas y cada uno de los elementos del
	teclado, para detectar qu� tecla ha sido presionada.
	El registro de direcci�n pX alimenta las filas 4 del teclado, y el registro en pY
	contiene los valores le�dos para las 3 columnas. Con pX explora, con pY detecta.
	*********************************************************************************	*/
char	ScanKeyboard(char *px,char *py)
{
	char MaskY;

	if((px==NULL)||(py==NULL)) return ERROR;//protecci�n contra registros X e Y no inicializados

	*px=0x01;	//primera fila a explorar
	do			//while (*px)!=0x10		equivale a explorar hasta la 4� fila inclusive
	{
		MaskY=0x01;//primera columna
		do		//while (*py)!=0x04		equivale a explorar hasta la 3� columna inclusive
		{
			GetTrueValue(*px,MaskY,py);
			if((*py)&MaskY) return GetKeyName(*px,MaskY);
			MaskY=MaskY<<1;	//desplazamiento de bits hacia el m�s significativo de Y, salto de columna

		}while (MaskY!=0x08);
		(*px)=(*px)<<1;	//desplazamiento de bits hacia el m�s significativo de X, salto de fila
	}while((*px)!=0x10);
	return ERROR;		//si lleg� hasta aqu� es porque no se detect� ninguna tecla presionada
}

/*	*********************************************************************************	*/


/*	*********************************************************************************
	Esta funci�n decodifica el valor de la tecla presionada, a partir de su posici�n
	dentro del teclado matricial. Devuelve el caracter que aparece en el frente de la tecla.
	La variable "x" identifica a la fila (puerto de salida para exploraci�n).
	La variable "y" identifica a la columna (puerto de salida para detecci�n).
	*********************************************************************************	*/
char	GetKeyName(char x,char y)
{
	switch(x)
	{
		case 0x01:	switch(y)
				{
					case 0x01:	return '1';
					case 0x02:	return '2';
					case 0x04:	return '3';
				}
				break;
		case 0x02:	switch(y)
				{
					case 0x01:	return '4';
					case 0x02:	return '5';
					case 0x04:	return '6';
				}
				break;
		case 0x04:	switch(y)
				{
					case 0x01:	return '7';
					case 0x02:	return '8';
					case 0x04:	return '9';
				}
				break;
		case 0x08:	switch(y)
				{
					case 0x01:	return '*';
					case 0x02:	return '0';
					case 0x04:	return '#';
				}
	}
	return ERROR;	//si lleg� hasta aqu� es porque se ha producido un error
}
/*	******************************************************************************	*/





int main()
{
	char OutputPort;	//esta variable simula el puerto de salida del �C
	char InputPort;		//esta variable simula el puerto de entrada del �C
	char PressedKey;	//tecla presionada


	if(PressedKey=ScanKeyboard(&OutputPort,&InputPort)) printf("%s%c\n","Resultado: Tecla ",PressedKey);
	else printf("%s\n","Resultado: No se ha presionado ninguna tecla.");
	return 0;
} 
