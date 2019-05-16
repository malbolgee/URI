/*
	@autor: Malbolge;
	@data: 15/05/2019;
	@nome: Triângulo Trinomial, a Vingança;
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define MOD 2147483647LLU

typedef unsigned long long llu;

llu power(llu, llu);

int main (int argc, char **argv)
{

	llu n;
	scanf("%llu", &n);
	printf("%llu\n", power(3, n));

	return 0;

}

llu power(llu a, llu x)
{

	llu ans = 1;
	while (x)
	{

		if (x & 1)
			ans = (ans * a) % MOD;

		a = (a * a) % MOD;
		x >>= 1;

	}

	return ans;

}