#include <stdio.h>
#include <string.h>

#define MAX_CHAR 30
#define N 5

struct paciente {
    char nombre[MAX_CHAR];
    float peso;
    int edad;
};

int main() {
    struct paciente nomina;
    FILE *f;
    
    printf("Ingrese los datos de maximo %d pacientes:\n", N);
    /* Escritura */
    f = fopen("nomina.dat", "wb");
    if (f == NULL) {
        printf("Error abriendo archivo escritura\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("\n--- Paciente %d ---\n", i + 1);
        printf("Ingrese Nombre: ");
        
        if (fgets(nomina.nombre, MAX_CHAR, stdin) == NULL) {
            printf("Error leyendo el nombre.\n");
            break;
        }

        // Quitar salto de línea
        size_t len = strlen(nomina.nombre);
        if (len > 0 && nomina.nombre[len - 1] == '\n') {
            nomina.nombre[len - 1] = '\0';
        }

        printf("Ingrese peso: ");
        if (scanf("%f", &nomina.peso) != 1) {
            printf("Error: Entrada de peso inválida.\n");
            return 1;
        }

        printf("Ingrese edad: ");
        if (scanf("%d", &nomina.edad) != 1) {
            printf("Error: Entrada de edad inválida.\n");
            return 1;
        }

        // Limpiar buffer de entrada de forma segura
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        fwrite(&nomina, sizeof(nomina), 1, f);
    }
    fclose(f);

    /* Lectura */
    f = fopen("nomina.dat", "rb");
    if (f == NULL) {
        printf("Error abriendo archivo lectura\n");
        return 1;
    }

    printf("\n=== Datos Guardados ===\n");
    printf("%-20s\t%-10s\t%s\n", "Nombre", "Peso", "Edad");
    printf("----------------------------------------\n");

    while (fread(&nomina, sizeof(nomina), 1, f) == 1) {
        printf("%-20s\t%-10.2f\t%d\n", nomina.nombre, nomina.peso, nomina.edad);
    }

    fclose(f);
    return 0;
}
