/*
	@autor: Malbolge;
	@data: 23/10/2018;
	@nome: Evento;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned long qtsXp, multiplicador;

	while (true)
	{

		scanf("%lu %lu", &multiplicador, &qtsXp);

		if (multiplicador == 0 && qtsXp == 0)
			break;

		printf("%lu\n", qtsXp * multiplicador);



	}



}
