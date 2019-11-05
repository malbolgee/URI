/*
    @autor: Malbolge;
    @data: 04/11/2019;
    @nome: Consultas Horríveis;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100100

typedef long long ll;

ll st[MAXSIZE << 2];
ll lz[MAXSIZE << 2];

void swap(int *, int *);
void push(int, int, int);
void build(int, int, int);
ll query(int, int, int, int, int);
void update(int, int, int, int, int, int);

int main(int argc, char **argv)
{

    int n, m, p, q, v, c, t;

    scanf("%d", &t);

    while (t--)
    {
        
        scanf("%d %d", &n, &c);
        build(1, 1, n);

        while (c--)
        {

            scanf("%d %d %d", &m, &p, &q);

            if (p > q)
                swap(&p, &q);

            if (m == 0)
            {
                
                scanf("%d", &v);
                update(1, 1, n, p, q, v);

            }
            else
                printf("%lld\n", query(1, 1, n, p, q));

        }

        memset(lz, 0, sizeof(lz));

    }

    return 0;

}

void swap(int *a, int *b)
{

    *a ^= *b ^= *a ^= *b;

}

void push(int i, int l, int r)
{

    if (lz[i])
    {

        st[i] += lz[i] * (r - l + 1);

        if (l != r)
        {   

            lz[i << 1] += lz[i];
            lz[i << 1 | 1] += lz[i];

        }

        lz[i] = 0LL;

    }

    return;

}

void build(int i, int l, int r)
{

    if (l == r)
        st[i] = 0LL;
    else
    {

        int mid = (l + r) >> 1;

        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        st[i] = 0LL;

    }

}

ll query(int i, int l, int r, int a, int b)
{

    push(i, l, r);
    if (b < l || a > r)
        return 0LL;

    if (a <= l && b >= r)
        return st[i];

    int mid = (l + r) >> 1;
    ll x = query(i << 1, l, mid, a, b);
    ll y = query(i << 1 | 1, mid + 1, r, a, b);

    return x + y;

}

void update(int i, int l, int r, int a, int b, int x)
{

    push(i, l, r);
    if (b < l || r < a)
        return;

    if (a <= l && b >= r)
    {

        lz[i] += x, 
        push(i, l, r);

    }
    else
    {

        int mid = (l + r) >> 1;
        update(i << 1, l, mid, a, b, x);
        update(i << 1 | 1, mid + 1 , r, a, b, x);

        st[i] = st[i << 1] + st[i << 1 | 1];

    }

    return;

}