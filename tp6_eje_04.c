#include <stdio.h>

#define LONG_CADENA 16
#define CANT_MUSICOS 2
#define CANT_DISCOS 2



typedef struct disco{
    char titulo[LONG_CADENA];
    int anio;
    int cant_canciones;

    
    /* data */
}t_d_disco;

/* Musico: {Nombre: “Músico 1”, 
            Edad: 35, Género: “Rock”, 
            Discos: {Titulo: “Disco 1”, Año: 2021, Canciones: 14}, 
            {Titulo: “Disco 2”, Año: 2006, Canciones: 8}} */

typedef struct musico{
    char nombre[LONG_CADENA];
    int edad;
    char genero[LONG_CADENA];
    t_d_disco discos[CANT_DISCOS];

    /* data */
}t_d_musico;



int main(void) {
    printf("Vamos a cargar los musicos\n");

    t_d_musico musicos[CANT_MUSICOS];
    char c;

    for(int i=0; i<CANT_MUSICOS;i++){
        printf("Nombre del musico:\t");
        fgets(musicos[i].nombre, LONG_CADENA, stdin);
        //while ((c = getchar()) != '\n' && c != EOF);

        
        printf("Edad del musico:\t");
        scanf("%d", &musicos[i].edad);
        while ((c = getchar()) != '\n' && c != EOF);
        
        printf("Genero:\t");
        fgets(musicos[i].genero, LONG_CADENA, stdin);
        //while ((c = getchar()) != '\n' && c != EOF);

        printf("Discos (Se cargan 3 poe ahora, luego lo hacemos dinamico):\t");
        printf("\nDiscos (Titulo\tAnio\tCantidad de canciones):\t");
        for(int j=0; j<CANT_DISCOS; j++){
            printf("\nTitulo:\t");

            fgets(musicos[i].discos[j].titulo, LONG_CADENA, stdin);
            //while ((c = getchar()) != '\n' && c != EOF);

            printf("Anio del disco:\t");
            scanf("%d", &musicos[i].discos[j].anio);
            while ((c = getchar()) != '\n' && c != EOF);

            printf("Cantidad de canciones:\t");
            scanf("%d", &musicos[i].discos[j].cant_canciones);
            //while ((c = getchar()) != '\n' && c != EOF);

        }
    }

    printf("Vamos a mostrar\n\n\n");
    for (int i = 0; i < CANT_DISCOS; i++){
        printf("Nombre del musico:\t%s\n", musicos[i].nombre);
        
        
        printf("\nEdad del musico:\t%d", musicos[i].edad);
        
        printf("\nGenero:\t%s", musicos[i].genero);
        
        printf("Discos (Titulo\tAnio\tCantidad de canciones):\t");
        


        for( int j=0; j< CANT_DISCOS; j++){
            printf("\nNombre del musico:\t%s", musicos[i].discos[j].titulo);

            printf("\nNombre del musico:\t%d", musicos[i].discos[j].anio);

            printf("\nNombre del musico:\t%d", musicos[i].discos[j].cant_canciones);



        }
        /* code */
    }
    
    return 0;
}