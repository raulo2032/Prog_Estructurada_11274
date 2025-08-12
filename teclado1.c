EJEMPLO: TECLADO MATRICIAL



#include <stdio.h>

#define	ERROR	0

/************************** FUNCTION PROTOTYPES**************************************/

void	GetTrueValue(char,char,char *);
char	ScanKeyboard(char *,char *);
char	GetKeyName(char,char);

/*	*********************************************************************************/



/*	********************************************************************************
	Esta función simula la presión física de una tecla del teclado matricial.
	Recibe como parámetros la variable "x" que representa en hexadecimal el número
	de fila de la matriz, ie., del puerto de salida. La variable "MaskY" representa la columna
	que está siendo leída (va al puerto de entrada). De la combinación de x, MaskY, y el estado
	de la tecla presionada, se devuelve el estado estimado de la tecla.
	****************************************************************************************/
void	GetTrueValue(char x,char MaskY,char *py)
{

	char estado;

	printf("%s%i%s%i%s","Ingrese el estado de la tecla cuyas coordenada hexadecimales son X=",x," Y=",MaskY,": ");
	estado=getchar();
	printf("\n");
	if((estado=='S')||(estado=='s')) *py=MaskY;	//si se presionó la tecla, codificar su valor
	else *py=0;
}

/*	**********************************************************************************	*/




/*	**********************************************************************************
	Esta función barre secuencial y matricialmente todas y cada uno de los elementos del
	teclado, para detectar qué tecla ha sido presionada.
	El registro de dirección pX alimenta las filas 4 del teclado, y el registro en pY
	contiene los valores leídos para las 3 columnas. Con pX explora, con pY detecta.
	*********************************************************************************	*/
char	ScanKeyboard(char *px,char *py)
{
	char MaskY;

	if((px==NULL)||(py==NULL)) return ERROR;//protección contra registros X e Y no inicializados

	*px=0x01;	//primera fila a explorar
	do			//while (*px)!=0x10		equivale a explorar hasta la 4º fila inclusive
	{
		MaskY=0x01;//primera columna
		do		//while (*py)!=0x04		equivale a explorar hasta la 3º columna inclusive
		{
			GetTrueValue(*px,MaskY,py);
			if((*py)&MaskY) return GetKeyName(*px,MaskY);
			MaskY=MaskY<<1;	//desplazamiento de bits hacia el más significativo de Y, salto de columna

		}while (MaskY!=0x08);
		(*px)=(*px)<<1;	//desplazamiento de bits hacia el más significativo de X, salto de fila
	}while((*px)!=0x10);
	return ERROR;		//si llegó hasta aquí es porque no se detectó ninguna tecla presionada
}

/*	*********************************************************************************	*/


/*	*********************************************************************************
	Esta función decodifica el valor de la tecla presionada, a partir de su posición
	dentro del teclado matricial. Devuelve el caracter que aparece en el frente de la tecla.
	La variable "x" identifica a la fila (puerto de salida para exploración).
	La variable "y" identifica a la columna (puerto de salida para detección).
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
	return ERROR;	//si llegó hasta aquí es porque se ha producido un error
}
/*	******************************************************************************	*/





int main()
{
	char OutputPort;	//esta variable simula el puerto de salida del µC
	char InputPort;		//esta variable simula el puerto de entrada del µC
	char PressedKey;	//tecla presionada


	if(PressedKey=ScanKeyboard(&OutputPort,&InputPort)) printf("%s%c\n","Resultado: Tecla ",PressedKey);
	else printf("%s\n","Resultado: No se ha presionado ninguna tecla.");
	return 0;
} 
