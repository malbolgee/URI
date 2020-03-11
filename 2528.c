/*

    @author: Malbolge;
    @date: 11/03/2020;
    @name: Cidade Proibida;

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INF 0x3f3f3f3fU
#define MAXSIZE 1200

typedef unsigned uint;

uint dist[MAXSIZE];
uint graph[MAXSIZE][MAXSIZE];

void dijkstra(int, int, uint g[MAXSIZE][MAXSIZE], uint *);

int main(int argc, char **argv)
{

    int r, e, c;
    int n, m, u, v;

    while (~scanf("%d %d", &n, &m))
    {

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                graph[i][j] = INF;

        for (int i = 0; i < m; ++i)
            scanf("%d %d", &u, &v), graph[u][v] = graph[v][u] = 1;

        scanf("%d %d %d", &c, &r, &e);

        for (int i = 0; i <= n; ++i)
            graph[e][i] = graph[i][e] = INF;

        dijkstra(c, n, graph, dist);
        
        printf("%d\n", dist[r]);

    }

    return 0;

}

void dijkstra(int s, int n, uint g[MAXSIZE][MAXSIZE], uint *d)
{

    bool vis[n + 1];
    memset(vis, false, sizeof(vis));

    for (int i = 0 ; i <= n; ++i)
        d[i] = INF;

    d[s] = 0;

    for (int i = 0; i <= n; ++i)
    {

        int v = -1;
        for (int j = 0; j <= n; ++j)
            if (!vis[j] && (v == -1 || d[j] < d[v]))
                v = j;

        if (d[v] == INF)
            break;

        vis[v] = true;
        for (int j = 0; j <= n; ++j)
            if (d[v] + g[v][j] < d[j])
                d[j] = g[v][j] + d[v];

    }

}