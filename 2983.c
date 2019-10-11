/*
    @autor: Malbolge;
    @data 08/10/2019;
    @nome: Nem Tudo é Greve;
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0

_Bool isPrime(long long);
int compare(long long *, long long *);

int main(int argc, char **argv)
{

    int n, i, j;
    long long x;
    long long v[1100];
    long long ans[1100];

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
        scanf("%lld", &v[i]);

    qsort(v, n, sizeof(long long), compare);
    
    j = 0;
    if (isPrime(v[0]))
        ans[j++] = v[0];

    for (i = 1; i < n; ++i)
        if (v[i] != v[i - 1])
            if (isPrime(v[i]))
                ans[j++] = v[i];

    if (j == 0)
        printf("%d\n\n", j);
    else
    {

        printf("%d\n", j);
        for (i = 0; i < j; ++i)
            printf("%lld%s", ans[i], i < j - 1 ? ", " : ".\n");

    }

    return 0;

}

int compare(long long *a, long long *b)
{

    return *a - *b;

}

_Bool isPrime(long long x)
{

    int i;
    if (x != 2LL  && x % 2LL == 0LL || x == 1LL)
        return false;

    int raiz = (int)sqrt(x);

    for (i = 3; i <= raiz; i += 2)
        if (x % i == 0)
            return false;

    return true;

}