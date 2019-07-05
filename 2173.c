/*

	@autor: Malbolge;
	@data: 05/07/2018;
	@nome: Caixa Dois;

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100010

typedef struct {

	int u, v, w;

} vertex;

int p[MAXSIZE];
vertex g[MAXSIZE];

int parent(int);
int kruskal(int, int);
void reverse(vertex *a, int, int);
int compare(vertex *, vertex *);

int main(int argc, char **argv)
{

	int i, x, y, ans = 0;
	while (scanf("%d %d", &x, &y), x)
	{

		for (i = 1; i <= y; ++i)
			scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);

		qsort(g, y + 1, sizeof(vertex), compare);

		ans = -kruskal(y, x);
		reverse(g, 1, y);
		ans += kruskal(y, x);
		printf("%d\n",ans);
		memset(p, 0, sizeof(int) * x);

	}

	return 0;

}

int kruskal(int __c, int __x)
{

	int i, u, v, ans;

	for (i = 0; i < __x; ++i)
		p[i] = i;

	for (i = 1, ans = 0; i <= __c; ++i)
	{

		v = parent(g[i].v);
		u = parent(g[i].u);

		if (u != v)
			p[u] = p[v], ans += g[i].w;

	}

	return ans;

}

int parent(int __i)
{

	if (__i == p[__i])
		return __i;

	return parent(p[__i]);

}

int compare(vertex *a, vertex *b)
{

	return a->w - b->w;

}

void reverse(vertex *a, int s, int e) 
{ 
    vertex temp; 
    while (s < e) 
    { 
        temp = a[s];    
        a[s] = a[e]; 
        a[e] = temp; 
        s++; 
        e--; 
    }    
} 