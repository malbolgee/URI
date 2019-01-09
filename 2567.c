/*
	@autor: Malbolge;
	@data: 08/01/2019;
	@nome: Virus;
*/

#include <stdio.h>
#include <stdlib.h>

int compara(int *, int *);

void main ()
{

	int soma;
	int n, i, j;

	while (scanf("%u", &n) != EOF)
	{

		int vetor[n];

		for (i = 0; i < n; ++i)
			scanf("%d", &vetor[i]);

		qsort(vetor, n, sizeof(int), compara);

		j = n - 1;
		soma = i = 0;

		while (j > i)
			soma += abs(vetor[i++] - vetor[j--]);

		printf("%d\n", soma);

	}

}

int compara(int *a, int *b)
{

	if (*a == *b)
		return 0;
	else if (*a > *b)
		return 1;
	else
		return -1;

}
