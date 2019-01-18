/*
	@autor: Malbolge;
	@data: 18/01/2019;
	@nome: Cola;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 100100


void main ()
{

	unsigned i, j;
	unsigned n, m;
	unsigned juan[MAXSIZE];
	unsigned ricardinho[MAXSIZE];

	while (scanf("%u %u", &n, &m) != EOF)
	{

		for (i = 0; i < n; ++i)
			scanf("%u", &juan[i]);

		for (i = 0; i < m; ++i)
			scanf("%u", &ricardinho[i]);

		i = j = 0;
		while (i < m && j < n)
		{

			if (ricardinho[i] == juan[j])
				++i;

			++j;

		}

		if (i == m)
			printf("sim\n");
		else
			printf("nao\n");

	}


}
