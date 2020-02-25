/*

    @author: Malbolge;
    @date: 25/02/2020;
    @name: Quase Menor Caminho (Almost Shortest Path);
    @source: ACM/ICPC South America Contest 2008;

*/

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 0x3f3f3f3fU
#define MAXSIZE 600

typedef unsigned uint;

uint graph[MAXSIZE][MAXSIZE];
uint invgraph[MAXSIZE][MAXSIZE];

uint dist[MAXSIZE];
uint invdist[MAXSIZE];

void dijkstra(int, int,  uint g[MAXSIZE][MAXSIZE], uint *);

int main(int argc, char **argv)
{

    int s, d, n, m, u, v, w;

    while (scanf("%d %d", &n, &m), n && m)
    {

        scanf("%d %d", &s, &d);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = invgraph[i][j] = INF;

        for (int i = 0; i < m; ++i)
        {

            scanf("%d %d %d", &u, &v, &w);

            graph[u][v] = w;
            invgraph[v][u] = w;

        }

        dijkstra(s, n, graph, dist);
        dijkstra(d, n, invgraph, invdist);

        uint min = dist[d];

        for (u = 0; u < n; ++u)
            for (v = 0; v < n; ++v)
                if (dist[u] + graph[u][v] + invdist[v] == min)
                    graph[u][v] = INF;

        dijkstra(s, n, graph, dist);

        if (dist[d] == INF)
            puts("-1");
        else
            printf("%u\n", dist[d]);

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
    for (int i = 0; i < n; ++i)
    {

        int v = -1;
        for (int j = 0; j <= n; ++j)
            if (!vis[j] && (v == -1 || d[j] < d[v]))
                v = j;

        if (d[v] == INF)
            break;

        vis[v] = true;
        for (int j = 0; j < n; ++j)
            if (d[v] + g[v][j] < d[j])
                d[j] = g[v][j] + d[v];

    }


}