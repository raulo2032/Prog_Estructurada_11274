#include<stdio.h>

int main (void)
{ char a;
  short b;
  int c;
  long d;
  float e;
  double f;
  long double g;

  printf("tamanio en plataforma de un char = %2d (bytes)\n", sizeof(a));
  printf("tamanio en plataforma de un short = %2d (bytes)\n", sizeof(b));
  printf("tamanio en plataforma de un int = %2d (bytes)\n", sizeof(c));
  printf("tamanio en plataforma de un long = %2d (bytes)\n", sizeof(d));
  printf("tamanio en plataforma de un float = %2d (bytes)\n", sizeof(e));
  printf("tamanio en plataforma de un double = %2d (bytes)\n", sizeof(f));
  printf("tamanio en plataforma de un long double = %2d (bytes)\n",                       sizeof(g));
}
