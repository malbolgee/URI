/*
    @autor: Malbolge;
    @data: 04/08/2019;
    @nome: Par ou Ímpar;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1010
#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

int v[MAXSIZE];
int dp[MAXSIZE][MAXSIZE];

int main(int argc, char **argv)
{

    int n, i, j, k;

    while (scanf("%d", &n), n)
    {

        n *= 2;

        for (i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        for (i = 0; i < n; ++i)
        {

            for (j = 0; j + i < n; ++j)
            {

                k = i + j;

                if (i == 0)
                    dp[j][k] = 0;

                if (i % 2 == 0)
                    dp[j][k] = MIN(dp[j + 1][k], dp[j][k -1]);
                else
                    dp[j][k] = MAX(dp[j + 1][k] + (v[j] % 2 == 0 ? 1 : 0), dp[j][k - 1] + (v[k] % 2 == 0 ? 1 : 0));

            }

        }

        printf("%d\n", dp[0][n - 1]);

    }

    return 0;

}