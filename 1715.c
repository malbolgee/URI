/*
	@autor: Malbolge;
	@data: 12/02/2019;
	@nome: Handebol;
*/

#include <stdio.h>

#define true 1
#define false 0

typedef unsigned short us;

void main ()
{

	us i, j;
	us numJogadores, numPartidas;

	scanf("%hu %hu", &numJogadores, &numPartidas);

	us tmp, ans = 0;
	for (i = 0; i < numJogadores; ++i)
	{

		us gols = 0;
		for (j = 0; j < numPartidas; ++j)
		{

			scanf("%hu", &tmp);
			if (tmp > 0)
				++gols;

		}

		if (gols == numPartidas)
			++ans;

	}

	printf("%hu\n", ans);

}
