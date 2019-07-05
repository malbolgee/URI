/*

	@autor: Malboge;
	@data: 02/07/2019;
	@nome: Espaço de Projeto;

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1000100

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

	int i, x, e;
	int u, v, w;

	scanf("%d", &x);

	for (i = 0; i < x; ++i)
		scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);

	qsort(g, x, sizeof(vertex), compare);

	printf("%d\n", kruskal(x, x));
	reverse(g, 0, x);
	printf("%d\n", kruskal(x, x));
	
	return 0;

}

int kruskal(int __c, int __x)
{

	unsigned ans, i, u, v;

	for (i = 0; i < __x; ++i)
		p[i] = i;

	for (i = 0, ans = 0; i < __c; ++i)
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

	return b->w - a->w;

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