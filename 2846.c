/*
    @autor: Malbolge;
    @data: 10/03/2019;
    @nome: Fibonot;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 100100

long long fibo[MAXSIZE];
long long _fibonot[MAXSIZE];

void fib();

void main ()
{

    int n;
    fib();
    scanf("%d", &n);
    printf("%lld\n", _fibonot[n]);
    
}

void fib()
{

    int i, j, k;
    fibo[0] = 0; fibo[1] = 1;
    for (i = 2; i <= MAXSIZE; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    for (i = 1, j = 2, k = 1; i <= MAXSIZE; ++i)
        if (fibo[j] != i)
            _fibonot[k++] = i;
        else
            ++j;

}
