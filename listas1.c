/*		implementacion de listas simples		*/

#include <stdio.h>


typedef void *puntero_generico;
typedef struct{
	puntero_generico punt_dato;
	struct nodo *sig;
}nodo, *lista;

enum{ ERROR, OK} status;
enum{ TRUE< FALSE} bool;

status crear_lista(lista *pl);
int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}

status crear_lista(lista *pl){
	*pl=NULL;                                 /*produce un puntero apuntando a NULL */
	return OK;
}

/* la implementacion en el main seria*/

int main(void){                               
	lista L;                                  /* esta crea la lista insitu    */
	crear_lista(&L);
}
/*-------------------------------------------------*/

lista crear_lista2(void){                    /* este no devuelve NULL, devuelve */
	lista=milista=NULL;                      /* una lista vacia                 */
	return milista;
}

/* la implementascion en e main seria*/

int main(void){
	lista L;                                 /* crea la lista y me la devuelve             */
	L=crear_lista2();                        /* es mas parecido al concepto sintactico del */
}                                            /* constrcutor                                */


/* como segunda primitiva, podemos crear un nodo lista   */

status crear_nodo_lista(lista *pl, puntero_generico dato){
	lista L=(lista)malloc(sizeof(nodo));
	if(L==NULL)    return ERROR;

	*pl=L;
	L->punt_dato=dato;
	L->sig=NULL;
	return OK;
}

/* como tercera primitiva, ver si la lista esta vacia o no */

bool lista_vacia(lista L){
	return (L==NULL) ? TRUE : FALSE;
}

/* como cuarta primitiva, destruri un nodo de la lista */

void liberar_nodo(lista *pl){
	free(*pl);
	*pl=NULL;
}

/* otra primitiva puede ser destruir nodo  */

puntero_generico destruir_nodo(lista *pl){
	puntero_generico dato;
	dato=(*pl)->dato;
	liberar_nodo(pl);
	return dato;
}

/* insertar principio */

status insertar_principio(lista *pl, puntero_generico dato){
	lista L;
	if(crear_nodo_lista(&L, dato)==ERROR)
		return ERROR;	/* no es tarea de la primitiva el poner printf(), OK???  */
	L->sig=*pl;
	*pl=L
	
	return OK;
}

/* para insertar al final de la lsita     */

status insertar_al_final(lista *pl, puntero_generico dato){
	lista L, temp;
	if(crear_nodo_lista(&L, dato)==ERROR)	return ERROR;

	if(lista_vacia(*pl)==TRUE) *pl=L;

	else{
		for(temp=*pl; temp->sig != NULL; temp=temp->sig);
		temp->sig=NULL;
	}
	return OK;
}



/* para recorrer una lista    */

void recorrer_lista)lista L, void(*pf)(puntero_generico)({
	while(L!=NULL)
		(*pf)(L->dato);

	L=L->sig;
}

/* una funcion para mostrar el dato*/

void m1(puntero_generico d1){
	printf("%s\n", d1->id);                        /* suponiendo id un miembro de la estuctura*/
}

/* para destruir una lista     */

status destruir_lista(lista *pl, void(*pf)(puntero_generico)){
	if(lista_vacia(*pl)==FALSE){
		destruir_lista(&(*pl->sig), pf);
		if(pf!=NULL)	(*pf)(*pl->dato);

		liberar_nodo(pl);
	}
	return OK;
}


void liberar nodo(lista *pl){
	free(*pl);
	*pl=NULL;
}

nodo* buscar(lista L, string target){
	while(L!=NULL){
		if(!strcmp(target, L->dato->nombre))	return L;

		L=L->sig;    
		retunr NULL;
	}
}

/* otra forma de resolverlo seria con una funcion del tipo

    nodo* lista(lista L, int(*pf)(  ),   )           */