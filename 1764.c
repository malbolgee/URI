/*

	@autor: Malbolge;
	@data: 14/06/2019;
	@nome: Itinerário do Papai Noel;

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 40050
#define MAXSIZE_P 40000

typedef struct {

	int u, v, w;

} edge;

edge g[MAXSIZE];
int p[MAXSIZE_P];

int compara(edge *, edge *);
int kruskal(int);
int componente(int);

int main(int argc, char **argv)
{

	int m, n, i;

	while (scanf("%d %d", &m, &n), m && n)
	{

		memset(g, 0, sizeof(g));
		memset(p, 0, sizeof(p));

		for (i = 0; i < n; ++i)
			scanf("%d %d %d", &g[i].v, &g[i].u, &g[i].w);

		qsort(g, n, sizeof(edge), compara);

		for (i = 1; i <=m ; ++i)
			p[i] = i;

		printf("%d\n", kruskal(n));

	}

	return 0;

}

int compara(edge *a, edge *b)
{

	return a->w - b->w;
	
}

int componente(int __i)
{

	if (__i == p[__i])
		return __i;

	return componente(p[__i]);

}

int kruskal(int __c)
{

	int i, ans, v, u;

	for (i = 0, ans = 0; i < __c; ++i)
	{

		v = componente(g[i].v);
		u = componente(g[i].u);

		if (v != u)
			p[v] = p[u], ans += g[i].w;

	}

	return ans;

}