/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Números Apaixornados;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

int compara(long long *, long long *);

void main ()
{

	short flag;
	unsigned n, i;
	long long vetor[MAXSIZE];

	while (scanf("%u", &n) != EOF)
	{

		memset(vetor, 0, sizeof(vetor));

		for (i = 0; i < n; ++i)
			scanf("%lld", &vetor[i]);

		qsort(vetor, n, sizeof(long long), compara);

		flag = 0;
		for (i = 0; i < n && flag < 2;)
		{

			if (vetor[i] == vetor[i + 1] && i < n - 1)
				i += 2;
			else
			{

				printf("%lld", vetor[i]);
				if (flag == 1)
					printf("\n");
				else
					printf(" ");

				++i;
				++flag;

			}

		}

	}

}

int compara(long long *a, long long *b)
{

	if (*a == *b)
		return 0;
	else if (*a > *b)
		return 1;
	else
		return -1;

}
