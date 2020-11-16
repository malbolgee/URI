/*
    @author: Malbolge;
    @date: 15/11/2020;
    @name: Binarizando a Matriz;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    int n, m;
    const int mod = 1e9 + 7;
    scanf("%d %d ", &n, &m);

    char mt[n][m];

    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < m; ++j)
            scanf("%c ", &mt[i][j]);

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][m] = 1;
    for (size_t i = 0; i < n; ++i)
    {

        int acc0[m];
        int acc1[m];
        memset(acc0, 0, sizeof(acc0));
        memset(acc1, 0, sizeof(acc1));

        for (size_t j = 0; j < m; ++j)
        {
            if (mt[i][j] == '.')
                continue;

            acc0[j] = mt[i][j] == '0';
            acc1[j] = mt[i][j] == '1';
        }

        for (size_t j = 1; j < m; ++j)
        {

            acc0[j] += acc0[j - 1];
            acc1[j] += acc1[j - 1];
        }

        for (size_t j = 0; j <= m; ++j)
        {

            if (dp[i][j] == 0)
                continue;

            for (size_t k = 0; k <= j; ++k)
            {

                int qt0, qt1;
                qt0 = 0;
                qt1 = acc1[m - 1];

                if (k)
                    qt0 = acc0[k - 1];

                if (k)
                    qt1 -= acc1[k - 1];

                if (qt0 == 0 && qt1 == 0)
                {
                    dp[i + 1][k] += dp[i][j];
                    if (dp[i + 1][k] >= mod)
                        dp[i + 1][k] -= mod;
                }
            }
        }
    }

    int ans = 0;
    for (size_t j = 0; j <= m; ++j)
    {

        ans += dp[n][j];
        if (ans >= mod)
            ans -= mod;
    }

    printf("%d\n", ans);
    return 0;
}