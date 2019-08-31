/*
    @autor: Nilson Andrade;
    @data: 30/08/2019;
    @nome: Tribol;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{

	char a, b;
	int n, q, i, u, v;
	char adj[4][3] = {{0, 2, 1}, {1 , 0, 2}, {2, 1, 0}, {0, 0, 0}};
	char ans[5][10] = {"red", "green", "blue", "empate", "trempate"};

	scanf("%d", &n);

	while (n--)
	{

		scanf("%d%*c", &q);
		memset(&adj[3], 0, sizeof(adj[3]));

		while(q--)
		{

			scanf("%c %c%*c", &a, &b);
			if (a == 'R')
				u = 0;
			else if (a == 'G')
				u = 1;
			else
				u = 2;

			if (b == 'R')
				v = 0;
			else if (b == 'G')
				v = 1;
			else
				v = 2;

			adj[3][u] += adj[u][v];

		}

		int maior = adj[3][0], cont = 0;

		for (i = 1; i < 3; ++i)
		{

			if (adj[3][i] > maior)
				maior = adj[3][i], cont = i;
			else
				if (adj[3][i] == maior)
					cont = cont == 3 ? 4 : 3;

		}

		printf("%s\n", ans[cont]);

	}

	return 0;

}