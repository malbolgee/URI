/*
    @autor: Malbolge;
    @data: 08/03/2019;
    @nome: Just in Time;
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

long isPrime(long);

void main ()
{

    long n;
    scanf("%ld", &n);
    printf("%ld\n", n == 2 ? 2 : isPrime(n));
    
}

long isPrime(long x)
{

    long i, j;
    if (x % 2 == 0)
        x -= 1;

    for (i = x; i >= 2; i -= 2)
    {

        _Bool flag = true;
        long size = sqrt(i);
        for (j = 3; j <= size; j += 2)
            if (i % j == 0)
            {
                flag = false;
                break;
            }

        if (flag)
            return i;

    }

}
