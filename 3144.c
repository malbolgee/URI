/*
    @author: Malbolge;
    @date: 02/11/2020;
    @name: G de Grafo;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct g_
{

    int u, v, w;

} g_t;

#define MAXSIZE 600
#define MAXSIZEG (((MAXSIZE) * (MAXSIZE - 1)) >> 1)

int id[MAXSIZE];
int sz[MAXSIZE];
g_t g[MAXSIZEG];

int find(int);
int kruskal(int);
void swap(int *, int *);
int compare(const void *, const void *);

int main(int argc, char **argv)
{

    int n, m, o;
    int u, v, w;

    scanf("%d %d %d", &n, &m, &o);

    for (int i = 0; i < m; ++i)
        scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);

    for (int i = 0; i <= n; ++i)
        id[i] = i, sz[i] = 1;

    qsort(g, m, sizeof(g_t), compare);

    printf("%d\n", kruskal(m));

    return 0;
}

int compare(const void *a, const void *b)
{

    return ((g_t *)a)->w - ((g_t *)b)->w;
}

inline void swap(int *a, int *b)
{

    int c = *a;
    *a = *b;
    *b = c;
}

int find(int u)
{

    if (u == id[u])
        return u;
    else
        return id[u] = find(id[u]);
}

int kruskal(int __c)
{

    int ans = 0;
    for (int i = 0; i < __c; ++i)
    {

        int p = find(g[i].u);
        int q = find(g[i].v);

        if (p != q)
        {

            if (sz[p] > sz[q])
                swap(&p, &q);

            id[p] = q;
            sz[q] += sz[p];

            ans += g[i].w;
        }
    }

    return ans * 2;
}