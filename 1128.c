/*
    @autor: Malbolge;
    @data: 25/08/2019;
    @nome: Ir e Vir;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 2010

char vis[MAXSIZE];
char g[MAXSIZE][MAXSIZE];

int n;
void dfs(int);

int main(int argc, char **argv)
{

    int m, u, v, p, i, j;

    while (scanf("%d %d", &n, &m), m && n)
    {

        memset(g, 0, sizeof(g));
        for (i = 0; i < m; ++i)
        {

            scanf("%d %d %d", &u, &v, &p);

            if (p == 1)
                g[u][v] = true;
            else
                g[u][v] = g[v][u] = true;

        }   

        _Bool flag = false;
        for (i = 1; i <= n; ++i)
        {
            
            memset(vis, 0, sizeof(vis));
            dfs(i);
            flag = false;
            for (j = 1; j < n && !flag; ++j)
                if (!vis[j])
                    flag = true;

            if (flag)
                break;

        }

        printf("%d\n", flag ? 0 : 1);

    }

    return 0;

}

void dfs(int u)
{

    int i;
    vis[u] = true;

    for (i = 1; i <= n; ++i)
        if (g[u][i])
            if (!vis[i])
                dfs(i);

}
