/*
    @autor: Malbolge;
    @data: 23/10/2019;
    @nome: Festival das Noites Brancas;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MOD 1500
#define MAXSIZE 10100

int f[2100];

int fib();
int binn(char *);
int modexp(int, int);

int main(int argc, char **argv)
{

    int i, ans, n;
    char bin[MAXSIZE];
    fib();

    scanf("%d", &n);
    while (n--)
    {

        scanf("%s", bin);
        printf("%03d\n", f[binn(bin)]);

    }

    return 0;

}

int modexp(int a, int b)
{

    int ans = 1;
    a = a % MOD;

    while (b > 0)
    {

        if (b & 1)
            ans = (ans * a) % MOD;

        b >>= 1;
        a = (a * a) % MOD;

    }

    return ans;

}

int binn(char *n)
{

    int i, j;
    int ans = 0;

    for (i = strlen(n) - 1, j = 0; i >= 0; --i, ++j)
        if (n[i] == '1')
            ans = (ans + modexp(2, j)) % MOD;

    return ans;

}

int fib()
{
    int i;
    f[1] = f[2] = 1;

    for (i = 3; i <= 2000; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % 1000;

}