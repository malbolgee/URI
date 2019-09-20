/*
    @autor: Malbolge;
    @data: 19/09/2019;
    @nome: Garoto Ixpertinho;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1100

typedef struct _g{

    int u, v;
    double w;

} g_t;

int p[MAXSIZE];
g_t g[MAXSIZE];

int parent(int);
double kruskal(int, int q);

int compare(g_t *, g_t *);

int x;
double t;

int main(int argc, char **argv)
{

    int q, c, i;

    while (scanf("%d %d %lf", &q, &c, &t), q && c && t)
    {

        for (i = 0; i < c; ++i)
            scanf("%d %d %lf", &g[i].u, &g[i].v, &g[i].w);

        qsort(g, c, sizeof(g_t), compare);
        printf("%.2lf ", kruskal(c, q));
        printf("%d\n", x);

    }

    return 0;

}

int compare(g_t *a, g_t *b)
{

    double tmp = a->w - b->w;

    if (tmp == 0.0)
        return 0;
    else if (tmp > 0.0)
        return 1;
    else
        return -1;

}

int parent(int _i)
{

    if (p[_i] == _i)
        return _i;

    return parent(p[_i]);

}

double kruskal(int n, int q)
{

    int i;
    double ans = 0;

    for (i = 0; i <= q; ++i)
        p[i] = i;

    x = 0;
    for (i = 0; i < n; ++i)
    {

        int u = parent(g[i].u);
        int v = parent(g[i].v);

        if (u != v)
        {

            p[u] = p[v];

            if (g[i].w > t)
                ans += g[i].w + 2, ++x;
            else
                ans += g[i].w;

        }

    }

    return ans;

}