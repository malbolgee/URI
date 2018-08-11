#include <stdio.h>

int main ()
{

  int n, i;

  do{
  scanf("%d", &n);
  if (n == 0)
  {

    return 0;

  }

  for (i = 1; i < n; i++)
  {

    printf("%d ", i);

  }

  printf("%d\n", i);

} while (n != 0);
}
