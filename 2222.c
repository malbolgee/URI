/*
	@autor: Malbolge;
	@data: 25/05/2019;
	@nome: Brincando com Conjuntos;
*/

#include <stdio.h>

#define true 1
#define false 0

typedef long long unsigned llu;

llu grid[10010];

unsigned count(llu x);

int main (int argc, char **argv)
{

	int t, n, i, j, k;
	scanf("%d", &t);

	while (t--)
	{

		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{

			grid[i] = 0;
			scanf("%d", &j);
			while (j--)
				scanf("%d", &k), grid[i] |= (1LL << k);

		}

		scanf("%d", &n);
		while (n--)
		{

			scanf("%d %d %d", &k, &i, &j);
			printf("%u\n", k == 1 ? count(grid[--i] & grid[--j]) : count(grid[--i] | grid[--j]));

		}

	}

	return 0;

}

unsigned count(llu x)
{

	unsigned ans = 0;
	while (x)
		ans += x & 1, x >>= 1;

	return ans;

}