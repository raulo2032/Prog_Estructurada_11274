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

#define FILAS   15
#define COLS    3 

void llenar_matriz(int matriz[FILAS][COLS]);
void mostrar_matriz(int matriz[FILAS][COLS]);
int buscar_persona(int matriz[FILAS][COLS], int sexo, int estado, int edad);

int main(void){
    int matriz [FILAS][COLS]={};
    srand(time(NULL));
    llenar_matriz(matriz);
    mostrar_matriz(matriz);
    printf("Existen en la lista %d personas hombre soltero de 35 anios\n", buscar_persona(matriz, 1,1,35));
    printf("Existen en la lista %d personas mujer casada de 34 anios\n", buscar_persona(matriz, 2,2,34));

}

int buscar_persona(int matriz[FILAS][COLS], int sexo, int estado, int edad){
    int contador=0;
    
    for(int i=0; i<FILAS; i++){
            if(matriz[i][0]==sexo && matriz[i][1]==estado && matriz[i][2] == edad) contador ++;
        
    }
    return contador;
}

/* sexo 1 o 2, estado 1 2 o 3, edad 1 a 70 */
void llenar_matriz(int matriz[FILAS][COLS]){
    for(int i=0; i<FILAS; i++){
                 
                matriz[i][0]= 1 + rand() % 2;   
                matriz[i][1]= 1 + rand() % 3;   
                matriz[i][2]= 33 + rand() % 4;   
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


