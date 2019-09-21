/*
    @autor: Malbolge;
    @data: 20/09/2019;
    @nome: DFSr - Hierarquia de Profundidade;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 30

int v, j;
_Bool flag;
int tmp[MAXSIZE];
char esp[MAXSIZE];
_Bool vis[MAXSIZE];
int adj[MAXSIZE][MAXSIZE];

void dfs(int);

int main(int argc, char **argv)
{

    int u, w;
    int n, e, i, caso = 0;

    scanf("%d", &n);

    while (n--)
    {

        scanf("%d %d", &v, &e);
        memset(vis, 0, sizeof(vis));
        memset(adj, 0, sizeof(adj));

        for (i = 0; i < e; ++i)
            scanf("%d %d", &u, &w), adj[u][w] = true;

        printf("Caso %d:\n", ++caso);
        for (i = 0; i < v; ++i)
        {

            esp[0] = 0;
            flag =  false;
            if (!vis[i])
                dfs(i);

            if (flag)
                putchar_unlocked('\n');

        }

    }

    return 0;

}

void dfs(int u)
{

    int i;
    vis[u] = true;
    strcat(esp, "  ");

    for (i = 0; i < v; ++i)
    {   

        if (adj[u][i])
        {
            
            flag = true;
            if (!vis[i])
            {
                
                printf("%s%d-%d pathR(G,%d)\n", esp, u, i, i);
                dfs(i);
                esp[strlen(esp) - 2] = 0;

            }
            else
                printf("%s%d-%d\n", esp, u, i);

        }
            
    }

}