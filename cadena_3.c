#include <stdio.h>
#include <string.h>

int func(int x){
    return x;
}
int main(void) {
    int x;
    printf("Hello, world!\n");
    char *saludo = "Salut, mundi.";       /*no la puedo recorrer y cambiar un valor*/
    char saludo_2[] = "Salut, mundi.";      /*le puedo cambiar un valor*/
                                            /* pues esta declarada como array*/

    char ptr[14];
    // printf("%s\n", saludo);
    // printf("%s\n", saludo_2);
    
    
    strcpy(ptr, saludo_2); /*Sobran 7 caracteres: ptr[12] - ptr[19] */
    printf("%s\n", ptr);
    int i;
    for (i = 0; ptr[i] != '\0'; i++)
    {
        printf("Char: %c\n", ptr[i]);
    }

    for (i = 0; i < 30; i++)
    {
        printf("Char: %c\n", ptr[i]);
    }
    

    

    return 0;
}
