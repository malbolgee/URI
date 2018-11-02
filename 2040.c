/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: O Campeão;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	char nomeTime[100];
	unsigned short qtsPontos;

} equipe;

unsigned short procuraTime(equipe *campeonato, char *jogoTime, unsigned short tam);
void ordena(equipe *campeonato, unsigned short tam);


void main ()
{
	char jogoTimeA[100], jogoTimeB[100];
	unsigned short golTimeA, golTimeB;
	unsigned short qtsTimes, aux;
	unsigned short i;

	while(true)
	{

		scanf("%hu", &qtsTimes);

		if (qtsTimes == 0)
			break;

		equipe campeonato[qtsTimes];
		for (i = 0; i < qtsTimes; i++)
			scanf(" %s %hu", campeonato[i].nomeTime, &campeonato[i].qtsPontos);

		aux = qtsTimes / 2;
		for (i = 0; i < aux; i++)
		{

			scanf(" %s %hu-%hu %s", jogoTimeA, &golTimeA, &golTimeB, jogoTimeB);

			// Os gols marcados por cada equipe valem 3 pontos cada;
			// Incremento os pontos do time na posição em que ele foi inserido
			// Essa posição é dada pelo retorno da funcão procuraTime(), definida na linha 78;
			campeonato[procuraTime(campeonato, jogoTimeA, qtsTimes)].qtsPontos += golTimeA * 3;
			campeonato[procuraTime(campeonato, jogoTimeB, qtsTimes)].qtsPontos += golTimeB * 3;

			
			if (golTimeA > golTimeB)
				campeonato[procuraTime(campeonato, jogoTimeA, qtsTimes)].qtsPontos += 5;
			else if (golTimeB > golTimeA)
				campeonato[procuraTime(campeonato, jogoTimeB, qtsTimes)].qtsPontos += 5;
			else
			{

				campeonato[procuraTime(campeonato, jogoTimeA, qtsTimes)].qtsPontos += 1;
				campeonato[procuraTime(campeonato, jogoTimeB, qtsTimes)].qtsPontos += 1;

			}

		}

		// Ordenando de forma descrecente pela quantidade de pontos, quem tem mais pontos
		// Fica na primeira posição;
		// Essa função está definida na linha 93;
		ordena(campeonato, qtsTimes);

		if (strcmp(campeonato[0].nomeTime, "Sport") == 0)
			printf("O Sport foi o campeao com %hu pontos :D\n\n", campeonato[0].qtsPontos);
		else
			printf("O Sport nao foi o campeao. O time campeao foi o %s com %hu pontos :(\n\n", campeonato[0].nomeTime, campeonato[0].qtsPontos);

	}
}

// Função procura a posição da um time no vetor de times;
unsigned short procuraTime(equipe *campeonato, char *jogoTime, unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (strcmp(campeonato[i].nomeTime, jogoTime) == 0)
			return i;

}

// Função para ordenar;
void ordena(equipe *campeonato, unsigned short tam)
{

	short i = 1, j;
	equipe pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = campeonato[i];

		while (j >= 0 && campeonato[j].qtsPontos < pivo.qtsPontos)
		{

			campeonato[j + 1] = campeonato[j];
			j--;

		}

		campeonato[j + 1] = pivo;
		i++;

	}

}
