/*

    @author: Malbolge;
    @date: 26/02/2020;
    @name: Colônia de Formigas;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LOG 18
#define MAXSIZE 100005
#define INF 0x3f3f3f3fLLU

typedef long long ll;

typedef struct _node{

    int u, w;
    struct _node *next;

} node_t;

typedef struct _g{

    node_t *adj;

} g_t;

int n;

ll dist[MAXSIZE];
int depth[MAXSIZE];
int parent[MAXSIZE][LOG];

g_t * make_graph(int);
node_t * make_node(int, int);
void push_in(g_t *, int, int, int);

void pst();
void dfs(int, g_t *);
int LCA(int u, int v);
void swap(int *, int *);

int main(int argc, char **argv)
{

    int u, v, w, q;

    while (scanf("%d%*c", &n), n)
    {

        g_t *g = make_graph(n + 1);

        for (int u = 1; u < n; ++u)
        {

            scanf("%d %d", &v, &w);

            if (u < v)
                push_in(g, v, u, w);
            else
                push_in(g, u, v, w);

        }

        for (int i = 0; i <= n; ++i)
            dist[i] = depth[i] = INF;

        parent[0][0] = 0;
        depth[0] = dist[0] = 0;

        dfs(0, g);
        pst();

        scanf("%d", &q);

        while (q--)
        {

            scanf("%d %d", &u, &v);

            int lca = LCA(u, v);
            ll ans = (dist[u] - dist[lca]) + (dist[v] - dist[lca]);
            printf("%lld%c", ans, q > 0 ? ' ' : '\n');

        }

    }

    return 0;

}

void dfs(int s, g_t *g)
{

    for (node_t *i = g->adj[s].next; i != NULL; i = i->next)
    {

        int v = i->u;
        int w = i->w;

        if (depth[v] == INF)
        {

            depth[v] = depth[s] + 1;
            dist[v] = dist[s] + (ll)w;
            parent[v][0] = s;
            dfs(v, g);

        }

    }

}

void pst()
{

    for (int i = 1; i < LOG; ++i)
        for (int u = 0; u < n; ++u)
            if (parent[u][i - 1] != -1)
                parent[u][i] = parent[parent[u][i - 1]][i - 1];

}

int LCA(int u, int v)
{

    if (depth[u] > depth[v])
        swap(&u, &v);

    int diff = depth[v] - depth[u];

    for (int i = 0; i < LOG; ++i)
        if ((diff >> i) & 1)
            v = parent[v][i];

    if (u == v)
        return u;

    for (int i = LOG - 1; i >= 0; --i)
        if (parent[u][i] != parent[v][i])
            u = parent[u][i], v = parent[v][i];

    return parent[u][0];

}

g_t * make_graph(int __size)
{

    g_t *g = (g_t *) malloc(sizeof(g_t));
    g->adj = (node_t *) malloc(sizeof(node_t) * (__size + 1));

    for (int i = 0; i <= __size; ++i)
        g->adj[i].next = NULL;

    return g;

}

node_t * make_node(int u, int w)
{

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->u = u;
    new_node->w = w;
    new_node->next = NULL;

    return new_node;

}

void push_in(g_t *g, int u, int v, int w)
{

    node_t *new_node = make_node(u, w);
    new_node->next = g->adj[v].next;
    g->adj[v].next = new_node;

}

inline void swap(int *a, int *b)
{

    int tmp = *a;
    *a = *b;
    *b = tmp;

}
