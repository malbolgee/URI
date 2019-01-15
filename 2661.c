/*
	@autor: Malbolge;
	@data: 13/01/2019;
	@nome: Despojados;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned long long numero;
	unsigned long long fatores, limite;

	scanf("%llu", &numero);

	limite = 2;
	fatores = 0;

	// Um número 'N' é divisor de 'S' se e somente se em sua fatoração
	// Não existe um número primo que não está presente nos fatores de 'S'
	// E os expoentes dos fatores de 'N' são todos menores ou iguais ao expoente
	// do fator correspodente de 'S';
	while (limite * limite <= numero)
	{

		if (numero % limite == 0)
		{

			++fatores;
			while (numero % limite == 0)
				numero /= limite;

		}

		++limite;

	}

	if (numero != 1)
		++fatores;

	printf("%llu\n", (1l << fatores) - fatores - 1);
}
