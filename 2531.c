/*
	@autor: Malbolge;
	@data: 26/01/2019;
	@nome: Compras em Fdl;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXX 1000100
#define MAXST MAXX*4
#define INF 0x3f3f3f3
#define MID ((l + r) / 2)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

typedef struct preco{

	int maior;
	int menor;

} preco;

preco st[MAXST];
int vetor[MAXX];

void biuld(int, int, int);
void update(int, int, int, int, int);
preco query(int, int, int, int, int);

void main ()
{

	unsigned a, b;
	unsigned i, n, tmp, q;

	while (scanf("%u", &n) != EOF)
	{

		for(i = 1; i <= n; ++i)
			scanf("%u", &vetor[i]);

		biuld(1, 1, n);
		scanf("%d", &q);

		while (q--)
		{

			scanf("%u", &tmp);

			if (tmp == 1)
				scanf("%u %u", &a, &b), update(1, 1, n, a, b);
			else
			{

				scanf("%u %u", &a, &b);
				preco ans = query(1, 1, n, a, b);
				printf("%u\n", abs(ans.maior - ans.menor));

			}

		}

	}
}

void biuld(int p, int l, int r)
{

	if (l == r)
	{

		st[p].maior = st[p].menor = vetor[l];
		return;

	}

	biuld(p * 2, l, MID);
	biuld(p * 2 + 1, MID + 1, r);

	st[p].maior = MAX(st[p * 2].maior, st[p * 2 + 1].maior);
	st[p].menor = MIN(st[p * 2].menor, st[p * 2 + 1].menor);

}

void update(int p , int l, int r, int x, int v)
{

	if (l == r)
	{

		vetor[x] = st[p].maior = st[p].menor = v;
		return;

	}

	if (x <= MID)
		update(p * 2, l, MID, x, v);
	else
		update(p * 2 + 1, MID + 1, r, x , v);

	st[p].maior = MAX(st[p * 2].maior, st[p * 2 + 1].maior);
	st[p].menor = MIN(st[p * 2].menor, st[p * 2 + 1].menor);

}

preco query(int p, int l, int r, int a, int b)
{

	if (a <= l && b >= r)
		return st[p];

	preco tmp;
	tmp.maior = -INF;
	tmp.menor = INF;
	if (b < l || a > r)
		return tmp;

	preco rL = query(p * 2, l, MID, a, b);
	preco rR = query(p * 2 + 1, MID + 1, r, a, b);

	preco ans;
	ans.maior = MAX(rL.maior, rR.maior);
	ans.menor = MIN(rL.menor, rR.menor);

	return ans;

}
