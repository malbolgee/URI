/*
	@autor: Malbolge;
	@data: 27/01/2018;
	@nome: Carteiro;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX 45100
long casas[MAX];
long cartas[MAX];

int busca(long *, long, long);

void main ()
{
	long tmp;
	long i, x, z;
	long n, m, tempo;

	scanf("%ld %ld", &n, &m);

	for (i = 1; i <= n; ++i)
		scanf("%ld", &casas[i]);

	z = 1;
	tempo = 0;
	for (i = 1; i <= m; ++i)
	{

		scanf("%ld", &tmp);
		x = busca(casas, n, tmp);
		tempo += abs(x - z);
		z = x;

	}

	printf("%ld\n", tempo);

}

int busca(long *casas, long tam, long chave)
{

	int hi, low, mid;

	hi = tam; low = 1;
	while (low <= hi)
	{

		mid = (low + hi) / 2;

		if (chave < casas[mid])
			hi = mid - 1;
		else if (chave > casas[mid])
			low = mid + 1;
		else
			return mid;

	}

	return -1;

}
