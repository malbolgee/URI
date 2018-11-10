/*
	@autor: Malbolge;
	@data: 10/11/2018;
	@nome: O Elfo das Trevas;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct rena{

	char nome[150];
	unsigned short peso;
	unsigned short idade;
	float altura;

} rena;

int compara(const void *a, const void *b);

void main ()
{

	unsigned short numTotalRenas, numTotalRenasTreno;
	unsigned short i, cenario;
	unsigned casos;

	scanf("%u", &casos);

	cenario = 0;
	while (casos--)
	{

		scanf("%hu %hu", &numTotalRenas, &numTotalRenasTreno);

		rena renas[numTotalRenas];

		for (i = 0; i < numTotalRenas; i++)
			scanf(" %s %hu %hu %f", renas[i].nome, &renas[i].peso, &renas[i].idade, &renas[i].altura);

		qsort(renas, numTotalRenas, sizeof(rena), compara);

		printf("CENARIO {%hu}\n", ++cenario);
		for (i = 0; i < numTotalRenasTreno; i++)
			printf("%hu - %s\n", i + 1,renas[i].nome);

	}

}

int compara(const void *a, const void *b)
{

	if ((*(struct rena*)a).peso == (*(struct rena*)b).peso)
	{
		if ((*(struct rena*)a).idade == (*(struct rena*)b).idade)
		{
			if ((*(struct rena*)a).altura == (*(struct rena*)b).altura)
			{
				if (strcmp((*(struct rena*)a).nome, (*(struct rena*)b).nome) == 0)
					return 0;
				else if ((strcmp((*(struct rena*)a).nome, (*(struct rena*)b).nome) > 0))
					return 1;
				else
					return -1;
			}
			else if ((*(struct rena*)a).altura < (*(struct rena*)b).altura)
				return -1;
			else
				return 1;
		}
		else if ((*(struct rena*)a).idade < (*(struct rena*)b).idade)
			return -1;
		else
			return 1;
	}
	else if ((*(struct rena*)a).peso > (*(struct rena*)b).peso)
		return -1;
	else
		return 1;
}
