/*
	@autor: Malbolge;
	@data: 20/01/2019;
	@nome: Sequência IccanobiF;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX 100

long long fib[MAX];

void preenche();
long long invert(long long);

void main ()
{

	long long x;

	preenche();
	while (scanf("%lld", &x) != EOF)
		printf("%lld\n", x == 0 ? 0 : fib[x]);

}

void preenche()
{

	long long i;

	fib[0] = 1;
 	for (i = 1; i <= 60; ++i)
		fib[i] = invert(fib[i - 1]) + invert(fib[i - 2]);

}

long long invert(long long x)
{

	int i;
	char string[100] = { 0 };

	i = 0;
	while (x)
		string[i++] = (x % 10) + 48, x /= 10;

	return atoll(string);

}
