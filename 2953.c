/*
    @autor: Malbolge;
    @data: 05/10/2019;
    @nome: Mais um Joguinho;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007LL

int fib[123545];

int main(int argc, char **argv)
{

    int i, n;
    fib[1] = 0;
    fib[2] = 1;
    fib[3] = 1;

    scanf("%d", &n);
    
    if (n == 2)
        puts("1");
    else
    {

        n--;
        for (i = 4; i <= n; ++i)
            fib[i] = (fib[i - 2] + fib[i - 3]) % MOD;

        printf("%d\n", fib[n]);

    }
    
    return 0;

}