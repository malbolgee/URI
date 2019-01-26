/*
	@autor: Malbolge;
	@data: 25/01/2019;
	@nome: Produto do Intervalo;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAX 100100
#define MAXST MAX*4
#define MIM(a, b) a > b ? b : a

void biuld(int, int, int);
void update(int, int, int, int, int);
long long query(int, int, int, int, int);

long long st[MAXST];
long long vetor[MAX];

void main ()
{

	int i;
	char comando;
	int n, k, a, b;

	while (scanf("%d %d", &n, &k) != EOF)
	{

		for (i = 1; i <= n; ++i)
			scanf("%lld", &vetor[i]);

		biuld(1, 1, n);
		for (i = 0; i < k; ++i)
		{

			scanf(" %c%*c", &comando);

			if (comando == 'C')
				scanf("%d %d", &a, &b), update(1, 1, n, a, b);
			else
			{

				scanf("%d %d", &a, &b);
				long long ans = query(1, 1, n, a, b);
				printf("%s", ans == 0 ? "0" : ans > 0 ? "+" : "-");

			}

		}

		printf("\n");

	}

}

void biuld(int p, int l, int r)
{

	if (l == r)
	{

		st[p] = vetor[l];
		return;

	}

	biuld(p * 2, l, (l + r) / 2);
	biuld((p * 2) + 1, ((l + r) / 2) + 1, r);

	int ans = st[p * 2] * st[p * 2 + 1];
	st[p] = ans == 0 ? 0 : ans > 0 ? 1 : -1;

}

void update(int p, int l, int r, int x, int v)
{

	if (l == r)
	{

		vetor[x] = st[p] = v;
		return;

	}

	if (x <= (l + r) / 2)
		update(p * 2, l, (l + r) / 2, x, v);
	else
		update((p * 2) + 1, ((l + r) / 2) + 1, r, x, v);

	int ans = st[p * 2] * st[p * 2 + 1];
	st[p] = ans == 0 ? 0 : ans > 0 ? 1 : -1;

}

long long query(int p, int l, int r, int a, int b)
{

	if (a <= l && b >= r)
		return st[p];

	if (b < l || a > r)
		return 1;

	long long rL = query(p * 2, l, (l + r) / 2, a, b);
	long long rR = query(p * 2 + 1, ((l + r) / 2) + 1, r, a, b);

	int ans = rL * rR;
	return ans == 0 ? 0 : ans > 0 ? 1 : -1;

}
