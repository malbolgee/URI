/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: Og;
*/

#include <stdio.h>

void main ()
{

	unsigned char dir, esq;

	while (1)
	{

		scanf("%hhd %hhd", &dir, &esq);

		if (esq == 0 && dir == 0)
			break;

		printf("%hhd\n", esq+dir);

	}

}