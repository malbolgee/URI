/*
  @autor: Malbolge;
  @data: 30/07/2018;
  @nome: Menor e Posição;
*/
#include "stdio.h"

int main ()
{

  int n, i, x, z;
  int menor, posicao;
  scanf("%d", &n);
  int vetor[n];

  for (i = 0; i < n; i++)
  {

    scanf("%d", &z);
    vetor[i] = z;

  }
  menor = vetor[0];
  for (i = 1; i < n; i++)
  {

    if (vetor[i] < menor)
    {

      menor = vetor[i];
      posicao = i;

    }
  }

  printf("Menor valor: %d\n", menor);
  printf("Posicao: %d\n", posicao);

}
