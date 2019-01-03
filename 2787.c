/*
	@autor: Malbolge;
	@data: 03/01/2019;
	@nome: Xadrez;
*/

#include <stdio.h>

void main ()
{

	unsigned short linha, coluna;

	scanf("%hu %hu", &linha, &coluna);

	if (linha % 2 == 0 && coluna % 2 == 0)
		printf("1\n");
	else if (linha % 2 == 1 && coluna % 2 == 1)
		printf("1\n");
	else
		printf("0\n");

}
