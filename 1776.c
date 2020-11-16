/*
    @author: Malbolge;
    @date: 15/11/2020;
    @name: Baile de Formatura;
*/

#include <stdio.h>

int main(int argc, char **argv)
{
    int t;
    long long n, ans;
    scanf("%d", &t);

    for (size_t i = 1; i <= t; ++i)
    {

        scanf("%lld", &n);

        ans = n;
        for (size_t j = 2; j * j <= n; ++j)
        {

            int exp = 0;
            while (n % j == 0)
                n /= j, exp++;

            if (exp & 1)
                ans *= j;
        }

        if (n > 1)
            ans *= n;

        printf("Caso #%lu: %lld\n", i, ans);
    }

    return 0;
}