/*
	@autor: Malbolge;
	@data: 01/10/2018;
	@nome: Churras no Yuri;
*/

#include <stdio.h>

typedef struct{

	char carne[21];
	unsigned short validade;

} friboi;

void ordena(friboi *, unsigned short tam);

void main ()
{

	unsigned short qtsCarnes, i;


	while (scanf("%hu", &qtsCarnes) != EOF)
	{

		friboi churrasco[qtsCarnes];

		for (i = 0; i < qtsCarnes; i++)
			scanf("%s %hu", churrasco[i].carne, &churrasco[i].validade);

		ordena(churrasco, qtsCarnes);

		for (i = 0; i < qtsCarnes; i++)
		{
			if (i != 0 && i != qtsCarnes)
				printf(" ");

			printf("%s", churrasco[i].carne);

		}

		printf("\n");
	}

}

void ordena(friboi *churrasco, unsigned short tam)
{

	short i = 1, j;
	friboi pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = churrasco[i];

		while (j >= 0 && churrasco[j].validade > pivo.validade)
		{

			churrasco[j + 1] = churrasco[j];
			j--;

		}
		churrasco[j + 1] = pivo;
		i++;

	}

}
