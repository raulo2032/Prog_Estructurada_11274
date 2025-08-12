/*		implementacion de listas simples		*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENTOS 256

typedef enum{ ERROR, OK} status;
typedef enum{ TRUE, FALSE} bool;
typedef char string[MAX_ELEMENTOS];

typedef void *puntero_generico;
typedef struct{
	puntero_generico punt_dato;
	struct nodo *sig;
	string nombre;
	int id;
}nodo, *lista;

status crear_lista(lista *pl);
lista crear_lista2(void);
status crear_nodo_lista(lista *pl, puntero_generico dato);
bool lista_vacia(lista L);
void liberar_nodo(lista *pl);
puntero_generico destruir_nodo(lista *pl);
status insertar_principio(lista *pl, puntero_generico dato);
status insertar_al_final(lista *pl, puntero_generico dato);
void recorrer_lista(lista L, void(*pf)(puntero_generico));
void m1(puntero_generico d1);
status destruir_lista(lista *pl, void(*pf)(puntero_generico));

int main(void){                               
	lista L, L2;                 /* esta crea la lista insitu    */
	crear_lista(&L);
	L2=crear_lista2();          /* crea la lista y me la devuelve             */
    return 1;                  /* constrcutor                                */  
}	                       /* es mas parecido al concepto sintactico del */

status crear_lista(lista *pl){
	*pl=NULL;  
	return OK;
}



lista crear_lista2(void){           /* este no devuelve NULL, devuelve */
	lista milista=NULL;             /* una lista vacia                 */
	return milista;
}


status crear_nodo_lista(lista *pl, puntero_generico dato){
	lista L=(lista)malloc(sizeof(nodo));
	if(L==NULL)    return ERROR;

	*pl=L;
	L->punt_dato=dato;
	L->sig=NULL;
	return OK;
}


bool lista_vacia(lista L){
	return (L==NULL) ? TRUE : FALSE;
}


void liberar_nodo(lista *pl){
	free(*pl);
	*pl=NULL;
}

puntero_generico destruir_nodo(lista *pl){
	puntero_generico dato;
	dato=(*pl)->punt_dato;     /* ak cambie punt_dato por dato */
	liberar_nodo(pl);
	return dato;
}





status insertar_principio(lista *pl, puntero_generico dato){
	lista L;
	if(crear_nodo_lista(&L, dato)==ERROR)
		return ERROR;/* no es tarea de la primitiva el poner printf(), OK???  */
	L->sig=*pl;            /*  L->sig=*pl; eto era asi*/
	*pl=L;
	
	return OK;
}


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


void recorrer_lista(lista L, void(*pf)(puntero_generico)){
	while(L!=NULL)
		(*pf)(L->punt_dato);      /*  punt_dato en vez de dato??*/

	L=L->sig;
}


  void m1(puntero_generico d1){
	printf("%s\n", d1->id);       /* suponiendo id un miembro de la estuctura*/
}     

status destruir_lista(lista *pl, void(*pf)(puntero_generico)){
	if(lista_vacia(*pl)==FALSE){
		destruir_lista(&(pl->sig), pf);
		if(pf!=NULL)	(*pf)(*pl->punt_dato);

		liberar_nodo(pl);
	}
	return OK;
}

nodo* buscar(lista L, string target){
	while(L != NULL){
		if(!strcmp(target, L->punt_dato->nombre))	return L;

		L=L->sig;    
	}
	return NULL;
}
