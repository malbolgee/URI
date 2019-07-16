/*
	@autor: Malbolge;
	@data: 15/07/2019;
	@nome: Laércio;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int compara(unsigned *, unsigned *);
int compara2(unsigned *, unsigned *);

int main (int argc, char **argv)
{
	
	unsigned i, j, tmp;
	unsigned n, c, k, z;

	scanf("%u", &c);

	while(c--)
	{

		scanf("%u", &n);

		unsigned vet1[n];
		unsigned vet2[n];
		for (i = 0, j = 0; i < n; ++i)
		{

			scanf("%u", &tmp);

			if (tmp % 2 != 0)
				vet1[j] = vet2[j] = tmp, ++j;

		}

		qsort(vet1, j, sizeof(unsigned), compara);
		qsort(vet2, j, sizeof(unsigned), compara2);

		k = z = 0;
		_Bool flag = false;
		for (i = 0; i < j; ++i)
		{
			
			if (i % 2 == 0)
				if (flag)
					printf(" %u", vet2[k++]);
				else
					printf("%u", vet2[k++]), flag = true;
			else
				if (flag)
					printf(" %u", vet1[z++]);
				else
					printf("%u", vet1[z++]), flag = true;

		}

		printf("\n");

	}

	return 0;

}

int compara(unsigned *a, unsigned *b)
{

	return *a - *b;

}

int compara2(unsigned *a, unsigned *b)
{

	return *b - *a;

}