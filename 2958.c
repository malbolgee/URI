/*
    @autor: Malbolge;
    @data: 17/09/2019;
    @nome: O Rolê Bad Vibes;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int compare(int *, int *);


int main(int argc, char **argv)
{

	char c;
	int n, m, x, i, k, j;
	scanf("%d %d", &n, &m);
	x = n * m;

	int vet[x];
	int vet2[x];

	for (i = j = k = 0; i < x; ++i)
	{

		scanf("%d%c", &n, &c);
		if (c == 'V')
			vet[j++] = (n * 100) + c;
		else
			vet2[k++] = (n * 100) + c;

	}

	qsort(vet, j, 4, compare);
	qsort(vet2, k, 4, compare);

	for (i = 0; i < j; ++i)
		printf("%d%c\n", vet[i] / 100, (char)(vet[i] % 100));

	for (i = 0; i < k; ++i)
		printf("%d%c\n", vet2[i] / 100, (char)(vet2[i] % 100));

	return 0;

}

int compare(int *a, int *b)
{

	return *b - *a;

}