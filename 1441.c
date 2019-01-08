/*
	@autor: Malbolge;
	@data: 08/01/2019;
	@nome: Sequências de Granizo;
*/

#include <stdio.h>

#define true 1
#define false 0

void main ()
{
	long long maior, valorAtual;
	unsigned short valorInicial;

	while (true)
	{

		scanf("%hu", &valorInicial);

		if (valorInicial == 0)
			break;

		maior = valorInicial;
		while (valorInicial != 1)
		{

			if (valorInicial & 1)
				valorInicial = (valorInicial * 3) + 1;
			else
				valorInicial = valorInicial / 2;

			if (valorInicial > maior)
				maior = valorInicial;

		}

		printf("%lld\n", maior);

	}

}
