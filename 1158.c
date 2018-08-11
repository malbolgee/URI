#include <stdio.h>

int main ()
{

  int x, y, i, n, j, k, soma = 0, aux;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &x, &y);

    for (k = 0, j = x; k < y; j++)
    {

      if (j % 2 != 0)
      {

        soma += j;
        k++;

      }
    }

    printf("%d\n", soma);
    soma = 0;

  }
}
