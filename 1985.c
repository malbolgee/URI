/*
  @autor: Malbolge;
  @data: 26/08/2018;
  @nome: MacPRONALTS;
*/

#include <stdio.h>

void main (void)
{

  unsigned short quantidade, casos, opcao;
  float total = 0;

  scanf("%hd", &casos);

  while (casos)
  {

      scanf("%hd %hd", &opcao, &quantidade);

      if (opcao == 1001)
        total += 1.50*quantidade;
      if (opcao == 1002)
        total += 2.50*quantidade;
      if (opcao == 1003)
        total += 3.50*quantidade;
      if (opcao == 1004)
        total += 4.50*quantidade;
      if (opcao == 1005)
        total += 5.50*quantidade;

    casos--;
  }
  printf("%.2f\n", total);
}
