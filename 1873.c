/*
  @autor: Malbolge;
  @data: 04/09/2018;
  @nome: Pedra-papel-tesoura-lagarto-Spock;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main ()
{
  unsigned short int n;
  char sheldon[10], rajesh[10];

  scanf("%hd", &n);

  while (n--)
  {

    scanf(" %s %s", rajesh, sheldon);
    if (strcmp(rajesh, sheldon) == 0)
      printf("empate\n");
    else if (strcmp(rajesh, "spock") == 0 && strcmp(sheldon, "pedra") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "lagarto") == 0 && strcmp(sheldon, "spock") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "tesoura") == 0 && strcmp(sheldon, "lagarto") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "papel") == 00 && strcmp(sheldon, "spock") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "tesoura") == 0 && strcmp(sheldon, "papel") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "papel") == 0 && strcmp(sheldon, "pedra") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "lagarto") == 0 && strcmp(sheldon, "papel") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "pedra") == 0 && strcmp(sheldon, "lagarto") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "spock") == 0 && strcmp(sheldon, "tesoura") == 0)
      printf("rajesh\n");
    else if (strcmp(rajesh, "pedra") == 0 && strcmp(sheldon, "tesoura") == 0)
      printf("rajesh\n");
    else
      printf("sheldon\n");
  }
}
