/*
    @autor: Malbolge;
    @data: 24/08/2019;
    @nome: Resgate em Queda Livre;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0
#define MAXSIZE 300000

typedef struct __g{

    int u, v;
    double w;

} g_t;

typedef struct __p{

    int x, y;

} point;

int parent(int);
double kruskal(int);
int compare(g_t *, g_t *);
double dist(point, point);

int p[MAXSIZE];
g_t g[MAXSIZE];
point points[MAXSIZE];

int main(int argc, char **argv)
{

    int i, j, n, c, k;

    scanf("%d", &c);

    while (c--)
    {

        scanf("%d", &n);

        for (i = 0, k = 0; i < n; ++i)
        {

            scanf("%d %d", &points[i].x, &points[i].y);
            for (j = 0; j < i; ++j)
            {

                g[k].u = j;
                g[k].v = i;
                g[k].w = dist(points[j], points[i]) / 100.0;
                ++k;

            }

        }

        qsort(g, k, sizeof(g_t), compare);

        for (i = 0; i < n; ++i)
            p[i] = i;

        printf("%.2lf\n", kruskal(k));

    }

    return 0;

}

int parent(int i)
{

    return i == p[i] ? i : parent(p[i]);

}

double kruskal(int __c)
{

    int i;
    int u, v;
    double ans;

    for (i = 0, ans = 0; i < __c; ++i)
    {

        u = parent(g[i].u);
        v = parent(g[i].v);

        if (v != u)
            p[u] = p[v], ans += g[i].w;

    }

    return ans;

}

double dist(point a, point b)
{

    return hypot(b.x - a.x, b.y - a.y);

}

int compare(g_t *a, g_t *b)
{

    double tmp = a->w - b->w;

    if (tmp > 0.0)
        return 1;
    else if (tmp < 0.0)
        return -1;
    else 
        return 0;

}