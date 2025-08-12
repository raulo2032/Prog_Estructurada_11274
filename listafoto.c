#include<stdio.h>
#include<stdlib.h>
typedef int tipodato;

typedef struct nodo{
	tipodato dato;
	struct nodo *sig;
}nodo, *lista;

typedef enum{OK, ERROR}estado;

typedef enum{FALSE, TRUE}bool;

estado crear_lista(lista *pl);
bool   lista_vacia(lista L);
estado crear_nodo(nodo **p, tipodato dato);
estado insertar_principio(lista *pl, tipodato dato);
estado buscar_nodo(lista *pl, tipodato dato, nodo **paborrar);
estado eliminar_nodo( lista *pl, lista aborrar);
void liberar_nodo(lista *pn);

int main(void){
	printf(" la connnnn de tu maaa.... ");
	return 0;
}


estado crear_lista(lista *pl){
	*pl=NULL;
	return OK;
}


bool   lista_vacia(lista L){
	return(L==NULL) ? TRUE : FALSE;
}


estado crear_nodo(nodo **p, tipodato dato){
	nodo *aux;
	if( (aux=(nodo*)malloc(sizeof(nodo))) == NULL) return ERROR;
	*p=aux;
	aux->dato=dato;
	return OK;
}


estado insertar_principio(lista *pl, tipodato dato){
	nodo *nuevo_nodo;
	if(crear_nodo(&nuevo_nodo, dato)==ERROR)  return ERROR;
	nuevo_nodo -> sig = *pl;
	*pl = nuevo_nodo;
	return OK;
}



estado buscar_nodo(lista *pl, tipodato dato, nodo **paborrar){
	lista Laux;
	if(lista_vacia(*pl)==TRUE) return ERROR;
	if((*pl) -> dato == dato )
		*paborrar = *pl;
	else{
		for(Laux=*pl; Laux != NULL && Laux ->dato != dato; Laux = Laux -> sig)
			;
		if(Laux==NULL) return ERROR;
		*paborrar = Laux;
	}
	return OK;
}

estado eliminar_nodo( lista *pl, lista aborrar){
	lista Laux;
	if(lista_vacia(*pl)) return ERROR;
	if(*pl==aborrar)
		*pl = (*pl) -> sig;
	else{
		for(Laux=*pl; Laux != NULL && Laux ->sig != aborrar; Laux = Laux -> sig)
			;
		if(Laux==NULL)
			return ERROR;
		else
			Laux -> sig = aborrar -> sig;
	}
	liberar_nodo(&aborrar);
	return OK;
}


void liberar_nodo(lista *pn){
	free(*pn);
	*pn=NULL;
}

