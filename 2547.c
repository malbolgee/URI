/*
	@autor: Malbolge;
	@data: 09/12/2018;
	@nome: Montanha-Russa;
*/

#include <stdio.h>

void main ()
{

	unsigned short qtsVisitantes;
	unsigned short alturaMax, alturaMin;
	unsigned short visitante;
	unsigned short i, visitantesHabilitados;

	while (scanf("%hu %hu %hu", &qtsVisitantes, &alturaMin, &alturaMax) != EOF)
	{

		visitantesHabilitados = 0;
		for (i = 0; i < qtsVisitantes; i++)
		{
			scanf("%hu", &visitante);
			if (visitante >= alturaMin && visitante <= alturaMax)
				visitantesHabilitados++;

		}

		printf("%hu\n", visitantesHabilitados);

	}

}
