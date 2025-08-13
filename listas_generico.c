#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ==== Tipos base ==== */
typedef void *puntero_generico;

typedef enum { ERROR = 0, OK = 1 } status;

/* ==== Nodo y lista ==== */
typedef struct nodo {
    puntero_generico dato;
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
nodo *buscar(lista L, void *target, int (*cmp)(puntero_generico, void*));

/* ==== Implementaciones ==== */

/* Crea una lista vacía */
status crear_lista(lista *pl) {
    *pl = NULL;
    return OK;
}

/* Constructor que devuelve lista vacía */
lista crear_lista2(void) {
    return NULL;
}

/* Crea nodo con dato genérico */
status crear_nodo_lista(lista *pl, puntero_generico dato) {
    lista L = (lista) malloc(sizeof(nodo));
    if (!L) return ERROR;
    L->dato = dato;
    L->sig = NULL;
    *pl = L;
    return OK;
}

/* ¿Está vacía? */
bool lista_vacia(lista L) {
    return (L == NULL);
}

/* Libera nodo (no libera dato) */
void liberar_nodo(lista *pl) {
    free(*pl);
    *pl = NULL;
}

/* Libera nodo y devuelve su dato */
puntero_generico destruir_nodo(lista *pl) {
    puntero_generico d = (*pl)->dato;
    liberar_nodo(pl);
    return d;
}

/* Inserta al principio */
status insertar_principio(lista *pl, puntero_generico dato) {
    lista L;
    if (crear_nodo_lista(&L, dato) == ERROR)
        return ERROR;
    L->sig = *pl;
    *pl = L;
    return OK;
}

/* Inserta al final */
status insertar_al_final(lista *pl, puntero_generico dato) {
    lista L, temp;
    if (crear_nodo_lista(&L, dato) == ERROR) return ERROR;
    if (lista_vacia(*pl)) {
        *pl = L;
    } else {
        for (temp = *pl; temp->sig; temp = temp->sig);
        temp->sig = L;
    }
    return OK;
}

/* Recorre y aplica función */
void recorrer_lista(lista L, void (*pf)(puntero_generico)) {
    while (L) {
        pf(L->dato);
        L = L->sig;
    }
}

/* Destruye lista, aplicando función de liberación opcional */
status destruir_lista(lista *pl, void (*pf)(puntero_generico)) {
    while (!lista_vacia(*pl)) {
        puntero_generico d = destruir_nodo(pl);
        if (pf) pf(d);
        *pl = (*pl)->sig; // mover puntero
    }
    return OK;
}

/* Busca usando función de comparación */
nodo *buscar(lista L, void *target, int (*cmp)(puntero_generico, void*)) {
    while (L) {
        if (cmp(L->dato, target) == 0) {
            return L;
        }
        L = L->sig;
    }
    return NULL;
}

/* ==== Ejemplo de uso con struct ==== */
typedef struct {
    char nombre[30];
    int edad;
} Persona;

/* Función para imprimir Persona */
void mostrar_persona(puntero_generico d) {
    Persona *p = (Persona *) d;
    printf("%s (%d años)\n", p->nombre, p->edad);
}

/* Función para liberar Persona */
void liberar_persona(puntero_generico d) {
    free(d);
}

/* Función de comparación por nombre */
int cmp_persona_nombre(puntero_generico d, void *target) {
    Persona *p = (Persona *) d;
    char *nombre = (char *) target;
    return strcmp(p->nombre, nombre);
}

/* ==== Main de prueba ==== */
int main(void) {
    lista L = crear_lista2();

    /* Crear personas dinámicamente */
    Persona *p1 = malloc(sizeof(Persona));
    strcpy(p1->nombre, "Ana");
    p1->edad = 25;

    Persona *p2 = malloc(sizeof(Persona));
    strcpy(p2->nombre, "Luis");
    p2->edad = 30;

    Persona *p3 = malloc(sizeof(Persona));
    strcpy(p3->nombre, "Marta");
    p3->edad = 28;

    insertar_al_final(&L, p1);
    insertar_al_final(&L, p2);
    insertar_principio(&L, p3);

    printf("Lista:\n");
    recorrer_lista(L, mostrar_persona);

    /* Buscar persona */
    nodo *n = buscar(L, "Luis", cmp_persona_nombre);
    if (n) {
        Persona *encontrada = n->dato;
        printf("Encontrado: %s (%d años)\n", encontrada->nombre, encontrada->edad);
    }

    /* Liberar todo */
    destruir_lista(&L, liberar_persona);

    return 0;
}
