/*

  Ejemplo de Listas Simplemente Enlazadas
	
	Autor : Ricardo Markiewicz
	
	Version : 1.0.0
	
	ChangeLog : 
	
	24-06-2002 - Inicio

*/

#include <stdio.h>
#include <stdlib.h>


/* estructuras */
typedef struct _agenda_ {
	char name[30];
	char tel[15];
	unsigned int edad;
} t_Agenda;

typedef t_Agenda t_Lst_Dato;

typedef struct _l_nodo_ {
	t_Lst_Dato *dato;
	struct _l_nodo_ *next;
} t_Lst_Nodo, *t_Lst;

typedef enum {LST_ERROR, LST_OK} t_Lst_Control;

/* Protoripos de listas */
t_Lst_Control Lst_Vacia(t_Lst);
t_Lst_Control Lst_Crear(t_Lst *);
t_Lst_Control Lst_Crear_Nodo(t_Lst_Nodo **, t_Lst_Dato *);
t_Lst_Control Lst_Insertar(t_Lst *, t_Lst_Dato *);
t_Lst_Control Lst_Aniadir(t_Lst *, t_Lst_Dato *);
t_Lst_Control Lst_Insertar_Despues(t_Lst *, t_Lst_Nodo *, t_Lst_Dato *);
t_Lst_Control Lst_Insertar_Antes(t_Lst *, t_Lst_Nodo *, t_Lst_Dato *);
t_Lst_Control Lst_Eliminar_Primero(t_Lst *, t_Lst_Dato **);
void Lst_Destruir(t_Lst *);
void Lst_Imprimir(t_Lst, void (*imprimir)(t_Lst_Dato *));
unsigned int Lst_Cantidad(t_Lst);

/* prototipos de datos */
int Ingresar_Dato(t_Lst_Dato **);
void imp_nombre(t_Lst_Dato *);

int main(int argc, char *argv[])
{
	t_Lst lista;
	int i=0;

	/* Inicio la lista */
	Lst_Crear(&lista);
	/* Ingreso 3 datos */
	while (i<4) {
		t_Lst_Dato *d;
		Ingresar_Dato(&d);
		Lst_Aniadir(&lista, d);
		Lst_Imprimir(lista, imp_nombre);
		i++;
	}
	/* Destruyo la lista */
	Lst_Destruir(&lista);

	return 0;
}

void imp_nombre(t_Lst_Dato *d)
{
	if (d == NULL)
		printf("NULL\n");
	else
		printf("%s (%d) -> ", d->name, d->edad);
}

t_Lst_Control Lst_Crear(t_Lst *l)
{
	(*l) = NULL;
	return LST_OK;
}

t_Lst_Control Lst_Vacia(t_Lst l)
{
	return (l == NULL);
}

t_Lst_Control Lst_Crear_Nodo(t_Lst_Nodo **n, t_Lst_Dato *d)
{
	t_Lst_Nodo *tmp;

	tmp = (t_Lst_Nodo *)malloc(sizeof(t_Lst_Nodo));
	if (tmp == NULL) return LST_ERROR;

	tmp->dato = d;
	tmp->next = NULL;
	(*n) = tmp;
	return LST_OK;
}

/* Agrega un nodo al principi */
t_Lst_Control Lst_Insertar(t_Lst *l, t_Lst_Dato *d)
{
	t_Lst_Nodo *n;

	/* creo el nuevo nodo */
	if (Lst_Crear_Nodo(&n, d) == LST_ERROR) return LST_ERROR;

	/* Enlazo al lista */
	if (Lst_Vacia(*l) == LST_OK)
		(*l) = n;
	else {
		n->next = *l;
		(*l) = n;
	}

	return LST_OK;
}

/* Agrega un nodo al final */
t_Lst_Control Lst_Aniadir(t_Lst *l, t_Lst_Dato *d)
{
	t_Lst_Nodo *n, *ultimo;

	/* creo el nuevo nodo */
	if (Lst_Crear_Nodo(&n, d) == LST_ERROR) return LST_ERROR;

	/* Enlazo al lista */
	if (Lst_Vacia(*l) == LST_OK)
		(*l) = n;
	else {
		/* busco el ultimo nodo */
		for(ultimo=(*l); ultimo->next != NULL; ultimo=ultimo->next) {}
		ultimo->next = n;
	}

	return LST_OK;
}

t_Lst_Control Lst_Insertar_Despues(t_Lst *l, t_Lst_Nodo *despues, t_Lst_Dato *d)
{
	t_Lst_Nodo *n;

	if (despues == NULL) return LST_ERROR;

	/* creo el nuevo nodo */
	if (Lst_Crear_Nodo(&n, d) == LST_ERROR) return LST_ERROR;

	/* Enlazo al lista */
	n->next = despues->next;
	despues->next = n;

	return LST_OK;
}

t_Lst_Control Lst_Insertar_Antes(t_Lst *l, t_Lst_Nodo *antes, t_Lst_Dato *d)
{
	t_Lst_Nodo *n, *padre;

	if (antes == NULL) return LST_ERROR;

	/* creo el nuevo nodo */
	if (Lst_Crear_Nodo(&n, d) == LST_ERROR) return LST_ERROR;

	/* Enlazo al lista */
	/* busco el padre de antes */
	for(padre=(*l); padre->next != antes; padre=padre->next) {}

	padre->next = n;
	n->next = antes;

	return LST_OK;
}

void Lst_Imprimir(t_Lst l, void (*imprimir)(t_Lst_Dato *))
{
	if (l == NULL) {
		imprimir(NULL);
		return;
	}

	imprimir(l->dato);
	Lst_Imprimir(l->next, imprimir);
}

unsigned int Lst_Cantidad(t_Lst l)
{
	t_Lst_Nodo *tmp;
	unsigned int count=0;

	for(tmp=l; tmp != NULL; tmp=tmp->next) count++;

	return count;
}

/* Elimina el primer nodo y devuelve el dato por n */
t_Lst_Control Lst_Eliminar_Primero(t_Lst *l, t_Lst_Dato **n)
{
	t_Lst_Nodo *tmp;

	if (Lst_Vacia(*l) == LST_OK) return LST_ERROR;

	tmp = (*l);
	(*l) = (*l)->next;
	(*n) = tmp->dato;
	free(tmp);

	return LST_OK;
}

void Lst_Destruir(t_Lst *l)
{
	t_Lst_Dato *d;
	while (Lst_Eliminar_Primero(l, &d) != LST_ERROR) free(d);

	Lst_Crear(l);
}

int Ingresar_Dato(t_Lst_Dato **d)
{
	t_Lst_Dato *tmp;

	tmp = malloc(sizeof(t_Lst_Dato));
	if (tmp == NULL) return 1;

	printf("Ingrese Nombre : ");
	scanf("%s", tmp->name);
	printf("Ingrese Telefono : ");
	scanf("%s", tmp->tel);
	printf("Ingrese Edad : ");
	scanf("%d", &(tmp->edad));
	(*d) = tmp;
	return 0;
}
