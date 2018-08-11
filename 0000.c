/*
  @autor: Malbolge;
  @data: 07/08/2018;
  @nome: Matriz Padrão;
*/

#include <stdio.h>

int main ()
{

  unsigned short int tamanho, linha, coluna;

  while (1)
  {

    scanf("%hd", &tamanho);
    short matriz[tamanho][tamanho];

    if (tamanho == 0)
      return 0;

    for(linha = 0; linha < tamanho; linha++)
      for(coluna = 0; coluna < tamanho; coluna++)
      {
        if (linha == coluna)
          matriz[linha][coluna] = linha + 1;
        if (linha + 1 == matriz[linha][linha])
          matriz[linha][coluna] = linha + 1;
        if (linha > coluna)
          matriz[linha][coluna] = coluna + 1;
      }

    for(linha = 0; linha < tamanho; linha++)
    {
      for(coluna = 0; coluna < tamanho; coluna++)
        printf("%d ", matriz[linha][coluna]);
      printf("\n");
    }
  }
}
