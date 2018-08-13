/*
  @autor: Malbolge;
  @data: 12/08/2018;
  @nome: Sequência de Sequência;
*/

#include <stdio.h>

int main ()
{

  register unsigned short numero, i, j, k, cont = 0, caso = 0;
   
  while (scanf("%hd", &numero) != EOF)
  {

    if (numero == 0)
    {
      caso++;
      printf("Caso %d: 1 numero\n", caso);
      printf("0\n\n");

    }
    else
    {
      
      for (i = 0; i <= numero; i++)
        for (j = i, k = 1; k <= i; k++)
          cont++;

      caso++;
      printf("Caso %d: %d numeros\n", caso, cont+1);

      for(i = 0; i <= numero; i++)
      {

        if (i == 0)
          printf("0");

        for (j = i, k = 1; k <= i; k++)
        {

          printf(" %d", j);
          cont++;

        }
      }

      printf("\n\n");
      cont = 0;

    }
  }
}