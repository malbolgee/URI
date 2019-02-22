/*
	@autor: Malbolge;
	@data: 19/02/2019;
	@nome: Fórmula 1;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 105
#define INF 0x3f3f

typedef unsigned short us;

void main ()
{

	us g, p, i, j, k;
	us grid[MAXSIZE][MAXSIZE], pointS[MAXSIZE], pontos[MAXSIZE];

	while (scanf("%hu %hu", &g, &p), g)
	{

		for (i = 0; i < g; ++i)
			for (j = 0; j < p; ++j)
				scanf("%hu", &grid[i][j]);

		us _system;
		scanf("%hu", &_system);

		while (_system--)
		{

			memset(pontos, 0, sizeof(pontos));
			memset(pointS, 0, sizeof(pointS));

			scanf("%hu", &k);

			for (i = 0; i < k; ++i)
				scanf("%hu", &pointS[i]);

			for (i = 0; i < g; ++i)
				for (j = 0; j < p; ++j)
					pontos[j] += pointS[grid[i][j] - 1];

			us maior = 0;
			for (i = 0; i < p; ++i)
				if (pontos[i] > maior)
					maior = pontos[i];

			_Bool flag = true;

			for (i = 0; i < p; ++i)
				if (pontos[i] == maior)
					if (flag)
						printf("%hu", i + 1), flag = false;
					else
						printf(" %hu", i + 1);

			printf("\n");

		}

	}

}
