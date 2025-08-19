#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

    int num1, num2;
/* Se espera que reciba 3 argumentos: el nombre
* del programa y los dos números enteros a sumar. */
if (argc != 3){
    printf("Modo de uso: %s <entero> <entero> \n", argv[0]);
    return 1;
}

printf("Bienvenido al programa %s \n\n", argv[0]);
/* atoi() convierte una cadena de caracteres en un entero */
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
printf("%d + %d = %d \n", num1, num2, num1 + num2);
return 0;
}