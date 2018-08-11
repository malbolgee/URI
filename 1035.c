/*
	@autor: Malbolge;
	@data: 22/07/2018;
	@nome: Teste de Seleção 1;
*/


#include <stdio.h>

int main ()
{

  unsigned short int a, b, c, d;
  scanf("%hd %hd %hd %hd", &a, &b, &c, &d);

  if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && a % 2 == 0 )
    printf("Valores aceitos\n");
  else
    printf("Valores nao aceitos\n");

}
