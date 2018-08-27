/*
  @autor: Malbolge;
  @data: 26/08/2018;
  @nome: Domingo de Manhã;
*/

#include <stdio.h>

void main (void)
{

  unsigned short hora, minuto, resultado = 0;
  char ponto;

  while (scanf("%hd%c%hd", &hora, &ponto, &minuto) != EOF)
  {

    if (hora >= 5 && hora <= 6)
      printf("Atraso maximo: %hu\n", 0);
    else if (hora == 7)
      printf("Atraso maximo: %hu\n", minuto);
    else if (hora == 8)
      printf("Atraso maximo: %hu\n", 60+minuto);
    else if (hora == 9)
      printf("Atraso maximo: %hu\n", 120+minuto);

    }
}
