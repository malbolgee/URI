/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: Jogo do Maior;
*/


#include <stdio.h>

void main ()
{

	unsigned short casos, numA, numB, maior;
	unsigned short pontosA = 0, pontosB = 0;

	while (1)
	{
		scanf("%hu", &casos);

		if (casos == 0)
			break;

		while (casos--)
		{

			scanf("%hu %hu", &numA, &numB);

			if (numA > numB)
				pontosA++;
			else if (numB > numA)
				pontosB++;

		}

		printf("%hu %hu\n", pontosA, pontosB);
		pontosA = 0;
		pontosB = 0;

	}
}