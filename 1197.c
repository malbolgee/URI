/*
  @autor: Malbolge;
  @data: 15/08/2018;
  @nome: Volta à Faculdade de Física;
*/

#include <stdio.h>

int main ()
{

  signed short velocidade, tempo;

  while (scanf("%hd %hd", &velocidade, &tempo) != EOF)
    printf("%d\n", velocidade*tempo*2);

}
