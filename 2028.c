/*
  @autor: Malbolge;
  @data: 12/08/2018;
  @nome: Sequência de Sequência;
*/

#include <stdio.h>

int contagem(int);


int main ()
{

  unsigned short numero, i, j, k, cont = 0, caso = 0;

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

      caso++;
      printf("Caso %d: %d numeros\n", caso, contagem(numero));
      for(i = 0; i <= numero; i++)
      {

        if (i == 0)
          printf("0");

        for (j = i, k = 1; k <= i; k++)
          printf(" %d", j);

      }

      printf("\n\n");
      cont = 0;

    }
  }
}

int contagem(int a)
{

  unsigned short soma = 0, i;

  for (i = a; i > 0; i--)
    soma += i;

  return ++soma;
}
