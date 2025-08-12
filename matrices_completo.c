/*
  Name: Matrices Completo - Guia 3
  Author: Damián hernández
  Description: Realiza operaciones con matrices (ej del 40 al 45 todos juntos)
*/


#include <stdio.h>
#include <string.h>

#define OP_DETERMINANTE     'd'     /*opciones de operaciones*/
#define OP_MULTIPLICACION   'm'
#define OP_SIMETRICA        's'
#define OP_TRANSPUESTA      't'
#define OP_TRAZA            'T'

#define OP_2X2  'd'     /*opciones de matrices a ingresar*/
#define OP_3X3  't'

#define OP_SALIDA_LOCAL_SI 's'      /*opciones de salida del programa*/ 
#define OP_SALIDA_LOCAL_NO 'n'
#define OP_SALIDA_GENERAL_SI 'S'
#define OP_SALIDA_GENERAL_NO 'N'

#define N2 2    /*max columnas y filas*/
#define N3 3
#define P  3


typedef enum {DETERMINANTE,MULTIPLICACION,SIMETRICA,TRANSPUESTA,TRAZA} toperacion;
typedef enum {M2X2, M3X3} tmatriz;
typedef enum {FALSE, TRUE} bool;


int main (void){
    unsigned int i, j, k;   /*declaración de variables*/
    double m1[N3][N3];  
    double m2[N3][P];
    
    char mat, opc;          
    toperacion operacion;
    
    double det;     
    tmatriz matriz;
       
    double multiplica;  
    double rta[N3][P];
   
    bool simetrica; 
    
    double traza;   
              
    double transpuesta[N3][N3]; 
        
    char sal_loc, sal_gen;  /*para la salida del programa*/
    bool salida_loc, salida_gen;
    
        
    
            
 do{  /*do while general, para seguir operando sin salir de programa*/
  
    /*ingresa longitud de la matriz*/
    printf("\n Desea ingresar una matriz de: \n");
    printf("\t 2 X 2 (d) \t o \t 3 x 3 (t)? ");
    scanf("%c", &mat);
    
    if (mat == OP_2X2)         matriz = M2X2; /*pongo etiqueta*/
    else if (mat == OP_3X3)    matriz = M3X3;
    
    
    switch (matriz){    /*presento los dos casos, 2x2 y 3x3*/
        case (M2X2):{
           
            printf("\n Ingrese los valores de la matriz: \n");
        
            for (i=0; i < N2; i++){
                for (j=0; j < N2; j++){
                    printf("\t * Para la posicion %u %u : ", i, j);
                    scanf("%lf", &m1[i][j]);
                }
            
                printf("\n");
            }
        
           do{ /*do while local, para operar varias veces con la misma matriz*/
            getchar();
            
            /*menu de opciones*/
            printf("\n Con la matriz ingresada que operacion desea realizar? \n");
            printf("\t * Calcular el DETERMINANTE de la matriz(d) \n");
            printf("\t * Realizar una MULTIPLICACION con otra matriz (m) \n");
            printf("\t * Saber si la matriz ingresada es SIMETRICA (s) \n");
            printf("\t * Hallar la matriz TRANSPUESTA (t) \n");
            printf("\t * Calcular la TRAZA de la matriz (T) \n");
            printf(" ---------------- : ");
            scanf("%c", &opc);
    
            switch (opc){   /*pongo etiqueta a la operación*/
                case (OP_DETERMINANTE):{     operacion = DETERMINANTE; break;
                }
                case (OP_MULTIPLICACION):{   operacion = MULTIPLICACION; break;
                }
                case (OP_SIMETRICA):{        operacion = SIMETRICA; break;
                }
                case (OP_TRANSPUESTA):{      operacion = TRANSPUESTA; break;
                }
                case (OP_TRAZA):{            operacion = TRAZA; break;
                }
                default:{
                    fprintf(stderr, "\n ERROR!!!Ingreso una opcion invalida");
                    return 1;
                }

            }/*fin switch (opc) */
   
           
             switch (operacion){ /*desarrollo de cada operación*/
                
                case (DETERMINANTE):{
                   
                     /*operación del discriminante*/
                    det = m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0];
                    
                    /*resultado del determinante*/
                    fprintf(stdout, "\n La matriz: \n");
    
                    for (i=0; i < N2; i++){
                        for (j=0; j < N2; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    
                    fprintf(stdout, "\n Tiene un determinante de: %.2lf \n", det);
                    
                    
                    break;
                    
                } /*fin determinante*/
        
                case (MULTIPLICACION):{
                    
                    /*ingresa nueva matriz para la multiplicación*/
                    printf("\n Ingrese los valores de la segunda matriz: \n");
            
                    for (i=0; i < N2; i++){
                        for (j=0; j < P; j++){
                            printf("\t * Para la posicion %u %u : ", i, j);
                            scanf("%lf", &m2[i][j]);
                        }
        
                        printf("\n");
                    }
  
                    /*cálculo del producto*/
                    for (i=0; i < N2; i++)
                        for (j=0; j < P; j++){
                        multiplica = 0;
                           
                           for (k=0; k < N2; k++)
                                multiplica = multiplica + m1[i][k]* m2[k][j];
            
                        rta[i][j] = multiplica;
                        }  
        
                    /*resultado*/
                    printf("\n El resulado de multiplicar la matriz: \n");
                 
                    for (i=0; i < N2; i++){
                        for (j=0; j < N2; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "\n Con la matriz: \n");
    
                    for (i=0; i < N2; i++){
                        for (j=0; j < N2; j++)
                            fprintf(stdout, "%.3lf \t", m2[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "Es :  \n");
                    
                    for (i=0; i < N2; i++){
                        for (j=0; j < P; j++)
                            fprintf(stdout, "%.2lf \t", rta[i][j]);
        
                        fprintf(stdout, "\n");
                    }
                    
                    break;
        
                } /*fin multiplicacion*/
                
                
                case (SIMETRICA):{
                    
                    /*verifica q sea simétrica*/
                    for (i=0; i < N2; i++)
                        for (j=0; j < N2; j++){
                            if (m1[i][j] == m1[j][i])    
                                simetrica = TRUE;
            
                            else{
                                simetrica = FALSE;
                                break;
                            }
                        }  
                    
                    /*resultado*/
                    fprintf(stdout, "\n La matriz: \n");
    
                    for (i=0; i < N2; i++){
                        for (j=0; j < N2; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    if (simetrica == TRUE)  fprintf(stdout, "\n ES SIMETRICA!! \n");
                    else                    fprintf(stdout, "\n NO ES SIMETRICA \n"); 
                    
                    break;
    
                } /*fin simetrica*/
                
                
                case (TRANSPUESTA):{
                    
                    /*transpone los elementos en una nueva matriz*/
                    for (j=0; j < N2; j++){
                        for (i=0; i < N2; i++)
                            transpuesta[j][i] = m1[i][j];
            
                    }
                    
                    /*resultado*/
                    fprintf(stdout, "\n Matriz original: \n");
    
                    for (i=0; i < N2; i++){
                        for (j=0; j < N2; j++)
                           fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "\n Matriz transpuesta: \n");
    
                    for (j=0; j < N2; j++){
                        for (i=0; i < N2; i++)
                            fprintf(stdout, "%.3lf \t", transpuesta[j][i]);
        
                        fprintf(stdout, "\n");
                    }
                    
                    break;

                }/*fin transpuesta*/
                
                
                case (TRAZA):{
                    traza = 0; /*inicializo el valor de la traza*/
    
                    /*sumo los elementos de la diagonal, donde [i]=[j]*/
                    for (i=0; i < N2; i++){
                        j = i;
        
                        traza = traza + m1[i][j];
                    }
                    
                    /*resultado*/
                    fprintf(stdout, "\n La matriz: \n");
    
                    for (i=0; i < N2; i++){
                        for (j=0; j < N2; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "\n Tiene un traza de: %.2lf \n", traza);
                    
                    break;
                }/*fin traza*/
                
                                                
            }/*fin switch operacion de 2x2*/
            
          
          /*pregunta para volver a utilizar la matriz, realizando otra opereración*/ 
          printf("\n\n ///////////// Realiza otra operacion con la misma matriz? (s/n) ");    /*pregunta para volver a ejecutar el programa*/
          scanf("%s", &sal_loc);
    
          /*pongo etiqueta a la salida_loc*/
          if (sal_loc == OP_SALIDA_LOCAL_SI)        salida_loc = TRUE;     
          else if (sal_loc == OP_SALIDA_LOCAL_NO)   salida_loc = FALSE;
    
       
          } while (salida_loc == TRUE); /*fin switch 2x2*/
          
          break;
          
      } /*fin switch 2x2*/
  
          
/* Ahora comienza el caso en el q la matriz es de 3x3, lo único q cambia con el caso
anterior es el rango de la matriz. Por lo tanto no vuelvo a comentar todo*/

        case (M3X3):{
           
            printf("\n Ingrese los valores de la matriz: \n");
            
            for (i=0; i < N3; i++){
                for (j=0; j < N3; j++){
                    printf("\t * Para la posicion %u %u : ", i, j);
                    scanf("%lf", &m1[i][j]);
                }
                
                printf("\n");
            }
    
           do {
            getchar();
            
            printf("\n Con la matriz ingresada que operacion desea realizar? \n");
            printf("\t * Calcular el DETERMINANTE de la matriz(d) \n");
            printf("\t * Realizar una MULTIPLICACION con otra matriz (m) \n");
            printf("\t * Saber si la matriz ingresada es SIMETRICA (s) \n");
            printf("\t * Hallar la matriz TRANSPUESTA (t) \n");
            printf("\t * Calcular la TRAZA de la matriz (T) \n");
            printf(" ---------------- : ");
            scanf("%c", &opc);
    
            switch (opc){
                case (OP_DETERMINANTE):{     operacion = DETERMINANTE; break;
                }
                case (OP_MULTIPLICACION):{   operacion = MULTIPLICACION; break;
                }
                case (OP_SIMETRICA):{        operacion = SIMETRICA; break;
                }
                case (OP_TRANSPUESTA):{      operacion = TRANSPUESTA; break;
                }
                case (OP_TRAZA):{            operacion = TRAZA; break;
                }
                default:{  
                    fprintf(stderr, "ERROR!! Ingreso una opcion invalida");
                    return 1;
                }

            }
   
            switch (operacion){
                case (DETERMINANTE):{
                    det = m1[0][0] * ((m1[1][1] * m1[2][2]) - (m1[1][2] * m1[2][1]));
        
                    det = det - m1[0][1] * ((m1[1][0] * m1[2][2]) - (m1[1][2] * m1[2][0]));
        
                    det = det + m1[0][2] * ((m1[1][0] * m1[2][1]) - (m1[1][1] * m1[2][0]));
                    
                    /*resultado del determinante*/
                    fprintf(stdout, "\n La matriz: \n");
    
                    for (i=0; i < N3; i++){
                        for (j=0; j < N3; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    
                    fprintf(stdout, "\n Tiene un determinante de: %.2lf \n", det);
                    
                    break;
                
                } /*fin determinante*/
        
                case (MULTIPLICACION):{
                    /*ingresa datos multiplicacion*/
                    printf("\n Ingrese los valores de la segunda matriz: \n");
            
                    for (i=0; i < N3; i++){
                        for (j=0; j < P; j++){
                            printf("\t * Para la posicion %u %u : ", i, j);
                            scanf("%lf", &m2[i][j]);
                        }
        
                        printf("\n");
                    }
  
                    /*calculo del producto*/
                    for (i=0; i < N3; i++)
                        for (j=0; j < P; j++){
                        multiplica = 0;
                           
                           for (k=0; k < N3; k++)
                                multiplica = multiplica + m1[i][k]* m2[k][j];
            
                        rta[i][j] = multiplica;
                        }  
        
                    /*resultado*/
                    printf("\n El resulado de multiplicar la matriz: \n");
                 
                    for (i=0; i < N3; i++){
                        for (j=0; j < N3; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "\n Con: \n");
    
                    for (i=0; i < N3; i++){
                        for (j=0; j < N3; j++)
                            fprintf(stdout, "%.3lf \t", m2[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "\n Es:  \n");
                    
                    for (i=0; i < N3; i++){
                        for (j=0; j < P; j++)
                            fprintf(stdout, "%.2lf \t", rta[i][j]);
        
                        
                        fprintf(stdout, "\n");
                    }
                    
                    break;
        
                } /*fin multiplicacion*/
                
                case (SIMETRICA):{
                    for (i=0; i < N3; i++)
                        for (j=0; j < N3; j++){
                            if (m1[i][j] == m1[j][i])    
                                simetrica = TRUE;
            
                            else{
                                simetrica = FALSE;
                                break;
                            }
                        }  
                    
                    /*resultado*/
                    fprintf(stdout, "\n La matriz: \n");
    
                    for (i=0; i < N3; i++){
                        for (j=0; j < N3; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    if (simetrica == TRUE)  fprintf(stdout, "\n ES SIMETRICA!! \n");
                    else                    fprintf(stdout, "\n NO ES SIMETRICA \n"); 
                    
                    break;
    
                } /*fin simetrica*/
                
                
                case (TRANSPUESTA):{
                    for (j=0; j < N3; j++){
                        for (i=0; i < N3; i++)
                            transpuesta[j][i] = m1[i][j];
            
                    }
                    
                    /*resultado*/
                    fprintf(stdout, "\n Matriz original: \n");
    
                    for (i=0; i < N3; i++){
                        for (j=0; j < N3; j++)
                           fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
    
                    fprintf(stdout, "\n Matriz transpuesta: \n");
    
                    for (j=0; j < N3; j++){
                        for (i=0; i < N3; i++)
                            fprintf(stdout, "%.3lf \t", transpuesta[j][i]);
        
                        fprintf(stdout, "\n");
                    }
                    
                    break;

                }/*fin transpuesta*/
                
                
                case (TRAZA):{
                    traza = 0;
    
                    for (i=0; i < N3; i++){
                        j = i;
        
                        traza = traza + m1 [i][j];
                    }
                    
                    /*resultado*/
                    fprintf(stdout, "\n La matriz: \n");
    
                    for (i=0; i < N3; i++){
                        for (j=0; j < N3; j++)
                            fprintf(stdout, "%.3lf \t", m1[i][j]);
        
                        fprintf(stdout, "\n");
                    }
                    
                    fprintf(stdout, "\n Tiene un traza de: %.2lf \n", traza);
                    
                    break;
                }/*fin traza*/
   
            }/*fin switch operacion de 3x3*/
  
        
          printf("\n\n ///////////// Realiza otra operacion con la misma matriz? (s/n) ");    /*pregunta para volver a ejecutar el programa*/
          scanf("%s", &sal_loc);
    
          if (sal_loc == OP_SALIDA_LOCAL_SI)        salida_loc = TRUE;     
          else if (sal_loc == OP_SALIDA_LOCAL_NO)   salida_loc = FALSE;
          
          
          } while (salida_loc == TRUE); /*fin do while 3x3*/
               
      }/*fin case 3x3*/
    
    }/*fin switch*/

    
    /*pregunta para salir del programa*/
    printf("\n ############# Sale del programa? (S/N) ");
    scanf("%s", &sal_gen);
    
    /*etiqueta para salida_gen*/
    if (sal_gen == OP_SALIDA_GENERAL_SI)        salida_gen = TRUE;     
    else if (sal_gen == OP_SALIDA_GENERAL_NO)   salida_gen = FALSE;
    
    getchar();
  
 } while (salida_gen == FALSE); /*fin do while general*/
 
 
 return 0;
 
}/*fin main*/


    
