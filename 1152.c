/*

	@autor: Malbolge;
	@data: 02/07/2019;
	@nome: Estradas Escuras;

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

	unsigned u, v, w;

} vertex;

#define true 1
#define false 0
#define MAXSIZE 200100 

vertex g[MAXSIZE];
int p[MAXSIZE];

int kruskal(int);
int parent(int);
int compara(vertex *, vertex *);

int main(int argc, char **argv)
{

	int e, v;

	while (scanf("%d %d", &e, &v), e && v)
	{

		int i;
		unsigned total = 0;
		for (i = 0; i < v; ++i)
			scanf("%d %d %d", &g[i].v, &g[i].u, &g[i].w), total += g[i].w;

		qsort(g, v, sizeof(vertex), compara);

		for (i = 1; i <= e; ++i)
			p[i] = i;

		printf("%u\n", total - kruskal(v));

		memset(g, 0, sizeof(g));
		memset(p, 0, sizeof(p));

	}

	return 0;

}

int parent(int __i)
{

	if (__i == p[__i])
		return __i;
	
	return parent(p[__i]);

}

int kruskal(int __c)
{

	int i, v, u;
	unsigned ans;

	for (i = 0, ans = 0; i < __c; ++i)
	{

		v = parent(g[i].v);
		u = parent(g[i].u);

		if (u != v)
			p[v] = p[u], ans += g[i].w;

	}

	return ans;

}

int compara(vertex *a, vertex *b)
{

	return a->w - b->w;

}