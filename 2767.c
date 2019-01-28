/*
	@autor: Malbolge;
	@data: 23/01/2019;
	@nome: Festa;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

void main ()
{

	unsigned i;
	unsigned n, m, k;
	int pares[MAXSIZE];
	unsigned homem, mulher;

	while (scanf("%d %d %d", &n, &m, &k) != EOF)
	{

		memset(pares, 0, sizeof(pares));

		for (i = 0; i < n; ++i)
		{

			scanf("%d", &homem);
			pares[homem % k]++;

		}

		long long soma = 0;
		for (i = 0; i < m; ++i)
		{

			scanf("%d", &mulher);
			soma += pares[(k - (mulher % k)) % k];

		}

		printf("%lld\n", soma);

	}

}
