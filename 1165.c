#include <stdio.h>

int main ()
{

  unsigned short int n, i, x, k, cont = 0;

  scanf("%hd", &x);

  for (k = 0; k < x; k++)
  {

    scanf("%hd", &n);

    for (i = 1; i <= n; i++)
      if (n % i == 0)
        cont++;

  if (cont != 2)
    printf("%d nao eh primo\n", n);
  else
    printf("%d eh primo\n", n);

  cont = 0;
  }
}
