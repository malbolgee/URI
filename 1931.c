/*
    @autor: Malbolge;
    @data: 14/12/2019;
    @nome: Mania de Par;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 11234
#define INF 0x3f3f3f3u

typedef struct _node{

    int u, w;
    struct _node * next;

} node_t;

typedef struct _g{

    node_t *adj;

} g_t;

int vis[MAXSIZE];
int dist[MAXSIZE];

g_t * make_graph(const int);
node_t * make_node(const int, const int);
void dijkstra(const g_t *restrict g, const int, const int);
void push_back(const g_t *restrict g, const int, const int, const int);
void make_aux_graph(const g_t *restrict g1, const g_t *restrict g2, const int __size);

int main(int argc, char **argv)
{

    int u, v, w;
    int n, m, i, j;

    scanf("%d %d", &n, &m);

    g_t *g1 = make_graph(n + 1);
    g_t *g2 = make_graph(n + 1);

    while (m--)
    {

        scanf("%d %d %d", &u, &v, &w);
        push_back(g1, u, v, w);
        push_back(g1, v, u, w);

    }

    dijkstra(g2, 1, n);

    if (dist[n] == INF)
        puts("-1");
    else
        printf("%d\n", dist[n]);

    return 0;

}

g_t * make_graph(const int __size)
{

    g_t *g = (g_t *) malloc(sizeof(g_t));
    g->adj = (node_t *) malloc(sizeof(node_t) * (__size + 1));

    for (int i = 1; i <= __size; ++i)
        g->adj[i].next = NULL;

    return g;

}

node_t * make_node(const int u, const int w)
{

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->u = u;
    new_node->w = w;
    new_node->next = NULL;

    return new_node;

}

void push_back(const g_t *restrict g, const int u, const int v, const int w)
{

    node_t * new_node = make_node(u, w);
    new_node->next = g->adj[v].next;
    g->adj[v].next = new_node;

}

void dijkstra(const g_t *restrict g, const int __s, const int __size)
{

    node_t *k;
    int i, j, v;

    memset(vis, false, sizeof(vis));

    for (i = 1; i <= __size; ++i)
        dist[i] = INF;

    dist[__s] = 0;

    for (i = 1; i <= __size; ++i)
    {

        v = -1;
        for (j = 1; j <= __size; ++j)
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF)
            break;

        vis[v] = true;

        for (k = g->adj[v].next; k != NULL; k = k->next)
        {

            int to = k->u;
            int len = k->w;

            if (dist[v] + len < dist[to])
                dist[to] = dist[v] + len;

        }

    }

}

void make_aux_graph(const g_t *restrict g1, const g_t *restrict g2, const int __size)
{

    int i;
    node_t *j, *k;

    for (i = 1; i <= __size; ++i)
    {

        for (j = g1->adj[i].next; j != NULL; j = j->next)
        {

            int u = j->u;
            int w = j->w;

            for (k = g1->adj[u].next; k != NULL; k = k->next)
            {

                int v = k->u;
                int w2 = k->w;
                push_back(g2, i, v, w + w2);

            }

        }

    }

}