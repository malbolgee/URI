/*
	@autor: Malbolge;
	@data: 31/03/2019;
	@nome: Promessa de Campanha;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 101
#define ABS(a) a > 0 ? a : -a

typedef unsigned short us;

_Bool flag;
_Bool visitados[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];

short n, m;
void dfs(short);

void main ()
{

	short i;
	char t;
	short caso = 0;

	scanf("%hhd", &t);

	while (t--)
	{

		scanf("%hd %hd", &n, &m);
		for (i = 0; i < m; ++i)
		{

			short a, b;
			scanf("%hd %hd", &a, &b);
			adj[a][b] = 1;
			adj[b][a] = 1;

		}

		printf("Caso #%hd: ", ++caso);
		short ans = 0;
		dfs(1);
		for (i = 1; i <= n; ++i)
			if (!visitados[i])
				++ans, dfs(i);

		if (!ans)
			puts("a promessa foi cumprida");
		else
			printf("ainda falta(m) %hd estrada(s)\n", ans);

		memset(adj, 0, sizeof(adj));
		memset(visitados, false, sizeof(visitados));
			
	}

}

void dfs(short u)
{

	short i;
	visitados[u] = true;
	for (i = 1; i <= n; ++i)
		if (adj[u][i])
			if (!visitados[i])
				dfs(i);

}