/*
    @autor: Malbolge;
    @data: 24/07/2019;
    @nome: Trilha Perigosa;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define SIZE 100100
#define SIZEST SIZE << 2

typedef long long ll;

ll vet[SIZE];
ll st[SIZEST];

int count(ll);
void build(int, int, int);
void update(int, int, int, int, ll);
ll range_query(int, int, int, int, int);

int main(int argc, char **argv)
{

    int r, l;
    int n, q, i;

    while (scanf("%d %d %d", &n, &q, &i) != EOF)
    {

        for (i = 1; i <= n; ++i)
            scanf("%d", &r), vet[i] = 1LL << (ll)r;

        build(1, 1, n);
        while (q--)
        {

            scanf("%d %d %d", &i, &r, &l);

            if (i == 1)
                printf("%d\n", count(range_query(1, 1, n, r, l)));
            else
                update(1, 1, n, r, 1LL << (ll)l);        
        }

        return 0;

    }

}

int count(ll n)
{

    int ans = 0;
    while (n)
        ans += n & 1LL, n >>= 1LL;

    return ans;

}

void build(int p, int l, int r)
{

    if (l == r)
        st[p] = vet[l];
    else
    {

        int m = (l + r) >> 1;
        build((p << 1) | 1, l, m);
        build((p << 1) + 2, m + 1, r);
        st[p] = st[(p << 1) | 1] | st[(p << 1) + 2];

    }
    
}

ll range_query(int p, int l, int r, int ql, int qr)
{

    if (ql > r || qr < l)
        return 0LL;

    if (l >= ql && r <= qr)
        return st[p];

    int m = (l + r) >> 1;

    return range_query((p << 1) | 1, l, m, ql, qr) | range_query((p << 1) + 2, m + 1, r, ql, qr);

}

void update(int p, int l, int r, int x, ll v)
{

    if (x > r || x < l)
        return;
    else if (l == x && r == x)
    {

        st[p] &= ~vet[x];
        vet[x] = v;
        st[p] |= vet[l];

    }
    else
    {

        int m = (l + r) >> 1;
        update((p << 1) | 1, l, m, x, v);
        update((p << 1) + 2, m + 1, r, x, v);
        st[p] = st[(p << 1) | 1] | st[(p << 1) + 2];

    }

}