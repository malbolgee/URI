/*
	@autor: Malbolge;
	@data: 28/03/2019;
	@nome: Mesada;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXN 100100
#define INF 0x3f3f3f3f

typedef struct neto{

	int id;
	int mesada;

} neto;

neto st[MAXN << 2];
int lazy[MAXN << 2];
int vet[MAXN];

void build(int, int, int);
void update(int, int, int, int, int, int);
neto query(int, int, int, int, int);
void push(int, int, int);

void main ()
{

	char op;
	int a, b, c;
	int n, q, i;

	while (scanf("%d %d", &n, &q) != EOF)
	{

		for (i = 1; i <= n; ++i)
			scanf("%d", &vet[i]);

		build(1 ,1, n);

		for (i = 0; i < q; ++i)
		{

			scanf(" %c", &op);

			if (op == 'C')
			{

				scanf(" %d %d", &a, &b);
				neto ans = query(1, 1, n, a, b);
				printf("%d\n", ans.id);

			}
			else
			{

				scanf(" %d %d %d", &a, &b, &c);
				update(1, 1, n, a, b, c);

			}

		}

		memset(lazy, 0, sizeof(lazy));

	}

}

void build(int p, int L, int R)
{

	if (L == R)
	{

		st[p].id = L;
		st[p].mesada = vet[L];
		return;

	}

	int m = (L + R) / 2;
	build((p << 1), L, m);
	build((p << 1) + 1, m + 1, R);
	neto cr = st[(p << 1)];
	neto cl = st[(p << 1) + 1];
	if (cr.mesada > cl.mesada || (cr.mesada == cl.mesada && cr.id < cl.id))
		st[p] = cr;
	else
		st[p] = cl;

}

void push(int p, int L, int R)
{

	neto ans = st[p];
	st[p].id = ans.id;
	st[p].mesada = ans.mesada + lazy[p];
	if (L != R)
	{

		lazy[(p << 1)] += lazy[p];
		lazy[(p << 1) + 1] += lazy[p];

	}

	lazy[p] = 0;

}

void update(int p, int L, int R, int a, int b, int v)
{

	push(p, L, R);
	if (a > R || b < L)
		return;

	if (a <= L && b >= R)
	{

		lazy[p] += v;
		push(p, L, R);
		return;

	}

	int m = (L + R) / 2;
	update((p << 1), L, m, a, b, v);
	update((p << 1) + 1, m + 1, R, a, b, v);
	neto cr = st[(p << 1)];
	neto cl = st[(p << 1) + 1];
	if (cl.mesada > cr.mesada || (cl.mesada == cr.mesada && cl.id < cr.id))
		st[p] = cl;
	else
		st[p] = cr;

}

neto query(int p, int L, int R, int a, int b)
{

	push(p, L, R);
	if (a > R || b < L)
	{

		neto ans;
		ans.id = -1;
		ans.mesada = -INF;
		return ans;

	}

	if (a <= L && b >= R)
		return st[p];

	int m = (L + R) / 2;
	neto cr = query((p << 1), L, m, a ,b);
	neto cl = query((p << 1) + 1, m + 1, R, a , b);

	if (cl.mesada > cr.mesada || (cl.mesada == cr.mesada && cl.id < cr.id))
		return cl;
	else
		return cr;

}