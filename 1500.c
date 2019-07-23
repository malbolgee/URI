/*
    @autor: Malbolge;
    @data: 22/07/2019;
    @nome: Consultas Horríveis;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define LSOne(s) (s & (-s))
#define MAXSIZE 100100LL

typedef long long ll;

ll b1[MAXSIZE];
ll b2[MAXSIZE];

ll query(ll);
ll p_query(ll *, ll);
void swap(ll *, ll *);
ll range_query(ll, ll);
void update(ll *, ll, ll);
void range_update(ll, ll, ll);

ll n;

int main(int argc, char **argv)
{

    ll t, o, p, q, v, m;

    scanf("%lld", &t);

    while (t--)
    {

        scanf("%lld %lld", &n, &o);

        memset(b1, 0LL, (n + 1LL) * sizeof(ll));
        memset(b2, 0LL, (n + 1LL) * sizeof(ll));

        while (o--)
        {

            scanf("%lld %lld %lld", &m, &p, &q);

            if (p > q)
                swap(&p, &q);

            if (m == 0LL)
            {
                
                scanf("%lld", &v);
                range_update(p, q, v);

            }
            else
                printf("%lld\n", range_query(p, q));

        }

    }

    return 0;

}

void swap(ll *a, ll *b)
{

    ll c;
    c = *a;
    *a = *b;
    *b = c;

}

ll p_query(ll *ft, ll b)
{

    ll sum = 0LL;
    for (; b; b -= LSOne(b))
        sum += ft[b];

    return sum;

}

ll query(ll b)
{

    return p_query(b1, b) * b - p_query(b2, b);

}

ll range_query(ll i, ll j)
{

    return query(j) - query(i - 1LL);

}

void update(ll *ft, ll k, ll v)
{

    for (; k <= n; k += LSOne(k))
        ft[k] += v;

}

void range_update(ll i, ll j, ll v)
{

    update(b1, i, v);
    update(b1, j + 1LL, -v);
    update(b2, i, v * (i - 1LL));
    update(b2, j + 1LL, -v * j);

}
