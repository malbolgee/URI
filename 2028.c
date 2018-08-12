/*
  @autor: Malbolge;
  @data: 12/08/2018;
  @nome: Sequência de Sequência;
*/

#include <stdio.h>

int main ()
{

  int numero, i, j, k, cont = 0, caso = 0;

  while (scanf("%d", &numero) != EOF)
  {

    if (numero == 0)
    {

      printf("Caso 1: 1 numero\n");
      printf("0\n");

    }
    else
    {

      for(i = 0; i <= numero; i++)
      {

        if (i == 0)
          printf("0 ");
        if (i == numero)
          printf("Caso %d: %d numeros\n", caso, cont);

        for (j = i, k = 1; k <= i; k++)
        {

          printf("%d ", j);
          cont++;

        }
      }
    }
  }
}
