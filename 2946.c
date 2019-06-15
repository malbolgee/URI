/*
	@autor: Malbolge;
	@data: 01/06/2019;
	@nome: Dabriel e a divisibilidade;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

unsigned vet[15];

int compara(int *a, int *b);
_Bool check(char *s1, unsigned x);

int main(int argc, char **argv)
{

	unsigned n, x;
	unsigned ans = 0;
	char num[100050];

	scanf("%s", num);
	scanf("%u", &n);

	unsigned i, tam = 0;
	for (i = 0; i < n; ++i)
	{

		scanf("%u", &x);

		if (check(num, x))
			vet[tam++] = x;

	}

	qsort(vet, tam, sizeof(unsigned), compara);

	if (!tam)
		puts("Nenhum");
	else
	{

		_Bool flag = false;
		for (i = 0; i < tam; ++i)
		{

			if (flag)
				printf(" %u", vet[i]);
			else
				printf("%d", vet[i]), flag = true;

		}

		printf("\n");

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

_Bool check(char *s1, unsigned x)
{

	unsigned i = 0;
	unsigned resto = 0;
	while (s1[i])
	{

		if ((s1[i] - '0') == 1)
			resto = (resto * 2 + 1) % x;
		if ((s1[i] - '0') == 0)
			resto = (resto * 2) % x;

		i++;
	}

	if (resto % x == 0)
		return true;
	else
		return false;

}