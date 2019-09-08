/*
    @autor: Malbolge;
    @data: 07/09/2019;
    @nome: Converter Quilômetros para Milhas;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned long long llu;

int fib[110];

int main(int argc, char **argv)
{   

    int i;
    fib[1] = 1;
    fib[2] = 2;

    for (i = 3; i < 46; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    int n, m, ans;

    scanf("%d", &n);

    while (n--)
    {

        scanf("%d", &m);

        i = 45;
        ans = 0;
        while (i > 1)
        {
            if (fib[i] <= m)
                m -= fib[i], ans += fib[i - 1];

            --i;
        }

        printf("%d\n", ans);

    }

    return 0;

}