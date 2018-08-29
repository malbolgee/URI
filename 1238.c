/*
  @autor: Malbolge;
  @data: 28/08/2018;
  @nome: Combinador;
*/

#include <stdio.h>
#include <string.h>

void main (void)
{

  char palavra1[60], palavra2[60];
  unsigned short i = 0, casos = 1, maior;

  while (casos)
  {
    scanf("%hu", &casos);

    scanf("%s %s", palavra1, palavra2);
    unsigned char tamPlv1 = strlen(palavra1), tamPlv2 = strlen(palavra2);

    if (tamPlv1 > tamPlv2)
      maior = tamPlv1;
    else
      maior = tamPlv2;

    while (maior)
    {

      if (i < tamPlv1)
        printf("%c", palavra1[i]);
      if (i < tamPlv2)
        printf("%c", palavra2[i]);

      i++;
      maior--;
    }

    printf("\n");
    i = 0;
    casos--;
  }
}
