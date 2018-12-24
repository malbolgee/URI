/*
	@autor: Malbolge;
	@data: 24/12/2018;
	@nome: Número Solitário;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compara(const void *a, const void *b);

void main ()
{

	unsigned long long i;
	unsigned long long qtsElementos;

	while (true)
	{

		scanf("%llu", &qtsElementos);

		if (qtsElementos == 0)
			break;

		unsigned long long set[qtsElementos];

		for (i = 0; i < qtsElementos; ++i)
			scanf("%llu", &set[i]);

		qsort(set, qtsElementos, sizeof(unsigned long long), compara);

		for (i = 0; i < qtsElementos; i += 2)
			if (set[i] != set[i + 1])
				break;

		printf("%llu\n", set[i]);

	}

}

int compara(const void *a, const void *b)
{

	if (*(int *)a == *(int *)b)
		return 0;
	else if (*(int *)a > *(int *)b)
		return 1;
	else
		return -1;

}
