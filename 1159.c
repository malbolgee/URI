#include <stdio.h>

int main ()
{

  int x, j, k, soma = 0;

  do{

    scanf("%d", &x);

    if (x == 0)
    {

      return 0;

    }

    for (k = 0, j = x; k < 5; j++)
    {

      if (j % 2 == 0)
      {

        soma += j;
        k++;

      }
    }

    printf("%d\n", soma);
    soma = 0;

} while (x != 0);

}
