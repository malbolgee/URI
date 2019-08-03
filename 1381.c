/*
    @autor: Malbolge;
    @data: 01/08/2019;
    @nome: Equações Diofantinas;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MOD 1300031
#define MAXSIZE 5000100

typedef long long ll;

ll fib[MAXSIZE];

ll inv(ll, ll);
ll exp_pow(ll, ll, ll);
void euclid(ll, ll, ll *, ll *, ll *);

int main(int argc, char **argv)
{

    int n, m, i, c;
    fib[0] = 1;

    for (i = 1; i < MAXSIZE; ++i)
        fib[i] = (i * fib[i - 1]) % MOD;

    scanf("%d", &c);

    while (c--)
    {

        scanf("%d %d", &n, &m);
        ll y = fib[m + n - 1];
        ll x = inv((fib[m] * fib[n - 1]) % MOD, MOD);
        printf("%lld\n", (y * x) % MOD);

    }

    return 0;

}

ll inv(ll n, ll m)
{

    ll x, y, g;
    euclid(n, m, &x, &y, &g);

    if (g != 1)
        return 0;

    return (x + m) % m;

}

void euclid(ll a, ll b, ll *x, ll *y, ll *g)
{

    *x = 0, *y = 1, *g = b;

    ll m, n, q, r, i, j;

    for (i = 1, j = 0; a != 0; *g = a, a = r)
    {

        q = (*g) / a, r = (*g) % a;
        m = (*x) - i * q, n = (*y) - j * q;
        *x = i, *y = j, i = m, j = n;

    }

}

ll exp_pow(ll a, ll e, ll m)
{

    ll ans = 1;

    while (e > 0)
    {

        if (e & 1)
            ans = (ans * a) % MOD;

        a = (a * a) % MOD;
        e >>= 1;

    }

    return ans;

}