/*
  @autor: Malbolge;
  @data: 15/08/2018;
  @nome: O Jogo Matemático de Paula;
*/

#include <stdio.h>
#include <ctype.h>

int main ()
{

  char letra;
  short numero1, numero2, resultado;
  unsigned short teste, i;

  scanf("%hd", &teste);

  for (i = 0; i < teste; i++)
  {
    scanf("%hd%c%hd", &numero1, &letra, &numero2);
    resultado = 0;

    if (numero1 == numero2)
    {
      resultado = numero1 * numero2;
      printf("%d\n", resultado);
    }

    else if (isupper(letra))
    {
      resultado = numero2 - numero1;
      printf("%d\n", resultado);
    }
    else if(islower(letra))
    {
      resultado = numero1 + numero2;
      printf("%d\n", resultado);
    }
  }
}
