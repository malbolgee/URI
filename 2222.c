/*
	@autor: Malbolge;
	@data: 19/05/2019;
	@nome: Brincando com Conjuntos;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MIN(x, y) x < y ? x : y
#define MAX(x, y) x > y ? x : y

int grid[10010][65];

int funion(int, int);
int fintersection(int, int);

int main(int argc, char **argv)
{

	int t, n, i, j, k;
	scanf("%d", &t);

	while (t--)
	{

		scanf("%d", &n);
		memset(grid, 0, sizeof(grid));

		for (i = 0; i < n; ++i)
		{

			scanf("%d", &j);
			while (j--)
				scanf("%d", &k), grid[i][k] = 1;

		}

		scanf("%d", &n);
		while (n--)
		{

			scanf("%d %d %d", &k, &i, &j);
			printf("%d\n", k == 1 ? fintersection(--i, --j) : funion(--i, --j));

		}

	}

	return 0;

}

int fintersection(int x, int y)
{

	int i, soma = 0;
	for (i = 1; i <= 60; ++i)
		soma += MIN(grid[x][i], grid[y][i]);

	return soma;

}

int funion(int x, int y)
{

	int i, soma = 0;
	for (i = 1; i <= 60; ++i)
		soma += MAX(grid[x][i], grid[y][i]);

	return soma;

}