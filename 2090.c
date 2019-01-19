/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Fui ao Mercado e Comprei...;
*/

#include <stdio.h>

typedef struct string{

	char produto[30];

} string;

#define true 1
#define false 0
#define MAXSIZE 100100

void main ()
{

	unsigned i, j;
	unsigned n, k;
	string shepa[MAXSIZE];

	while (scanf("%d %d", &n, &k), n)
	{

		long long hi, low, mid;
		for (i = 1; i <= n; ++i)
			scanf("%s", shepa[i].produto);

		low = 1; hi = n;
		while (low < hi)
		{

			mid = low + (hi - low) / 2;
			if (mid * (mid + 1) / 2 >= k)
				hi = mid;
			else
				low = mid + 1;

		}

		printf("%s\n", shepa[k - ((low - 1) * low / 2)].produto);

	}


}
