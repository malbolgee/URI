/*
	@autor: Malbolge;
	@data: 14/02/2019;
	@nome: R+L=J;
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 10
#define T printf("TESTE\n")

typedef long long ll;

void main ()
{

	ll a, b, c;
	char numA[MAXSIZE], numB[MAXSIZE], numC[MAXSIZE];

	while (scanf(" %[^+]+%[^=]=%[^\n]", numA, numB, numC) != EOF)
	{

		if (isdigit(numA[0]) && isdigit(numB[0]))
		{

			a = atoi(numA), b = atoi(numB);
			printf("%lld\n", a + b);

		}
		else if (isdigit(numA[0]) && isdigit(numC[0]))
		{

			a = atoi(numA), c = atoi(numC);
			printf("%lld\n", c - a);

		}
		else
		{

			b = atoi(numB), c = atoi(numC);
			printf("%lld\n", c - b);

		}

	}

}
