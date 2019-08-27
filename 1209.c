/*
    @autor: Malbolge;
    @data: 26/08/2019;
    @nome: Festas de São Petersburgo;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1010

int f[MAXSIZE];
char vis[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];

int main(int argc, char **argv)
{

    int u, v, i;
    int n, m, k;

    while (scanf("%d %d %d", &n, &m, &k) != EOF)
    {
        
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        memset(adj, 0, sizeof(adj));

        for (i = 0; i < m; ++i)
        {

            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = true;
            ++f[u], ++f[v];

        }

        int e, s;
        e = s = 0;
        int queue[MAXSIZE << 2];
        for (i = 1; i <= n; ++i)
            if (f[i] < k)
                queue[e++] = i, vis[i] = true;

        while (s < e)
        {

            u = queue[s++];
            for (i = 1; i <= n; ++i)
                if (adj[u][i])
                    if (!vis[i] && --f[i] < k)
                        queue[e++] = i, vis[i] = true;

        }

        int ans[MAXSIZE];
        for (i = 1, k = 0; i <= n; ++i)
            if (!vis[i])
                ans[k++] = i;
        
        if (k)
            for (i = 0; i < k; ++i)
                printf("%d%c", ans[i], i < k - 1 ? ' ' : '\n');
        else
            puts("0");

    }

    return 0;

}