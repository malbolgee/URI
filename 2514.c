/*
	@autor: Malbolge;
	@data: 18/01/2019;
	@nome: Alinhamento Lunar;
*/

#include <stdio.h>

int mdc(int a, int b);

void main ()
{

	int g, c;
	int l1, l2, l3;
	int anosQueVirao;
	int anosPassados;

	while (scanf("%d", &anosPassados) != EOF)
	{

		scanf("%d %d %d", &l1, &l2, &l3);
		g = mdc(l1, l2);
		g = (l1 * l2) / g;
		c = mdc(g, l3);
		anosQueVirao = (l3 * g) / c;
		printf("%d\n", anosQueVirao - anosPassados);

	}

}

int mdc(int a, int b)
{

	int resto = a % b;

	while (resto != 0)
	{

		a = b;
		b = resto;
		resto = a % b;

	}

	return b;

}
