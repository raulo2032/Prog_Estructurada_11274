#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    char p[5] = {'H','o', 'l', 'a', '\0'};

    

    printf("Un carácter = %c\n", p[0]); /* Imprime H */
    printf("Contenido de p = %s\n", p); /* p apunta al array */
 
    return 0;
}