/*
    @autor: Malbolge;
    @data: 15/08/2019;
    @nome: Cortando Canos;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define true 1
#define false 0
#define MAXSIZE 2500
#define MAX(a, b) a > b ? a : b

int n;
int v[MAXSIZE];
int w[MAXSIZE];
int dp[MAXSIZE][MAXSIZE];

int solve(int, int);

int main(int argc, char **argv)
{

    int i, m;

    while (scanf("%d %d", &n, &m) != EOF)
    {

        for (i = 0; i < n; ++i)
            scanf("%d %d", &w[i], &v[i]);

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, m));

    }

    return 0;

}

int solve(int u, int p)
{

    if (u == n)
        return 0;
    
    if (p == 0)
        return 0;
    
    if (p < 0)
        return INT_MIN;

    if (dp[u][p] == -1)
        dp[u][p] = MAX(solve(u + 1, p), v[u] + solve(u, p - w[u]));

    return dp[u][p];

}