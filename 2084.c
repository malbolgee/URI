/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Eleições;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int compara(int *, int *);

void main ()
{

	int n, i;
	int votos, pos;
	double vote45, vote40, vote10, divv;

	scanf("%d", &n);

	int vet[n];

	votos = 0;
	for (i = 0; i < n; ++i)
		scanf("%d", &vet[i]), votos += vet[i];

	qsort(vet, n, sizeof(int), compara);
	pos = n - 1;

	vote45 = (45 * votos * 1.00f) / 100.00f;
	vote40 = (40 * votos * 1.00f) / 100.00f;
	vote10 = (10 * votos * 1.00f) / 100.00f;

	if (vet[pos] >= vote45)
		printf("1\n");
	else if (vet[pos] < vote40)
		printf("2\n");
	else if (vet[pos] >= vote40)
	{

		_Bool flag = false;
		for (i = 0; i < pos; ++i)
		{

			divv = vet[pos] - vet[i];
			if (divv >= vote10)
				continue;
			else
			{

				flag = true;
				break;

			}

		}

		printf("%c\n", flag ? '2' : '1');

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
