#include <stdio.h>

int main ()
{

  int n, i, j, cont = 1, k;

  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = cont, k = 0; k < 3; j++, k++)
    {

      printf("%d ", j);

    }
    printf("PUM");
    printf("\n");
    cont += 4;
  }
}
