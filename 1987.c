/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: Divisibilidade Por 3;
*/


#include <stdio.h>
#include <stdbool.h>


void main ()
{

	unsigned soma = 0, numAlg, algarismos;
	bool multiplo = false;


	while (scanf("%u %u", &numAlg, &algarismos) != EOF)
	{

		if (algarismos % 3 == 0)
			multiplo = true;

		while (algarismos)
		{

			soma += algarismos%10;
			algarismos /= 10;

		}

		if (multiplo)
			printf("%u sim\n", soma);
		else
			printf("%u nao\n", soma);

		soma = 0;
		multiplo = false;

	}

}