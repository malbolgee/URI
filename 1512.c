/*
	@autor: Malbolge;
	@data: 04/06/2019;
	@nome: Azulejos;
*/

#include <stdio.h>

#define true 1
#define false 0

#define MMC(a, b) ((a / mdc(a, b)) * b)

unsigned mdc(unsigned, unsigned);

typedef long long unsigned llu;

int main(int argc, char **argv)
{

	llu n, a, b;

	while (scanf("%llu %llu %llu", &n, &a, &b), n)
		printf("%llu\n", ((n / a) + (n / b)) - n / MMC(a, b));

	return 0;

}

unsigned mdc(unsigned a, unsigned b)
{

	unsigned resto = a % b;
	while (resto)
	{

		a = b;
		b = resto;
		resto = a % b;

	}

	return b;

}
