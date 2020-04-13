/*

    @author: Malbolge;
    @date: 07/04/2020;
    @name: Esta Sentença é Falsa;

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 1234
typedef unsigned uint;

typedef struct _node{

    int u, w;
    struct _node *next;

} node_t;

typedef struct _g{

    node_t *adj;

} g_t;

bool p;
int x, y;

int n;
int vis[MAXSIZE];
int next[MAXSIZE];

g_t * make_graph(int);
node_t * make_node(int, int);
void push_in(g_t *, int, int, int);
void dfs(g_t *, int, int, int);

inline int max(int, int);

int main(int argc, char **argv)
{

    while (scanf("%d", &n), n)
    {

        int number, res;
        char string[10];
        
        g_t *g = make_graph(n);
        memset(next, -1, sizeof(next));
        memset(vis, false, sizeof(vis));

        pos = true;

        for (uint i = 0; i < n; ++i)
        {

            scanf("%s %d %s %s", string, &number, string, string);
            next[i] = number - 1;
            push_in(g, number - 1, i, string[0] == 'f' ? 1 : 0);

        }

        res = 0;

        for (uint i = 0; i < n && p; ++i)
        {

            if (vis[i])
                continue;

            vis[i] = 2;

            uint u = i;

            while (next[u] != -1 && !vis[next[u]])
                u = next[u], vis[u] = 2;

            x = y = 0;
            dfs(g, u, 0, 0);

            res += max(x, y);

        }

        if (!p)
            puts("Inconsistent");
        else
            printf("%d\n", res);

    }

    return 0;

}

g_t * make_graph(int _size)
{   

    g_t *g = (g_t *) malloc(sizeof(g_t));
    g->adj = (node_t *) malloc(sizeof(node_t) * (n + 1));

    for (uint i = 0; i < _size; ++i)
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

    node_t *new_node = make_node(v, w);
    new_node->next = g->adj[u].next;
    g->adj[u].next = new_node;

}

void dfs(g_t *g, int u, int v, int f)
{

    if (vis[u] == 1)
    {

        if (f % 2)
            p = false;

        return;

    }

    vis[u] = 1;
    y += 1 - v;
    x += v;

    for (node_t * i = g->adj[u].next; i != NULL; i = i->next)
    {

        int k = i->u;
        int w = i->w;

        dfs(g, k, w != v ? 1 : 0, w + f);

    }

}

int max(int _a, int _b)
{

    return _a > _b ? _a : _b; 

}