/*
    @autor: Malbolge;
    @data: 19/09/2019;
    @nome: Lançando Moedas;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

long long pop(long long);

int main(int argc, char **argv)
{

    long long n;

    scanf("%lld", &n);
    printf("%lld\n", 1LL << pop(n));

    return 0;

}

long long pop(long long u)
{

    long long ans = 0;

    while (u)
        u &= (u - 1), ++ans;

    return ans;

}