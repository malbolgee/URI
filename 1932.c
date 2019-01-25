/*
	@autor: Malbolge;
	@data: 22/01/2019;
	@nome: Bolsa de Valores;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 200100

unsigned lucroMaximo(int *, int, int);

void main ()
{

	unsigned i;
	int dias, taxa;
	int bolsa[MAXSIZE];

	scanf("%d %d", &dias, &taxa);

	for (i = 0; i < dias; ++i)
		scanf("%d", &bolsa[i]);

	printf("%u\n", lucroMaximo(bolsa, dias, taxa));


}

unsigned lucroMaximo(int *bolsa, int dias, int taxa)
{

	unsigned i;
	int lucroAtual, lucroFinal, lucroMaximo;

	lucroMaximo = 0;
	lucroAtual = lucroFinal = bolsa[0];
	for (i = 1; i < dias; ++i)
	{

		if ((lucroAtual > bolsa[i] && (lucroAtual - bolsa[i] >= taxa)) || bolsa[i] < lucroFinal)
		{

			if (lucroAtual - lucroFinal - taxa > 0)
				lucroMaximo += lucroAtual - lucroFinal - taxa;

			lucroAtual = lucroFinal = bolsa[i];

		}

		if (bolsa[i] > lucroAtual)
			lucroAtual = bolsa[i];

	}

	if (lucroAtual - lucroFinal - taxa > 0)
		lucroMaximo += lucroAtual - lucroFinal - taxa;

	return lucroMaximo;

}
