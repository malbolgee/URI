/*
	@autor: Malbolge;
	@data: 29/09/2018;
	@nome: Roberto e a Sala Desenfreada;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	unsigned short engProd, engHidr, intrusos;
	unsigned short casos, matricula;

	while (scanf("%hu", &casos) != EOF)
	{
		char turma[100];

		engProd = engHidr = intrusos = 0;
		while (casos--)
		{

			scanf("%hu %s", &matricula, turma);

			if (strcmp(turma, "EPR") == 0)
				engProd++;
			else if (strcmp(turma, "EHD") == 0)
				engHidr++;
			else
				intrusos++;

		}


		printf("EPR: %hu\nEHD: %hu\nINTRUSOS: %hu\n", engProd, engHidr, intrusos);

	}
}