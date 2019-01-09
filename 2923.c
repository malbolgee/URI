/*
	@autor: Malbolge;
	@data: 09/01/2019;
	@nome: Birinho;
*/

#include <stdio.h>

void main ()
{

	unsigned warning, critical;
	unsigned tamTotal, tamUtilizado;

	while (scanf("%u %u %u %u", &tamTotal, &tamUtilizado, &warning, &critical) != EOF)
	{

		if ((tamUtilizado * 100.0f) / tamTotal >= critical)
			printf("critical\n");
		else if ((tamUtilizado * 100.0f) / tamTotal >= warning)
			printf("warning\n");
		else
			printf("OK\n");

	}

}
