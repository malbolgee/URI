/*
    @autor: Malbolge;
    @data: 29/08/2019;
    @nome: Dudu Faz Serviço;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 30100

typedef struct _node{

    int u;
    struct _node *next;

} node;

typedef struct _g{

    node **adj;

} g_t;

_Bool flag;
char vis[MAXSIZE];

g_t *make_graph(int);
void dfs(g_t *, int);
node * make_node(int);
void push_back(g_t *, int, int);

int main(int argc, char **argv)
{

    int n, m, i, k, u, v; 
    scanf("%d", &k);

    while (k--)
    {

        g_t *grafo = make_graph(10100);
        scanf("%d %d", &n, &m);

        for (i = 0; i < m; ++i)
            scanf("%d %d", &u, &v), push_back(grafo, u, v);

        flag = false;
        for (i = 0; i < n; ++i)
        {

            if (!vis[i])
                dfs(grafo, i);
            
            if (flag)
                break;

        }

        printf("%s\n", flag ? "SIM" : "NAO");
        memset(vis, 0, sizeof(vis));

    }

    return 0;

}

g_t * make_graph(int __size)
{

    int i;
    g_t *graph = (g_t *) malloc(sizeof(g_t));
    graph->adj = (node **) malloc(__size * sizeof(node *));
    
    for (i = 0; i < __size; ++i)
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

void push_back(g_t *graph, int u, int v)
{

    node * aux;
    node * new_node = make_node(v);

    if (graph->adj[u] == NULL)
    {

        new_node->next = graph->adj[u];
        graph->adj[u] = new_node;

    }
    else
    {

        aux = graph->adj[u];
        new_node->next = aux;
        graph->adj[u] = new_node;

    }

}

void dfs(g_t *graph, int u)
{

    node *i;
    vis[u] = true;

    if (flag)
        return;

    for (i = graph->adj[u]; i != NULL; i = i->next)
    {

        int v = i->u;
        if(vis[v] == 1)
        {
            
            flag = true;
            break;

        }
        else if (vis[v] == 0)
            dfs(graph, v);

    }

    vis[u] = 2;

}