/*
	@autor: Malbolge;
	@data: 24/12/2018;
	@nome: Maratona;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void main ()
{

	unsigned i;
	bool termina = true;
	unsigned atual, anterior;
	int qtsPostos, distIntMax;

	scanf("%u %u", &qtsPostos, &distIntMax);

	anterior = 0;
	for (i = 0; i < qtsPostos; ++i)
	{

		scanf("%u", &atual);
		if ((atual - anterior) > distIntMax)
			termina = false;

		anterior = atual;

	}

	if (termina && (42195 - anterior <= distIntMax))
		printf("S\n");
	else
		printf("N\n");

}
