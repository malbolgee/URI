/*
  @autor: Malbolge;
  @data: 26/08/2018;
  @nome: O Enigma da Pronolândia;
*/

#include <stdio.h>
#include <string.h>

void main (void)
{

  char numero[10];
  char i, j, aux;

  scanf("%s", numero);
  unsigned short tam = strlen(numero), tam2 = tam/2;

  for (i = 0, j = tam - 1; i < tam2; i++, j--)
  {
    aux = numero[i];
    numero[i] = numero[j];
    numero[j] = aux;
  }

  printf("%s\n", numero);
}
