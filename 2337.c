/*
    @autor: Malbolge;
    @data: 07/09/2019;
    @nome: Pro Habilidade;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1010

typedef long long ll;

void solve();
ll mdc(ll, ll);
ll mmc(ll, ll);

typedef struct {

    ll num;
    ll den;

} ans_t;

ll fib[MAXSIZE];
ans_t ans[MAXSIZE];

// https://www.fq.math.ca/Papers1/49-3/GriffithsCoinToss.pdf

int main(int argc, char **argv)
{

    ll n;
    solve();
    while (~scanf("%lld", &n))
        printf("%lld/%lld\n", ans[n].num, ans[n].den);

    return 0;

}

void solve()
{

    fib[0] = 0LL;
    fib[1] = 2LL;
    fib[2] = 3LL;

    int i;
    for (i = 3; i < 42; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];

    for (i = 1; i < 42; ++i)
    {

        ll tmp = mdc(fib[i], 1LL << i);
        ans[i].num = fib[i] / tmp;
        ans[i].den = (1LL << i) / tmp;

    }

}

ll mdc(ll a, ll b)
{

    if (!b)
        return a;

    return mdc(b, a % b);

}

ll mmc(ll a, ll b)
{

    return (a / mdc(a, b)) * b;

}