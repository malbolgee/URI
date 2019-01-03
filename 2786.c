/*
	@autor: Malbolge;
	@data: 03/01/2019;
	@nome: Piso da Escola;
*/

#include <stdio.h>

void main ()
{

	unsigned short linha, coluna;

	scanf("%hu %hu", &linha, &coluna);

	printf("%hu\n", (linha * coluna) + (linha - 1) * (coluna - 1));
	printf("%hu\n",  (2 * (linha - 1)) + (2 * (coluna - 1)));

}
