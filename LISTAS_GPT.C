#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ==== Tipos base ==== */
typedef void *puntero_generico;
typedef char *string;

typedef enum { ERROR = 0, OK = 1 } status;

/* ==== Estructura de nodo y lista ==== */
typedef struct nodo {
    puntero_generico punt_dato;
    struct nodo *sig;
} nodo, *lista;

/* ==== Prototipos ==== */
status crear_lista(lista *pl);
lista crear_lista2(void);
status crear_nodo_lista(lista *pl, puntero_generico dato);
bool lista_vacia(lista L);
void liberar_nodo(lista *pl);
puntero_generico destruir_nodo(lista *pl);
status insertar_principio(lista *pl, puntero_generico dato);
status insertar_al_final(lista *pl, puntero_generico dato);
void recorrer_lista(lista L, void (*pf)(puntero_generico));
status destruir_lista(lista *pl, void (*pf)(puntero_generico));
nodo *buscar(lista L, string target);

/* ==== Implementaciones ==== */

/* Inicializa una lista vacía (constructor "in situ") */
status crear_lista(lista *pl) {
    *pl = NULL;
    return OK;
}

/* Crea una lista vacía y la devuelve (constructor que retorna valor) */
lista crear_lista2(void) {
    lista milista = NULL;
    return milista;
}

/* Crea un nodo con dato genérico */
status crear_nodo_lista(lista *pl, puntero_generico dato) {
    lista L = (lista) malloc(sizeof(nodo));
    if (L == NULL) return ERROR;

    *pl = L;
    L->punt_dato = dato;
    L->sig = NULL;
    return OK;
}

/* Verifica si la lista está vacía */
bool lista_vacia(lista L) {
    return (L == NULL);
}

/* Libera un nodo (sin liberar el dato) */
void liberar_nodo(lista *pl) {
    free(*pl);
    *pl = NULL;
}

/* Libera un nodo y devuelve el dato almacenado */
puntero_generico destruir_nodo(lista *pl) {
    puntero_generico dato = (*pl)->punt_dato;
    liberar_nodo(pl);
    return dato;
}

/* Inserta un dato al inicio */
status insertar_principio(lista *pl, puntero_generico dato) {
    lista L;
    if (crear_nodo_lista(&L, dato) == ERROR)
        return ERROR;
    L->sig = *pl;
    *pl = L;
    return OK;
}

/* Inserta un dato al final */
status insertar_al_final(lista *pl, puntero_generico dato) {
    lista L, temp;
    if (crear_nodo_lista(&L, dato) == ERROR) return ERROR;

    if (lista_vacia(*pl)) {
        *pl = L;
    } else {
        for (temp = *pl; temp->sig != NULL; temp = temp->sig);
        temp->sig = L;
    }
    return OK;
}

/* Recorre la lista y aplica una función a cada dato */
void recorrer_lista(lista L, void (*pf)(puntero_generico)) {
    while (L != NULL) {
        (*pf)(L->punt_dato);
        L = L->sig;
    }
}

/* Destruye toda la lista, aplicando función opcional a los datos */
status destruir_lista(lista *pl, void (*pf)(puntero_generico)) {
    if (!lista_vacia(*pl)) {
        destruir_lista(&((*pl)->sig), pf);
        if (pf != NULL)
            (*pf)((*pl)->punt_dato);
        liberar_nodo(pl);
    }
    return OK;
}

/* Busca un nodo cuyo dato->nombre coincida (supone dato como struct con "nombre") */
nodo *buscar(lista L, string target) {
    while (L != NULL) {
        /* Aquí asumimos que punt_dato apunta a struct con char* nombre */
        struct { string nombre; } *dato = L->punt_dato;
        if (dato != NULL && dato->nombre != NULL && strcmp(target, dato->nombre) == 0)
            return L;
        L = L->sig;
    }
    return NULL;
}

/* ==== Funciones de ejemplo ==== */
void mostrar_string(puntero_generico d) {
    printf("%s\n", (char *) d);
}

/* ==== Main de prueba ==== */
int main(void) {
    lista L = crear_lista2();

    insertar_al_final(&L, "Uno");
    insertar_al_final(&L, "Dos");
    insertar_principio(&L, "Cero");

    printf("Recorrido:\n");
    recorrer_lista(L, mostrar_string);

    destruir_lista(&L, NULL);
    return 0;
}
