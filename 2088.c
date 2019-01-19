/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Combate à Dengue;
*/

#include <stdio.h>
#include <tgmath.h>

#define true 1
#define false 0
#define INF 0x3f3f3f3f3f3f3f3fLL

int n;
double dist[17][17];
double memoria[17][1 << 17];

double solve(int, int);
double d(int, int, int, int);
double mim(double a, double b);

void main ()
{

	while (scanf("%d", &n), n)
	{

		++n;
		int i, j;
		int x[n], y[n];

		for (i = 0; i < n; ++i)
			scanf("%d %d", &x[i], &y[i]);

		for (i = 0; i < n; ++i)
			for (j = i; j < n; ++j)
				dist[i][j] = dist[j][i] = d(x[i], y[i], x[j], y[j]);

		int tmp = 1 << n;
		for (i = 0; i < n; ++i)
			for (j = 0; j < tmp; ++j)
				memoria[i][j] = -1;

		printf("%.2lf\n", solve(0, 1));

	}

}

double d(int x1, int y1, int x2, int y2)
{

	return hypot(x1 - x2, y1 - y2);

}

double solve(int id, int bitmask)
{

	int i;
	if (bitmask == ((1 << n) - 1))
		return dist[id][0];

	if (memoria[id][bitmask] != -1)
		return memoria[id][bitmask];

	double retorno = INF;
	for (i = 0; i < n; ++i)
		if (!(bitmask & (1 << i)))
			retorno = mim(retorno, dist[id][i] + solve(i, bitmask | (1 << i)));

	return memoria[id][bitmask] = retorno;
}

double mim(double a, double b)
{

	if (a > b)
		return b;
	else
		return a;

}
