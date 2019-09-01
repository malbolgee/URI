/*
	@autor: Malbolge;
	@data: 01/09/2019;
	@nome: Casas de Westeros;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1010

int bor[MAXSIZE];
char vis[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];

int n;
int vertices, arestas;

void dfs(int);
int compare(int *, int *b);

int main(int argc, char **argv)
{

	int i, j;
	char c[MAXSIZE];

	scanf("%d%*c", &n);

	for (i = 0; i < n; ++i)
	{

		scanf("%s", c);
		for (j = 0; c[j]; ++j)
			if (i != j && c[j] == 'S')
				adj[i][j] = true, ++bor[i];

	}

	int ans[MAXSIZE];

	for (i = j = 0; i < n; ++i)
	{

		if (!vis[i])
		{

			vertices = arestas = 0;
			dfs(i);

			if (vertices * (vertices - 1) != arestas)
			{

				puts("-1");
				return 0;

			}

			ans[j++] = vertices;

		}

	}

	qsort(ans, j, 4, compare);

	printf("%d\n", j);
	for (i = 0; i < j; ++i)
		printf("%d%c", ans[i], i < j - 1 ? ' ' : '\n');

	return 0;

}

void dfs(int u)
{

	int i;
	vis[u] = true;	
	++vertices;
	arestas += bor[u];

	for (i = 0; i < n; ++i)
		if (adj[u][i])
			if (!vis[i])
				dfs(i);

}


int compare(int *a, int *b)
{

	return *b - *a;

}