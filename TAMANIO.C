#include<stdio.h>

int main (void)
{ char a;
  short b;
  int c;
  long d;
  float e;
  double f;
  long double g;

  printf("tamanio en plataforma de un char = %zu (bytes)\n", sizeof(a));
  printf("tamanio en plataforma de un short = %zu (bytes)\n", sizeof(b));
  printf("tamanio en plataforma de un int = %zu (bytes)\n", sizeof(c));
  printf("tamanio en plataforma de un long = %zu (bytes)\n", sizeof(d));
  printf("tamanio en plataforma de un float = %zu (bytes)\n", sizeof(e));
  printf("tamanio en plataforma de un double = %zu (bytes)\n", sizeof(f));
  printf("tamanio en plataforma de un long double = %zu (bytes)\n",                       sizeof(g));
}
