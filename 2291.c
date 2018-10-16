/*
	@autor: Malbolge;
	@data: 15/10/2018
	@nome: Números Divinos;
*/

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 1000000

unsigned long long somaDivisores[MAXSIZE];

void crivo();

void main ()
{

	unsigned long long numero;
	crivo();

	while (true)
	{

		scanf("%llu", &numero);

		if (numero == 0)
			break;

		printf("%llu\n", somaDivisores[numero]);

	}

}

void crivo()
{
	unsigned long long i, j;

	for (i = 1; i <= MAXSIZE; i++)
		for (j = i; j <= MAXSIZE; j += i)
			somaDivisores[j] += i;

	for (i = 2; i <= MAXSIZE; i++)
		somaDivisores[i] += somaDivisores[i - 1];

}
