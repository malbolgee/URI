/*
    @author: Malbolge;
    @date: 21/06/2020;
    @name: Exercício de História;
*/

#include <stdio.h>
#include <math.h>

typedef unsigned long long ullint;

int main(int argc, char **argv)
{
    
    ullint n;

    while (~scanf("%llu", &n))
        printf("%.lf\n", ceil(n / 100.0));

    return 0;
}