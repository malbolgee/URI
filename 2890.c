/*
    @autor: Malbolge;
    @data: 06/03/2019;
    @nome: Colorindo Tetraedros;
*/

#include <stdio.h>

#define MOD 1000007

typedef long long ll;

ll pow2(ll);
ll pow4(ll);
ll inverso(ll );
ll mdc(ll, ll, ll *, ll *);

void main ()
{

    ll n;
    while (scanf("%lld", &n), n)
        printf("%lld\n", (((11 * pow2(n) + pow4(n)) % MOD)) * inverso(12) % MOD);

}

ll pow2(ll a)
{

    ll i, result = 1;
    for (i = 0; i < 2; ++i)
        result = (result * a) % MOD;

    return result;

}

ll pow4(ll a)
{

    ll i, result = 1;
    for (i = 0; i < 4; ++i)
        result = (result * a) % MOD;

    return result;

}

ll inverso(ll a)
{

    ll x, y, d;
    d = mdc(a, MOD, &x, &y);
    if (x < 0)
        x = x + MOD;

    return x;

}

ll mdc(ll a, ll b, ll *x, ll *y)
{

    ll xx, yy, d;

    if (b == 0LL)
    {

        *x = 1LL;
        *y = 0LL;
        return a;

    }

    d = mdc(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - ((a / b) * yy);

    return d;

}