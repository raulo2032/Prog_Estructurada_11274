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
status insertar_principio(lista *pl, puntero_generico dato);
status insertar_al_final(lista *pl, puntero_generico dato);
status insertar_en_posicion(lista *pl, puntero_generico dato, int pos);
status eliminar_por_dato(lista *pl, void *target, int (*cmp)(puntero_generico, void*), void (*liberar)(puntero_generico));
void recorrer_lista(lista L, void (*pf)(puntero_generico));
int contar_lista(lista L);
status destruir_lista(lista *pl, void (*pf)(puntero_generico));
void ordenar_lista(lista *pl, int (*cmp)(puntero_generico, puntero_generico));

nodo *buscar(lista L, void *target, int (*cmp)(puntero_generico, void*));

/* ==== Implementaciones ==== */

status crear_lista(lista *pl) {
    *pl = NULL;
    return OK;
}

lista crear_lista2(void) {
    return NULL;
}

status crear_nodo_lista(lista *pl, puntero_generico dato) {
    lista L = (lista) malloc(sizeof(nodo));
    if (!L) return ERROR;
    L->dato = dato;
    L->sig = NULL;
    *pl = L;
    return OK;
}

bool lista_vacia(lista L) {
    return (L == NULL);
}

status insertar_principio(lista *pl, puntero_generico dato) {
    lista L;
    if (crear_nodo_lista(&L, dato) == ERROR)
        return ERROR;
    L->sig = *pl;
    *pl = L;
    return OK;
}

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

status insertar_en_posicion(lista *pl, puntero_generico dato, int pos) {
    if (pos < 0) return ERROR;
    if (pos == 0) return insertar_principio(pl, dato);

    lista temp = *pl;
    for (int i = 0; temp && i < pos-1; i++)
        temp = temp->sig;

    if (!temp) return ERROR; // posición fuera de rango

    lista nuevo;
    if (crear_nodo_lista(&nuevo, dato) == ERROR) return ERROR;

    nuevo->sig = temp->sig;
    temp->sig = nuevo;
    return OK;
}

status eliminar_por_dato(lista *pl, void *target, int (*cmp)(puntero_generico, void*), void (*liberar)(puntero_generico)) {
    lista temp = *pl, prev = NULL;

    while (temp) {
        if (cmp(temp->dato, target) == 0) {
            if (prev) prev->sig = temp->sig;
            else *pl = temp->sig;

            if (liberar) liberar(temp->dato);
            free(temp);
            return OK;
        }
        prev = temp;
        temp = temp->sig;
    }
    return ERROR; // no encontrado
}

void recorrer_lista(lista L, void (*pf)(puntero_generico)) {
    while (L) {
        pf(L->dato);
        L = L->sig;
    }
}

int contar_lista(lista L) {
    int contador = 0;
    while (L) {
        contador++;
        L = L->sig;
    }
    return contador;
}

status destruir_lista(lista *pl, void (*pf)(puntero_generico)) {
    while (!lista_vacia(*pl)) {
        lista temp = *pl;
        puntero_generico d = temp->dato;
        *pl = temp->sig;
        if (pf) pf(d);
        free(temp);
    }
    return OK;
}

nodo *buscar(lista L, void *target, int (*cmp)(puntero_generico, void*)) {
    while (L) {
        if (cmp(L->dato, target) == 0)
            return L;
        L = L->sig;
    }
    return NULL;
}

void ordenar_lista(lista *pl, int (*cmp)(puntero_generico, puntero_generico)) {
    if (!*pl || !(*pl)->sig) return;

    bool cambiado;
    do {
        cambiado = false;
        lista prev = NULL, curr = *pl;
        while (curr->sig) {
            if (cmp(curr->dato, curr->sig->dato) > 0) {
                lista sig = curr->sig;
                curr->sig = sig->sig;
                sig->sig = curr;
                if (prev) prev->sig = sig;
                else *pl = sig;
                prev = sig;
                cambiado = true;
            } else {
                prev = curr;
                curr = curr->sig;
            }
        }
    } while (cambiado);
}

/* ==== Ejemplo de uso con struct ==== */
typedef struct {
    char nombre[30];
    int edad;
} Persona;

void mostrar_persona(puntero_generico d) {
    Persona *p = (Persona *) d;
    printf("%s (%d años)\n", p->nombre, p->edad);
}

void liberar_persona(puntero_generico d) {
    free(d);
}

int cmp_persona_nombre(puntero_generico d, void *target) {
    Persona *p = (Persona *) d;
    char *nombre = (char *) target;
    return strcmp(p->nombre, nombre);
}

int cmp_persona_nombre_ordenar(puntero_generico d1, puntero_generico d2) {
    Persona *p1 = (Persona *) d1;
    Persona *p2 = (Persona *) d2;
    return strcmp(p1->nombre, p2->nombre);
}

/* ==== Main de prueba ==== */
int main(void) {
    lista L = crear_lista2();

    Persona *p1 = malloc(sizeof(Persona)); strcpy(p1->nombre, "Ana"); p1->edad = 25;
    Persona *p2 = malloc(sizeof(Persona)); strcpy(p2->nombre, "Luis"); p2->edad = 30;
    Persona *p3 = malloc(sizeof(Persona)); strcpy(p3->nombre, "Marta"); p3->edad = 28;

    insertar_al_final(&L, p1);
    insertar_al_final(&L, p2);
    insertar_principio(&L, p3);

    printf("Lista original:\n");
    recorrer_lista(L, mostrar_persona);

    printf("\nInsertar en posición 1:\n");
    Persona *p4 = malloc(sizeof(Persona)); strcpy(p4->nombre, "Carlos"); p4->edad = 22;
    insertar_en_posicion(&L, p4, 1);
    recorrer_lista(L, mostrar_persona);

    printf("\nEliminar por nombre 'Luis':\n");
    eliminar_por_dato(&L, "Luis", cmp_persona_nombre, liberar_persona);
    recorrer_lista(L, mostrar_persona);

    printf("\nContar elementos: %d\n", contar_lista(L));

    printf("\nOrdenar lista por nombre:\n");
    ordenar_lista(&L, cmp_persona_nombre_ordenar);
    recorrer_lista(L, mostrar_persona);

    destruir_lista(&L, liberar_persona);
    return 0;
}
