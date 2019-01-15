/*
	@autor: Malbolge;
	@data: 13/01/2019;
	@nome: A Mesa Quadrada de Inês Venezuela;
*/

#include <stdio.h>

#define MAX 100000

unsigned long long expNum(unsigned long long, unsigned long long);
unsigned long long mim(unsigned long long, unsigned long long);

void main ()
{

	unsigned i;
	unsigned long long a, b;
	unsigned long long fatores, expA, expB;

	scanf("%llu %llu", &a, &b);

	fatores = 1;

	for (i = 2; i < MAX; ++i)
	{

		expA = expB = 0;
		while (a % i == 0)
			++expA, a /= i;

		while (b % i == 0)
			++expB, b /= i;

		fatores *= expNum(i, ((mim(expA, expB) + (mim(expA, expB) % 2)) / 2));

	}

	if (a == b)
		fatores *= a;

	printf("%llu\n", fatores);

}

unsigned long long mim(unsigned long long a, unsigned long long b)
{

	if (a < b)
		return a;
	else
		return b;

}

unsigned long long expNum(unsigned long long x, unsigned long long y)
{

	unsigned i;
	unsigned long long retorno = 1;

	for (i = 0; i < y; ++i)
		retorno *= x;

	return retorno;

}
