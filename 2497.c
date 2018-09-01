/*
	@autor: Malbolge;
	@data: 01/09/2018;
	@nome: Contando Ciclos;
*/

#include <stdio.h>

void main (void)
{

	short casos, experimentos = 0, ciclos = 0;
	unsigned short estados = 0;

	while (1)
	{

		scanf("%hd", &casos);

		if (casos == -1)
			break;

		while (casos)
		{

			estados++; 

			if (estados % 2 == 0)
				ciclos++;

			casos--;
		}

		experimentos++;
		printf("Experiment %d: %d full cycle(s)\n", experimentos, ciclos);
		estados = 0;
		ciclos = 0;
	}
}