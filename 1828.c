/*
  @autor: Malbolge;
  @data: 02/08/2018;
  @nome: Bazinga!;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main ()
{
  unsigned short int n, cont = 0;
  char sheldon[10], raj[10];

  scanf("%hd", &n);

  for (unsigned short i = 0; i < n; i++)
  {

    cont++;
    scanf("%s %s", sheldon, raj);
    if (strcmp(sheldon, raj) == 0)
      printf("Caso #%d: De novo!\n", cont);
    else if (strcmp(sheldon, "Spock") == 0 && strcmp(raj, "pedra") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "lagarto") == 0 && strcmp(raj, "Spock") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "tesoura") == 0 && strcmp(raj, "lagarto") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "papel") == 00 && strcmp(raj, "Spock") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "tesoura") == 0 && strcmp(raj, "papel") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "papel") == 0 && strcmp(raj, "pedra") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "lagarto") == 0 && strcmp(raj, "papel") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "pedra") == 0 && strcmp(raj, "lagarto") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "Spock") == 0 && strcmp(raj, "tesoura") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else if (strcmp(sheldon, "pedra") == 0 && strcmp(raj, "tesoura") == 0)
      printf("Caso #%d: Bazinga!\n", cont);
    else
      printf("Caso #%d: Raj trapaceou!\n", cont);
  }
}
