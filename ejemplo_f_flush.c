#include <stdio.h>

#define MAX_STR 50

int main() {
    char nombre_vec[MAX_STR];
    int largo_vec, min, max;
    int c; // para limpiar el buffer

    printf("Ingrese el nombre del vector: ");
    scanf("%49s", nombre_vec);

    // limpiar el buffer de stdin (descartar hasta \n o EOF)
    while ((c = getchar()) != '\n' && c != EOF);

    printf("El nombre ingresado es: %s\n", nombre_vec);

    return 0;
}
