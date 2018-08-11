/*
  @autor: Malbolge;
  @data: 07/08/2018;
  @nome: Matriz Padrão;
*/

#include <stdio.h>

int main ()
{

  unsigned short int n, i, j;

  do
  {

    scanf("%hd", &n);
    int m[n][n];

    for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
      {
        if (i == j)
          m[i][j] = i + 1;
        if (i + 1 == m[i][i])
          m[i][j] = i + 1;
        if (i > j)
          m[i][j] = j + 1;
      }

    for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
        printf("%d ", m[i][j]);
      printf("\n");
    }
  } while(n != 0);
}
