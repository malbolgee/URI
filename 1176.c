/*
  @autor: Malbolge;
  @data: 30/07/2018;
  @nome: Fibonacci em Vetor;
*/
#include <stdio.h>
#include <math.h>

int main ()
{

  int t, n, i, k, a = 0, b = 1, fib = 0;
  long long int c = 0;

  scanf("%d", &t);

  for (i = 0; i < t; i++)
  {

    scanf("%d", &n);

    if (n == 0)
    {

      printf("Fib(%d) = 0\n", n);

    }
    else
    {

      for (k = 0; k < n; k++)
      {

        a = b;
        b = c;
        c = a + b;

      }
      printf("Fib(%d) = %lld\n", n, c);
      a = 0;
      b = 1;
      c = 0;
    }
  }
}
