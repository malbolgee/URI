/*
	@autor: Malbolge;
	@data: 10/01/2019;
	@nome: A Nota;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD	1000000007
#define MAXSIZE 1100000

int compara(unsigned *, unsigned *);

void main ()
{

	unsigned i;
	long long soma;
	unsigned qtsNotas, k;
	unsigned notas[MAXSIZE];

	while (scanf("%u %u", &qtsNotas, &k) != EOF)
	{

		memset(notas, 0, sizeof(notas));

		for (i = 0; i < qtsNotas; ++i)
			scanf("%u", &notas[i]);

		qsort(notas, qtsNotas, sizeof(unsigned), compara);

		soma = 0;
		for (i = 0; i < k; ++i)
			soma = ((soma % MOD) + (notas[i] % MOD)) % MOD;

		printf("%lld\n", soma);

	}

}

int compara(unsigned *a, unsigned *b)
{

	if (*a == *b)
		return 0;
	else if (*a < *b)
		return 1;
	else
		return -1;

}
