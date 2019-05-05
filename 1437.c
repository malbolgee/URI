/*
	@autor: Malbolge;
	@data: 05/05/2019;
	@nomne: Esquerda, Volver!;
*/

#include <stdio.h>

void main ()
{

	int x;
	unsigned i;
	unsigned n;
	char comandos[1001];
	char dir[] = "NLSO";
	
	while (scanf("%u", &n), n)
	{

		scanf("%s", comandos);

		x = 1;
		for (i = 0; i < n; ++i)
			if (comandos[i] == 'D')
			{

				++x;
				if (x > 4)
					x = 1;

			}
			else
			{
				--x;
				if (x == 0)
					x = 4;

			}

		printf("%c\n", dir[x - 1]);

	}

}