/*
    @author: Malbolge;
    @date: 08/11/2020;
    @name: Irmãos;
*/

#include <stdio.h>

#define MAXSIZE 123

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};
int z[2][MAXSIZE][MAXSIZE];

int main(int argc, char **argv)
{

    int n, r, c, k;
    while (scanf("%d %d %d %d", &n, &r, &c, &k), n)
    {

        for (size_t i = 0; i < r; ++i)
            for (size_t j = 0; j < c; ++j)
                scanf("%d", &z[0][i][j]);

        for (size_t i = 0; i < k; ++i)
            for (size_t j = 0; j < r; ++j)
                for (size_t w = 0; w < c; ++w)
                {

                    int u = z[i % 2][j][w];
                    z[(i + 1) % 2][j][w] = u;

                    for (size_t o = 0; o < 4; ++o)
                    {

                        int mi = x[o] + j;
                        int mj = y[o] + w;

                        if (mi < 0 || mi >= r || mj < 0 || mj >= c)
                            continue;

                        int v = z[i % 2][mi][mj];

                        if (u == (v + 1) % n)
                            z[(i + 1) % 2][j][w] = v, o = 4;
                    }
                }

        for (size_t i = 0; i < r; ++i)
        {

            printf("%d", z[k % 2][i][0]);
            for (size_t j = 1; j < c; ++j)
                printf(" %d", z[k % 2][i][j]);

            puts("");
        }
    }

    return 0;
}