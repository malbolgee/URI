/*
	@autor: Malbolge;
	@data: 29/01/2019;
	@nome: Tetris;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAX 1100
#define INF 0x3f3f3f
#define A competidores[i].pontos
#define C competidores[i].nome

typedef struct pessoa{

	char nome[30];
	unsigned short pontos;

} pessoa;

pessoa competidores[MAX];

int compara(pessoa *, pessoa *);

void main ()
{

	int tmp;
	int maior, menor, pos;
	unsigned short i, j, teste = 0;
	unsigned short qtsCompetidores;

	while (scanf("%hu", &qtsCompetidores), qtsCompetidores)
	{

		memset(competidores, 0, sizeof(competidores));

		for (i = 0; i < qtsCompetidores; ++i)
		{

			scanf("%s", competidores[i].nome);

			maior = -INF; menor = INF;
			for (j = 0; j < 12; ++j)
			{

				scanf("%d", &tmp);
				if (tmp > maior)
					maior = tmp;
				if (tmp < menor)
					menor = tmp;

				competidores[i].pontos += tmp;

			}

			competidores[i].pontos -= (menor + maior);

		}

		qsort(competidores, qtsCompetidores, sizeof(pessoa), compara);

		maior = INF;
		printf("Teste %hu\n", ++teste);
		for (i = 0, pos = 1; i < qtsCompetidores; ++i)
		{

			if (A != maior)
				pos = i + 1;

			printf("%hu %u %s\n", pos, A, C);
			maior = A;

		}
		
		printf("\n");

	}

}

int compara(pessoa *a, pessoa *b)
{

	if (a->pontos == b->pontos)
	{

		if (strcmp(a->nome, b->nome) == 0)
			return 0;
		else if (strcmp(a->nome, b->nome) > 0)
			return 1;
		else
			return -1;

	}
	else if (a->pontos > b->pontos)
		return -1;
	else
		return 1;

}
