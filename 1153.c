#include <stdio.h>

int main ()
{
  int n, i, resultado = 1;
  scanf("%d", &n);

  for (i = n; i > 0; i--)
  {

      resultado *= i;

  }
  printf("%d\n", resultado);
  return 0;

}
