/*
    @autor: Malbolge;
    @data: 08/09/2019;
    @nome: RSA;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef long long ll;

int _phi(int);
int inv_mod(int, int);
ll fast_exp(ll, ll, ll);
void euclid_ext(int, int);

int x, y, d;

int main(int argc, char **argv)
{

    int n, e, c, phi;

    scanf("%d %d %d", &n, &e, &c);
    phi = _phi(n);

    int d = inv_mod(e, phi);
    printf("%lld\n", fast_exp(c, d, n));

    return 0;

}

int _phi(int n) 
{

    int result = n;
    for (int i = 2; i * i <= n; i++) 
    {

        if(n % i == 0) 
        {

            while(n % i == 0)
                n /= i;

            result -= result / i;

        }
    }

    if(n > 1)
        result -= result / n;

    return result;

}

ll fast_exp(ll p, ll q, ll m)
{

    ll r = 1;
    while (q)
    {

        if (q & 1)
            r = (r * p) % m;
        
        p = (p * p) % m;
        q >>= 1;

    }

    return r;

}


void euclid_ext(int a, int b)
{

    if (!b)
    {

        x = 1;
        y = 0;
        d = a;

        return;

    }

    euclid_ext(b, a % b);
    
    int x1 = y, y1 = x - (a / b) * y;
    x = x1, y = y1;

}

int inv_mod(int a, int m)
{

    euclid_ext(a, m);
    return (x % m + m) % m;

}