/*
    @autor: Malbolge;
    @data: 19/03/2019;
    @nome: Spurs Rocks;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 105

typedef unsigned short us;

typedef struct equipe{

	int qts_pontos;
	int marcadas;
	int sofridas;
	int id;

} equipe;

int compara(equipe *, equipe *);

equipe times[MAXSIZE];

void main ()
{

	int n, i;
	int instancia = 0;
	int id1, id2, pt1, pt2;
	while (scanf("%d", &n))
	{	

		if (n == 0)
			break;
		if (instancia != 0)
			printf("\n");

		us tmp = n * (n - 1) / 2;
		for (i = 0; i < tmp; ++i)
		{

			scanf("%d %d %d %d", &id1, &pt1, &id2, &pt2);

			if (pt1 > pt2) 
				times[id1].qts_pontos += 2,	times[id2].qts_pontos += 1;
			else
				times[id2].qts_pontos += 2,	times[id1].qts_pontos += 1;

			times[id1].marcadas += pt1;
			times[id1].sofridas += pt2;
			times[id2].marcadas += pt2;
			times[id2].sofridas += pt1;
			times[id1].id = id1;
			times[id2].id = id2;

		}

		qsort(&times[1], n, sizeof(equipe), compara);

		_Bool flag = false;
		printf("Instancia %hd\n", ++instancia);
		for (i = 1; i <= n; ++i)
			if (flag)
				printf(" %d", times[i].id);
			else
				printf("%d", times[i].id), flag = true;

		printf("\n");

		memset(times, 0, sizeof(times));

	}

}

int compara(equipe *a, equipe *b)
{

	if (a->qts_pontos == b->qts_pontos)
	{

		if (a->sofridas == 0)
				a->sofridas = 1;
		if (b->sofridas == 0)
				b->sofridas = 1;

		if (a->marcadas / (a->sofridas * 1.0f) == b->marcadas / (b->sofridas * 1.0f))
		{

			if (a->marcadas == b->marcadas)
			{

				if (a->id < b->id)
					return 1;
				else
					return -1;

			}
			else if (a->marcadas > b->marcadas)
				return -1;
			else
				return 1;

		}
		else if (a->marcadas / (a->sofridas * 1.0f) > b->marcadas / (b->sofridas * 1.0f))
			return -1;
		else
			return 1;

	}
	else if (a->qts_pontos > b->qts_pontos)
		return -1;
	else
		return 1;

}