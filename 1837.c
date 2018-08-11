/*
  @autor: Malbolge;
  @data: 03/08/2018;
  @nome: Prefácio;
*/

#include <stdio.h>

int main ()
{

  signed short int a, b, resultado, resto;

  scanf("%hd %hd", &a, &b);

  resultado = (int)a/b;
  resto = a%b;
  printf("%d %d\n", resultado, resto);



}
