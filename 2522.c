/*
    @autor: Malbolge;
    @data: 17/08/2019;
    @nome: Rede do DINF;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0
#define MAXSIZE 300000

typedef struct {

    int x, y;

} point;

typedef struct {

    int u, v;
    double w;

} graph;

int parent(int);
double kruskal(int);

int p[600];
point e[600];
graph g[MAXSIZE];

double kruskal(int);
double dist(point, point);
int compare(graph *, graph *);

int main(int argc, char **argv)
{

    int n, i, j, k;

    while (scanf("%d", &n) != EOF)
    {


        memset(p, 0, sizeof(p));
        memset(g, 0, sizeof(g));

        for (i = 0, k = 0; i < n; ++i)
        {

            scanf("%d %d", &e[i].x, &e[i].y);

            for (j = 0; j < i; ++j)
            {

                g[k].u = j;
                g[k].v = i;
                g[k].w = dist(e[j], e[i]);
                ++k;

            }

        }   

        qsort(g, k, sizeof(graph), compare);

        for (i = 0; i < n; ++i)
            p[i] = i;

        printf("%.2lf\n", kruskal(k));

    }

    return 0;

}

int parent(int __i)
{

    if (__i == p[__i])
        return __i;

    return parent(p[__i]);

}

double kruskal(int __c)
{

    int i, u, v;
    double ans = 0;

    for (i = 0; i < __c; ++i)
    {

        u = parent(g[i].u);
        v = parent(g[i].v);

        if (u != v)
            p[u] = p[v], ans += g[i].w;

    }

    return ans;

}


double dist(point a, point b)
{

    return hypot(b.x - a.x, b.y - a.y);

}

int compare(graph *a, graph *b)
{

    return a->w - b->w;

}