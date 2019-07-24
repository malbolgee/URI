/*
    @autor: Malbolge;
    @data: 23/07/2019;
    @nome: Homem, Elefante e Rato;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define SIZE 100100
#define SIZEST SIZE << 2

int lz[SIZEST];
int st[SIZEST][3];

void swap(int *, int *);
void push(int, int, int);
void build(int, int, int);
inline void __add(int *, int *);
void range_update(int, int, int, int, int);
void range_query(int, int, int, int, int, int *);

int main(int argc, char **argv)
{

    char op;
    int ans[3];
    int i, n, m, a, b;

    while (scanf("%d %d%*c", &n, &m) != EOF)
    {

        build(1, 1, n);
        while (m--)
        {

            scanf("%c %d %d%*c", &op, &a, &b);
            if (op == 'C')
            {

                memset(ans, 0, sizeof(ans));
                range_query(1, 1, n, a, b, ans);
                printf("%d %d %d\n", ans[0], ans[1], ans[2]);

            }
            else
                range_update(1, 1, n, a, b);

        }

        putchar_unlocked('\n');

    }

    return 0;

}

void swap(int *a, int *b)
{

    int c;
    c = *a;
    *a = *b;
    *b = c;

}

void push(int p, int l, int r)
{

    if (lz[p] == 1)
    {

        swap(&st[p][0], &st[p][1]);
        swap(&st[p][0], &st[p][2]);

    }
    else if (lz[p] == 2)
    {

        swap(&st[p][0], &st[p][2]);
        swap(&st[p][0], &st[p][1]);

    }

    if (lz[p] && l != r)
    {

        lz[p << 1] = (lz[p << 1] + lz[p]) % 3;
        lz[(p << 1) + 1] = (lz[(p << 1) + 1] + lz[p]) % 3;

    }

    lz[p] = 0;

}

void range_query(int p, int l, int r, int ql, int qr, int *ans)
{

    push(p, l, r);
    if (l > qr || r < ql)
        return;
    else if (l >= ql && r <= qr)
        __add(ans, st[p]);
    else
    {

        int m = (l + r) >> 1;
        range_query(p << 1, l, m, ql, qr, ans);
        range_query((p << 1) + 1, m + 1, r, ql, qr, ans);
        
    }    

}

void range_update(int p, int l, int r, int ql, int qr)
{

    push(p, l, r);
    if (l > qr || r < ql)
        return;
    else if (l >= ql && r <= qr)
        lz[p] = 1, push(p, l, r);
    else
    {

        int m = (l + r) >> 1;
        range_update(p << 1, l, m, ql, qr);
        range_update((p << 1) + 1, m + 1, r, ql, qr);
        memset(st[p], 0, sizeof(st[p]));
        __add(st[p], st[p << 1]);
        __add(st[p], st[(p << 1) + 1]);

    }

}

void __add(int *ans, int *line)
{

    int i;
    for (i = 0; i < 3; ++i)
        ans[i] += line[i];

}

void build(int p, int l, int r)
{

    lz[p] = 0;
    memset(st[p], 0, sizeof(st[p]));
    if (l == r)
        st[p][0] = 1;
    else
    {

        int m = (l + r) >> 1;
        build(p << 1, l, m);
        build((p << 1) + 1, m + 1, r);
        __add(st[p], st[p << 1]);
        __add(st[p], st[(p << 1) + 1]);

    }

}
