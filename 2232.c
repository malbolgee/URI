/*
	@autor: Malbolge;
	@data: 06/10/2018;
	@nome: Triângulo de Pascal;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned short casos;
	unsigned numero;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%u", &numero);

		if (numero == 1)
			printf("1\n");
		else
			printf("%u\n", (unsigned)pow(2, numero) - 1);

	}

}
