/*
  @autor: Malbolge;
  @data: 15/08/2018;
  @nome: Cifra de Cézar;
*/
#include <stdio.h>
#include <string.h>

int main ()
{
  unsigned short testes, deslocamento;
  unsigned short i, j;

  scanf("%hd", &testes);

  for (i = 0; i < testes; i++)
  {
    char palavra[50], letra;
    scanf("%s", palavra);
    scanf("%hd", &deslocamento);

    for (j = 0; j < strlen(palavra); j++)
    {
      if (palavra[j] - deslocamento < 'A')
      {
        letra = '[' - (deslocamento - (palavra[j] - 'A'));
        printf("%c", letra);
      }
      else
      {
        letra = palavra[j] - deslocamento;
        printf("%c", letra);
      }
    }
    printf("\n");
  }
}
