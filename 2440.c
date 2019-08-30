/*
    @autor: Malbolge;
    @data: 29/08/2019;
    @nome: Famílias de Tróia;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 53216

typedef struct _node{

    int u;
    struct _node *next;

} node;

typedef struct _g{

    node **adj;

} g_t;

char vis[MAXSIZE];

g_t * make_graph(int);
node * make_node(int);
void push(g_t *, int, int);
void dfs(g_t *, int);

int main(int argc, char **argv)
{

    int n, m, i, u, v;
    g_t *grafo = make_graph(MAXSIZE);
    
    scanf("%d %d", &n, &m);

    for (i = 0; i < m; ++i)
        scanf("%d %d", &u, &v), push(grafo, u, v);
    
    int ans = 0;
    for (i = 1; i <= n; ++i)
        if (!vis[i])
            ++ans, dfs(grafo, i);

    printf("%d\n", ans);

    return 0;

}

g_t * make_graph(int _size)
{

    int i;
    g_t *graph = (g_t *) malloc(sizeof(g_t));
    graph->adj = (node **) malloc(_size * sizeof(node *));

    for (i = 0; i < _size; ++i)
        graph->adj[i] = NULL;
 
    return graph;

}

node * make_node(int u)
{

    node * new_node = (node *) malloc(sizeof(node));
    new_node->u = u;
    new_node->next = NULL;

    return new_node;

}

void push(g_t *graph, int u, int v)
{

    node * new_node = make_node(v);
    new_node->next = graph->adj[u];
    graph->adj[u] = new_node;

    new_node = make_node(u);
    new_node->next = graph->adj[v];
    graph->adj[v] = new_node;
    
}

void dfs(g_t *graph, int u)
{

    node *i;
    vis[u] = true;

    for (i = graph->adj[u]; i != NULL; i = i->next)
        if (!vis[i->u])
            dfs(graph, i->u);

}