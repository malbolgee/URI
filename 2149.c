/*
	@autor: Malbolge;
	@data: 01/02/2019;
	@nome: Sequência do Tio Phill Bonati;
*/

#include <stdio.h>
#define MAX	20

unsigned long long fib[MAX];

void preenche();

void main ()
{

	int n;
	preenche();

	while (scanf("%d", &n) != EOF)
		printf("%llu\n", fib[n]);

}

void preenche()
{

	int i;
	fib[1] = 0;
	fib[2] = 1;
	for (i = 3; i <= MAX; ++i)
		if (i % 2 == 0)
			fib[i] = fib[i - 1] * fib[i - 2];
		else
			fib[i] = fib[i - 1] + fib[i - 2];

}
