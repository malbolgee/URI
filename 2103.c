/*
    @autor: Malbolge;
    @data 30/07/2019;
    @nome: Harbin é Muita Grana!;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 10000
#define MOD 1300031LL

typedef struct __node{

    int vertex;
    int weight;
    struct __node *next;

} node;

typedef struct __g{

    node **adj;

} g_t;

int n;
long long ans;

g_t * make_graph(int);
int dfs(g_t *, int, int);
node * make_node(int, int);
void add_edge(g_t *, int, int, int);

int main(int argc, char **argv)
{

    int i, u, v, w, c;

    scanf("%d", &c);

    while (c--)
    {

        scanf("%d", &n);
        g_t *graph = make_graph(n);

        for (i = 0; i < n - 1; ++i)
        {

            scanf("%d %d %d", &u, &v, &w);
            --u, --v;
            add_edge(graph, u, v, w);

        }

        ans = 0;
        for (i = 0; i < n; ++i)
        {

            if (graph->adj[i]->next == NULL)
            {

                dfs(graph, i, -1);
                break;

            }

        }

        printf("%lld\n", ans);

    }

    return 0;

}

g_t * make_graph(int __size)
{

    int i;
    g_t * graph = (g_t *) malloc(sizeof(g_t));
    graph->adj = (node **) malloc(__size * sizeof(node *));

    for (i = 0; i < __size; ++i)
        graph->adj[i] = NULL;

    return graph;

}

node * make_node(int u, int w)
{

    node * new_node = (node *) malloc(sizeof(node));
    new_node->vertex = u;
    new_node->weight = w;
    new_node->next = NULL;

    return new_node;

}

void add_edge(g_t *graph, int u, int v, int w)
{

    node *new_node = make_node(v, w);
    new_node->next = graph->adj[u];
    graph->adj[u] = new_node;

    new_node = make_node(u, w);
    new_node->next = graph->adj[v];
    graph->adj[v] = new_node;

}

int dfs(g_t *__graph, int u, int v)
{

    node *i;
    int qtd;
    int size = 1;

    for (i = __graph->adj[u]; i != NULL; i = i->next)
    {

        int w = i->vertex;

        if (v != w)
        {

            qtd = dfs(__graph, w, u);
            ans += qtd * (n - qtd) * i->weight;

            while (ans >= MOD)
                ans -= MOD;

            size += qtd;

        }

    }

    return size;

}