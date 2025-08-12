/*	Divide & Conquer
	Ordena de menor a mayor utilizando Merge-Sort*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* CANTIDAD debe ser un numero tal que : 2^k = CANTIDAD */
#define CANTIDAD 16

void Ordenar(int *, int);
int *Array_Crear(int, int *, int);
void Array_Destruir(int *);
void Array_Print(int *, int , char *);

int main(int argc, char *argv[])
{
	int v[CANTIDAD], i;

	/* Inicializo la tabla de numeros aleatorios */
	srand(time(NULL));

	/* Creo un vector con numeros aleatorios entre 0-255 */
	for(i=0; i<CANTIDAD; i++) {
		v[i] = rand()%256;
	}

	Array_Print(v, CANTIDAD, "Array");
	
	Ordenar(v, CANTIDAD);

	Array_Print(v, CANTIDAD, "Array Ordenado");
	
	return EXIT_SUCCESS;
}

/*
   v = vector donde buscar
   p = posicion del primer elemento
   u = posicion del ultimo elemento
*/
void Ordenar(int *v, int largo)
{
	int medio, i, off1, off2, *tmp1, *tmp2;

	/* Tomo como caso base tener 1 elemento */
	if (largo == 1) {
		return;
	} else {
		/* Calculo la posicion central del subvector */
		medio = largo / 2;

		/* Creo 2 vectores auxiliares */
		tmp1 = Array_Crear(medio, v, 0);
		tmp2 = Array_Crear(medio, v, medio);

		/* Ordeno en forma recursiva cada subvector */
		Ordenar(tmp1, medio);
		Ordenar(tmp2, medio);
		
		/* Mezclo ambos vectores sobre v */
		off1 = off2 = 0;
		for(i=0; (off1<medio) && (off2<medio); i++) {
			if (tmp1[off1] < tmp2[off2]) {
				v[i] = tmp1[off1];
				off1++;
			} else {
				v[i] = tmp2[off2];
				off2++;
			}
		}
		
		/* Ahora debo copiar el restante de alguno de los vectores
		   auxiliares. Solo se ejecutara un for, ya que para uno de
		   los vectores ya tendre todos los elementos copiados
		*/
		for( ; off1<medio; i++, off1++)
			v[i] = tmp1[off1];
			
		for( ; off2<medio; i++, off2++)
			v[i] = tmp2[off2];
		
		/* Elimino los vectores auxiliares */
		Array_Destruir(tmp1);
		Array_Destruir(tmp2);
	}
}

/* Crea un nuevo array y copia de origen la posicion desde */
int *Array_Crear(int largo, int *origen, int desde)
{
	int *tmp, i;
	
	/* Creo el nuevo array */
	tmp = calloc(largo, sizeof(int));
	
	/* Copio los valores */
	for(i=0; i<largo; i++)
		tmp[i] = origen[desde+i];
	
	/* Magic :-) */
	return tmp;
}

void Array_Destruir(int *v)
{
	free(v);
}

void Array_Print(int *v, int largo, char *s)
{
	int i;
	printf("%s = {", s);
	for(i=0; i<largo; i++) {
		printf("%d", v[i]);
		/* Mientras no sea el ultimo elemento imprimo una "," */
		if (i<CANTIDAD-1)
			printf(",");
	}
	printf("}\n");
}

