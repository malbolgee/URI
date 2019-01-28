/*
	@autor: Malbolge;
	@data: 28/01/2019;
	@nome: Museu Virtual 3D;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX 1100

void main ()
{

	short i;
	unsigned soma;
	unsigned short n, m;
	unsigned short vetor[MAX];

	while (scanf("%hu %hu", &n, &m) != EOF)
	{

		for (i = 0; i < n; ++i)
			scanf("%hu", &vetor[i]);

		soma = 0;
		for (i = 1; i <= m; ++i)
			soma += vetor[n - i];

		printf("%u\n", soma);

	}

}
