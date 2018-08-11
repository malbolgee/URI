/*
  @autor: Malbolge;
  @data: 30/07/2018;
  @nome: Preenchimento de Vetor IV;
*/

#include <stdio.h>

int main ()
{

  int n, i, k, z, j, l;
  int par[5], impar[5];


  k = 0;
  z = 0;
  for (i = 0; i < 15; i++)
  {

      scanf("%d", &n);

      if (n % 2 == 0)
      {

        par[k] = n;
        k++;
        if (k == 5)
        {

          k = 0;
          for (j = 0; j < 5; j++)
          {

            printf("par[%d] = %d\n", j, par[j]);

          }
        }
      }
      else
      {

        impar[z] = n;
        z++;

        if (z == 5)
        {

          z = 0;
          for (l = 0; l < 5; l++)
          {

            printf("impar[%d] = %d\n", l, impar[l]);

          }
        }
      }
  }

  for (i = 0; i < z; i++)
  {

    printf("impar[%d] = %d\n", i, impar[i]);

  }

  for ( i = 0; i < k; i++)
  {

    printf("par[%d] = %d\n", i, par[i]);

  }
}
