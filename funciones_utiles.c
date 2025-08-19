#include <c.type.h>

//Estas funcionan sobre caracteres

int isalnum (int c);
int isalpha (int c);
int isascii (int c);
int isblank (int c);
int iscntrl (int c);
int isdigit (int c);
int isgraph (int c);
int islower (int c);
int isprint (int c);
int ispunct (int c);
int isspace (int c);
int isupper (int c);
int isxdigit (int c);

// Estas funcionan sobre strings

#include <string.h>
char *strcpy(char *dest, const char *orig);
char *strcnpy(char *dest, const n char *orig);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const n char *src);
int *strlen((const char *s);
int *strcmp(const char *s1, const char *s2);
Devuelve 0 si las cadenas representadas por arg1 y arg2 son iguales, o un
valor menor que cero si arg1 precede alfabéticamente a arg2.