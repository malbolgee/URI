/*

    @autor: Malbolge;
    @data: 13/12/2019;
    @nome: Reunião;

*/

#include <stdio.h>

#define MAXSIZE 110
#define INFINITY 100000

int dist[MAXSIZE][MAXSIZE];

inline int min(int, int);

int main(int argc, char **argv)
{

	int n, m;
	int i, j, k, w;

	scanf("%d %d", &n, &m);

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			dist[i][j] = INFINITY;

	for (i = 0; i < n; ++i)
		dist[i][i] = 0;

	for (i = 0; i < m; ++i)
	{

		scanf("%d %d %d", &j, &k, &w);
		dist[j][k] = dist[k][j] = w;

	}

	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			for (k = 0; k < n; ++k)
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	
	int maior = -1;
	int menor = INFINITY;

	for (i = 0; i < n; ++i)
	{

		maior = -1;
		for (j = 0; j < n; ++j)
			if (dist[i][j] > maior && dist[i][j] != INFINITY)
				maior = dist[i][j];

		if (menor > maior && maior > 0)
			menor = maior;

	}

	printf("%d\n", menor);

	return 0;

}

int min(int a, int b)
{

	return a < b ? a : b;

}