/*
	@autor: Malbolge;
	@data: 20/01/2019;
	@nome: Onde Estão Minhas Chaves;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAX	1100

void main ()
{

	unsigned short vetor[MAX];
	unsigned short i, q, e, tmp;

	while (scanf("%hu %hu", &q, &e) != EOF)
	{

		for (i = 0; i < e; ++i)
			scanf("%hu", &tmp), vetor[tmp] = tmp;

		for (i = 0; i < q; ++i)
		{

			scanf("%hu", &tmp);
			if (tmp == vetor[tmp])
				printf("0\n");
			else
				printf("1\n"), vetor[tmp] = tmp;

		}

	}

}
