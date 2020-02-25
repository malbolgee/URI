/*

    @author: Malbolge;
    @date: 24/02/2020;
    @name: Programação de Viagem;

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 300
#define INF 0x3f3f3f3f

int p[MAXSIZE];
int path[MAXSIZE];
int dist[MAXSIZE];
int adj[MAXSIZE][MAXSIZE];

int dijkstra(int, int);
void reverse(int *, int);

int __size;

int main(int argc, char **argv)
{

    int n, m, a, b, w, d;

    while (scanf("%d %d", &n, &m), n && m)
    {

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                adj[i][j] = INF;

        for (int i = 0; i < m; ++i)
        {

            scanf("%d %d %d", &a, &b, &w);
            adj[a][b] = adj[b][a] = w;

        }

        scanf("%d", &d);
        int ans = dijkstra(d, n);

        if (ans <= 120)
            printf("Will not be late. ");
        else
            printf("It will be %d minutes late. ", ans - 120);

        printf("Travel time - %d - best way -", ans);

        for (int i = 0; i <= __size; ++i)
            printf(" %d", path[i]);

        putchar_unlocked('\n');

    }
    return 0;

}

int dijkstra(int d, int size)
{

    memset(p, -1, sizeof(p));
    bool vis[MAXSIZE] = { false };

    for (int i = 0; i <= size; ++i)
        dist[i] = INF;

    p[d] = d;
    dist[d] = 0;

    for (int i = 0; i <= size; ++i)
    {

        int v = -1;
        for (int j = 0; j <= size; ++j)
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF)
            break;

        vis[v] = true;
        for (int j = 0; j <= size; ++j)
            if (dist[v] + adj[v][j] < dist[j])
                dist[j] = adj[v][j] + dist[v], p[j] = v;

    }

    int u = 1;
    __size = 0;

    while (p[u] != u)
        path[__size++] = u, u = p[u];

    path[__size] = d;

    reverse(path, __size + 1);

    return dist[1];

}

void reverse(int *v, int n)
{

    for (int i = 0, j = n - 1; i < j; ++i, --j)
    {

        int tmp = v[i];
        v[i] = v[j];
        v[j] = tmp;

    }

}