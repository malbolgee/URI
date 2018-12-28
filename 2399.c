/*
	@autor: Malbolge;
	@data: 27/12/2018;
	@nome: Campo Minado;
*/

#include <stdio.h>

void main ()
{

	unsigned short i;
	unsigned short qtsCells;
	char campoMinado[] = { 0, 0, 0 };

	scanf("%hu", &qtsCells);

	for (i = 0; i < qtsCells + 1; ++i)
	{

		if (i < qtsCells)
			scanf("%hhd", &campoMinado[i % 3]);
		else
			campoMinado[i % 3] = 0;

		if (i > 0)
			printf("%hhd\n", campoMinado[0] + campoMinado[1] + campoMinado[2]);

	}

}
