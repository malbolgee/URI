/*
	@autor: Malbolge;
	@data: 26/09/2018;
	@nome: Cara ou Coroa;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned char numero;
	unsigned short mary = 0, john = 0, casos;

	while (true)
	{

		scanf("%hu", &casos);

		if (casos == 0)
			break;

		mary = john = 0;
		while (casos--)
		{

			scanf("%hhd", &numero);

			if (numero == 0)
				mary++;
			else
				john++;
		}

		printf("Mary won %hu times and John won %hu times\n", mary, john);

	}
}