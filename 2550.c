/*
    @author: Malbolge;
    @date: 14/07/2020;
    @name: Novo Campus;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 1010
#define MAXSIZEG (((MAXSIZE) * (MAXSIZE - 1)) >> 1)

typedef struct __g
{

    int u, v, w;

} g_t;

int id[MAXSIZE];
int sz[MAXSIZE];
g_t g[MAXSIZEG];
bool vis[MAXSIZE];
int adj[MAXSIZE][MAXSIZE];

void dfs(int);
int find(int);
int kruskal(int);
void swap(int *, int *);
int compare(const void *, const void *);

char scanff(int *);
void print_d(int);

int n;

int main(int argc, char **argv)
{

    int m;

    while (~scanf("%d %d%*c", &n, &m))
    {

        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < m; ++i)
        {

            scanff(&g[i].u);
            scanff(&g[i].v);
            scanff(&g[i].w);

            adj[g[i].u][g[i].v] = g[i].w;
        }

        int comp = 0;
        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                ++comp, dfs(i);

        if (comp > 1)
        {
            puts("impossivel");
            continue;
        }

        for (int i = 1; i <= n; ++i)
            id[i] = i, sz[i] = 1;

        qsort(g, m, sizeof(g_t), compare);

        print_d(kruskal(m));
        putchar_unlocked('\n');
    }

    return 0;
}

int compare(const void *a, const void *b)
{

    return ((g_t *)a)->w - ((g_t *)b)->w;
}

inline void swap(int *a, int *b)
{

    int tmp = *a;
    *a = *b;
    *b = tmp;
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

    return ans;
}

void dfs(int s)
{

    vis[s] = true;
    for (int i = 1; i <= n; ++i)
        if (adj[s][i] && !vis[i])
            dfs(i);
}

inline char scanff(int *a)
{

    register char c = 0;
    *a = 0;
    c = getchar_unlocked();

    while (c >= 48)
        *a = *a * 10 + (c - '0'), c = getchar_unlocked();

    return c;
}

inline void print_d(int n)
{

    int i = 10;
    char output_buffer[10];
    do
    {

        output_buffer[--i] = (n % 10) + '0';
        n /= 10;

    } while (n);

    do
    {
        putchar_unlocked(output_buffer[i]);

    } while (++i < 10);
}