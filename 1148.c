/*
    @autor: Malbolge;
    @data: 21/10/2019;
    @nome: Países em Guerra;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 600
#define INF 0x3f3f3f3f

int adj[MAXSIZE][MAXSIZE];

void dijkstra(int, int, int);

int main(int argc, char **argv)
{

    int u, v, w;
    int n, m, i, j, t;

    while (scanf("%d %d", &n, &m), n || m)
    {

        for (i = 0; i <= n; ++i)
            for (j = 0; j <= n; ++j)
                adj[i][j] = INF;

        for (i = 0; i < m; ++i)
        {

            scanf("%d %d %d", &u, &v, &w);

            if (adj[v][u] != INF)
                adj[u][v] = adj[v][u] = 0;
            else
                adj[u][v] = w;

        }

        scanf("%d", &t);
        while (t--)
        {

            scanf("%d %d", &u, &v);
            dijkstra(n, u, v);

        }

        putchar_unlocked('\n');

    }

    return 0;

}

void dijkstra(int n, int src, int dest)
{

    int i, j;
    int vis[n + 1];
    int dist[n + 1];

    memset(vis, false, sizeof(vis));

    for (i = 0; i <= n; ++i)
        dist[i] = INF;

    dist[src] = 0;
    for (i = 0; i <= n; ++i)
    {

        int v = -1;
        for (j = 0; j <= n; ++j)
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF)
            break;

        vis[v] = true;
        for (j = 0; j <= n; ++j)
            if (dist[v] + adj[v][j] < dist[j])
                dist[j] = adj[v][j] + dist[v];

    }

    if (dist[dest] < INF)
        printf("%d\n", dist[dest]);
    else
        puts("Nao e possivel entregar a carta");

}