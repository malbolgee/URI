/*
	@autor: Malbolge;
	@data: 05/01/2019;
	@nome: Garçom;
*/

#include <stdio.h>

void main ()
{

	unsigned short soma = 0;
	unsigned short qtsBandejas;
	unsigned short latas, copos;

	scanf("%hu", &qtsBandejas);

	while (qtsBandejas--)
	{

		scanf("%hu %hu", &latas, &copos);

		if (latas > copos)
			soma += copos;

	}

	printf("%hu\n", soma);

}
