/*

	@autor: Malbolge;
	@data: 14/06/2019;
	@nome: Roteadores;

 */

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct {

	int v, u, w;

} edge;

edge g[250];
int p[70];

int compara(edge *, edge *);
int componente(int);
int kruskal(int);

int main(int argc, char **argv)
{

	int r, c, i;
	scanf("%d %d", &r, &c);

	for (i = 0; i < c; ++i)
		scanf("%d %d %d", &g[i].v, &g[i].u, &g[i].w);

	qsort(g, c, sizeof(edge), compara);

	for (i = 1; i <= r; ++i)
		p[i] = i;

	printf("%d\n", kruskal(c));

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