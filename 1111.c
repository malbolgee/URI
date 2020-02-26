/*

    @author: Malbolge;
    @date: 26/02/2020;
    @name: Desrugenstein;

*/

#include <stdio.h>
#include <stdbool.h>

#define INF 0x3f3f3f3fU
#define MAXSIZE 123

typedef unsigned uint;

uint g[MAXSIZE][MAXSIZE];

void fw(int);
uint min(uint, uint);

int main(int argc, char **argv)
{

    int u, v, w, n, z, x;

    while (scanf("%d%*c", &n), n)
    {

        for (int i = 0; i < n * n; ++i)
        {

            for (int j = 0; j < n * n; ++j)
                g[i][j] = INF;

            g[i][i] = 0U;

        }

        for (int i = n - 1; i >= 0; --i)
        {

            for (int j = 0; j < n; ++j)
            {

                scanf("%d %d %d %d", &u, &v, &z, &w);

                if (u == 1)
                    g[i * n + j][(i + 1) * n + j] = 1U;
                if (v == 1)
                    g[i * n + j][(i - 1) * n + j] = 1U;
                if (z == 1)
                    g[i * n + j][i * n - 1 + j] = 1U;
                if (w == 1)
                    g[i * n + j][i * n + 1 + j] = 1U;

            }

        }

        x = n;

        fw(n * n);

        scanf("%d", &n);

        while (n--)
        {

            scanf("%d %d %d %d", &u, &v, &z, &w);

            u = u + v * x;
            z = z + w * x;

            if (g[u][z] != INF)
                printf("%u\n", g[u][z]);
            else
                puts("Impossible");

        }

        putchar_unlocked('\n');

    }

    return 0;

}

void fw(int n)
{

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                g[j][k] = min(g[j][k], g[j][i] + g[i][k]);

}

inline uint min(uint a, uint b)
{

    return a < b ? a : b;

}