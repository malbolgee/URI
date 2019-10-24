/*
    @autor: Malbolge;
    @data: 24/10/2019;
    @nome: Decoração Natalina;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

typedef struct _string{

    char s[100];

} string_t;

int min(int , int);
int solve(string_t *, string_t *, int, int);

int main()
{

    char *str;
    int i, r, m, n, t, j;
    setlocale(LC_NUMERIC, "pt_BR.UTF-8");

    scanf("%d", &t);
    for (j = 1; j <= t; ++j)
    {

        scanf("%d", &r);
        scanf("%d", &m);

        string_t s1[m];
        for (i = 0; i < m; ++i)
            scanf(" %s", s1[i].s);

        scanf("%d", &n);

        string_t s2[n];
        for (i = 0; i < n; ++i)
            scanf(" %s", s2[i].s);

        printf("Caso #%d: R$ %.2f\n", j, (solve(s1, s2, m, n) * r) / 100.0f);

    }

    return 0;

}

int solve(string_t *s1, string_t *s2, int m, int n)
{

    int i, j;
    int dp[m + 1][n + 1];

    for (i = 0; i <= m; ++i)
        dp[i][0] = i * 50;
    
    for (i = 0; i <= n ; ++i)
        dp[0][i] = i * 250;
   
    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j)
            if (strcmp(s1[i - 1].s, s2[j - 1].s) == 0)
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1] + 250, min(dp[i - 1][j] + 50, dp[i - 1][j - 1] + 100));

    return dp[m][n];

}

int min(int a, int b)
{

    return a < b ? a : b;

}