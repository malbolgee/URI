/*
  @autor: Malbolge;
  @data: 03/08/2018;
  @nome: Matriz Quadrada IV;
*/

#include <stdio.h>

void matrix(unsigned short);

int main ()
{

  unsigned short tamanho;

  while (scanf("%hd", &tamanho) != EOF)
  {

    matrix(tamanho);

  }
}

void matrix(unsigned short tamanho)
{

  int m[tamanho][tamanho];
  unsigned short linha, coluna;

  // Preenche a matriz com 2 na diagonal principal;
  // 3 na diagonal secundária;
  // e 0 nas demais posições;
  for (linha = 0; linha < tamanho; linha++)
    for (coluna = 0; coluna < tamanho; coluna++)
    {

      if (linha == coluna)
        m[linha][coluna] = 2;
      else if (linha == tamanho - coluna - 1)
        m[linha][coluna] = 3;
      else
        m[linha][coluna] = 0;

    }

  // Dica dada pela questão;
  unsigned short inicio = tamanho/3;
  // O problema é achar a condição de parada, ou seja, o fim;
  // O final seria o tamanho menos o início, para sempre sobrar a
  // mesma quantidade de colunas em ambos os lados;
  unsigned short fim = tamanho - inicio;

  for (linha = inicio; linha < fim; linha++)
    for (coluna = inicio; coluna < fim; coluna++)
      m[linha][coluna] = 1;

  // O tamanho dividido por 2 sempre nos dá o elemento central;
  m[tamanho/2][tamanho/2] = 4;

  // Apenas imprime a matriz resultante;
  for (linha = 0; linha < tamanho; linha++)
  {

    for (coluna = 0; coluna < tamanho; coluna++)
      printf("%d", m[linha][coluna]);

    printf("\n");
  }
  printf("\n");
}