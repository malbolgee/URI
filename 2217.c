/*
	@autor: Malbolge;
	@data: 04/10/2018;
	@nome: Nove;
*/

#include <stdio.h>

void main ()
{

	unsigned long numero;
	unsigned short casos;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%lu", &numero);

		if (numero % 2 == 0)
			printf("1\n");
		else
			printf("9\n");

	}


}	
