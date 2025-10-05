/*  Escriba una función tal que retorne en un puntero ptr la fila donde se encuentra el valor máximo de una matriz 
    de enteros de NxM. Utilice este retorno para imprimir, en otra función, la fila completa.
*/

/*  En una matriz se almacenan los siguientes datos referidos a una población de 2000 personas: 
    P(sexo, estadocivil, edad) donde: sexo puede tomar los valores 1 ó 2 (masculino ó femenino); 
    estadocivil puede tomar los valores de 1 a 3 (soltero, casado, viudo); 
    edad un valor entre 1 y 70.  
    Generar una función que cargue el arreglo anterior con datos al azar, 
    respetando los dominios de cada grupo. 
    Escribir una función que reciba como argumentos dicha matriz, un sexo, estado civil, y edad, 
    y retorne el número de personas que se encuentren en esas condiciones. 
*/

# include<time.h>
# include<stdlib.h>
# include<stdio.h>

#define FILAS   5
#define COLS    5 

void llenar_matriz(int matriz[FILAS][COLS]);
void mostrar_matriz(int matriz[FILAS][COLS]);
int* buscar_mayor(int matriz[FILAS][COLS]);

int main(void){
    int matriz [FILAS][COLS]={};
    srand(time(NULL));
    llenar_matriz(matriz);
    mostrar_matriz(matriz);
    
    int *ptr_mayor = buscar_mayor(matriz);

    printf("El mayor es %d\n", *ptr_mayor);



}

int* buscar_mayor(int matriz[FILAS][COLS]){
    int mayor_i=0, mayor_j=0, mayor = matriz[0][0];
    
    
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLS; j++){
            if(matriz[i][j]>mayor){
                mayor = matriz[i][j];
                mayor_i=i;
                mayor_j=j;
            }
        }
                   
    }
    
     return &matriz[mayor_i][mayor_j];
}



void llenar_matriz(int matriz[FILAS][COLS]){
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<FILAS; j++){
            matriz[i][j]= 1 + rand() % 100;   
        }
    }
}



void mostrar_matriz(int matriz[FILAS][COLS]){
    for(int i=0; i<FILAS; i++){
        for(int j=0; j<COLS; j++){
            printf("%d\t", matriz[i][j]);   
                 
                
        }
        printf("\n");
        
    }
}


