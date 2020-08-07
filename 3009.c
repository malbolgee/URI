
/*
    @author: Malbolge;
    @date: 11/07/2020;
    @name: Dominós;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 1010

bool vis[MAXSIZE];
char graph[MAXSIZE][MAXSIZE];

int n, m;

bool check();
void dfs(int);

int main(int argc, char **argv)
{

    int c, a, b;
    scanf("%d", &c);

    bool count;
    while (c--)
    {

        scanf("%d %d", &n, &m);
        memset(graph, 0, sizeof(graph));

        for (int i = 0; i < m; ++i)
            scanf("%d %d", &a, &b), graph[a][b] = 1;

        count = false;
        for (int i = 1; i <= n; ++i)
        {

            memset(vis, 0, sizeof(vis));
            dfs(i);
            if (check())
                count = true, i = n + 1;
        }

        if (count)
            putchar_unlocked('S');
        else
            putchar_unlocked('N');

        putchar_unlocked('\n');
    }

    return 0;
}

void dfs(int s)
{

    vis[s] = true;
    for (int i = 1; i <= n; ++i)
        if (graph[s][i])
            if (!vis[i])
                dfs(i);
}

inline bool check()
{

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            return false;

    return true;
}