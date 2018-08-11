#include <stdio.h>

int main () {

int x, y, soma = 0, i, aux;


scanf("%d %d", &x, &y);

if (y < x)
{

   aux = x;
   x = y;
   y = aux;

}

for (i = x + 1; i < y; i++)
{

  if (i % 5 == 3 || i % 5 == 2)
  {

    printf("%d\n", i);

  }
}
}
