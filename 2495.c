/*
	@autor: Malbolge;
	@data: 09/01/2019;
	@nome: Onde Está Minha Caneta?;
*/

#include <stdio.h>

void main ()
{

	unsigned i;
	unsigned long long numCanetas;
	unsigned long long soma, somaTotal, tmp;

	while (scanf("%llu", &numCanetas) != EOF)
	{

		somaTotal = (numCanetas * (numCanetas + 1)) / 2;

		soma = 0;
		for (i = 1; i < numCanetas; ++i)
		{

			scanf("%llu", &tmp);
			soma += tmp;

		}

		printf("%lld\n", somaTotal - soma);

	}
}
