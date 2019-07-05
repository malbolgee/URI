/*

	@autor: Malbolge;
	@data: 30/06/2019;
	@nome: Reduzindo Detalhes em um Mapa;

 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{

	int v, u, w;

} vertex;

vertex g[124760];
int p[124750];

int compara(vertex *, vertex *);
int componente(int);
int kruskal(int);

int main(int argc, char **argv)
{

	int r, c, i;
	scanf("%d %d", &r, &c);

	for (i = 0; i < c; ++i)
		scanf("%d %d %d", &g[i].v, &g[i].u, &g[i].w);

	qsort(g, c, sizeof(vertex), compara);

	for (i = 1; i <=r; ++i)
		p[i]= i;

	printf("%d\n", kruskal(c));

	return 0;

}

int compara(vertex *a, vertex *b)
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
			p[u] = p[v], ans += g[i].w;

	}

	return ans;

}