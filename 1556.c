/*
    @autor: Malbolge;
    @data: 25/07/2019;
    @nome: Removendo Letras;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int t, s;
char p[1005];
char en[1005];
int g[1005][30];

void dfs();

void print(char *);

int main(int argc, char **argv)
{

    int i, j;
    while (scanf("%s", &en[1]) != EOF)
    {
        
        en[0] = 'X';
        int lig[30];
        t = strlen(en);

        memset(g, 0, sizeof(g));
        memset(lig, 0, sizeof(lig));

        for (i = t - 1; i >= 0; --i)
        {
            
            for (j = 0; j < 30; ++j)
                g[i][j] = lig[j];

            lig[en[i] - 'a'] = i;

        }

        s = 0;
        dfs(0);
        putchar_unlocked('\n');

    }

    return 0;

}

void dfs(int u)
{

    int i;

    for (i = 0; i < 30; ++i)
        if (g[u][i])
        {

            p[s++] = 'a' + i;
            p[s] = '\0';
            print(p);
            dfs(g[u][i]);
            --s;

        }

}

void print(char *__s)
{

    unsigned i;
    for (i = 0; __s[i]; ++i)
        putchar_unlocked(__s[i]);

    putchar_unlocked('\n');

}