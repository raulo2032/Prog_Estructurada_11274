#include <stdio.h>
#include <stdlib.h>  // rand(), srand()
#include <time.h>    // time()

#define LINEA printf("-----------------\n")

// Prototipo: recibe un vector de enteros, longitud, min, max
void carga_vector(int v[], int N, int menor, int mayor);

int main(void) {
    int largo_vec, min, max;

    // Semilla para generar números aleatorios distintos en cada ejecución
    srand(time(NULL));

    printf("Ingrese la longitud del vector:\n");
    scanf("%d", &largo_vec);
    while (getchar() != '\n' && getchar() != EOF); // limpiar buffer

    int vector[largo_vec];  // ahora que sabemos el tamaño, lo declaramos

    printf("Ingrese el limite inferior del vector:\n");
    scanf("%d", &min);
    while (getchar() != '\n' && getchar() != EOF);

    printf("Ingrese el limite superior del vector:\n");
    scanf("%d", &max);
    while (getchar() != '\n' && getchar() != EOF);

    // Cargar el vector con números aleatorios
    carga_vector(vector, largo_vec, min, max);

    // Mostrar resultados formateados
    LINEA;
    printf("Vector generado:\n[");
    for (int i = 0; i < largo_vec; i++) {
        printf("%d", vector[i]);
        if (i < largo_vec - 1) printf(", ");
    }
    printf("]\n");
    LINEA;

    return 0;
}

// Función que carga el vector con números aleatorios en [menor, mayor]
void carga_vector(int v[], int N, int menor, int mayor) {
    for (int i = 0; i < N; i++) {
        v[i] = menor + rand() % (mayor - menor + 1);
    }
}
