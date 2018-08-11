/*
  @autor: Malbolge;
  @data: 03/08/2018;
  @nome: Matriz Quadrada IV;
*/

#include <stdio.h>

void matrix(unsigned short int);

int main ()
{

  unsigned short int n;

  while (scanf("%hd", &n) != EOF)
  {

    matrix(n);

  }
}

void matrix(unsigned short int n)
{

  int m[n][n];

  for (unsigned short i = 0; i < n; i++)
    for (unsigned short j = 0; j < n; j++)
    {

      if (i == j)
        m[i][j] = 2;
      else if (i == n - j - 1)
        m[i][j] = 3;
      else
        m[i][j] = 0;

    }

  unsigned short int k = n/3;
  //printf("Esse é o valor de K: %d\n", k);
  unsigned short int l = n-k;
  //printf("Esse é o valor de l: %d\n", l);

  for (unsigned short i = k; i < l; i++)
    for (unsigned short j = k; j < l; j++)
      m[i][j] = 1;

  m[n/2][n/2] = 4;

  for (unsigned short i = 0; i < n; i++)
  {

    for (unsigned short j = 0; j < n; j++)
      printf("%d", m[i][j]);

    printf("\n");
  }
  printf("\n");
}
