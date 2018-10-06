/*
	@autor: Malbolge;
	@data: 06/10/2018;
	@nome: Figurinhas;
*/

#include <stdio.h>

void main ()
{

	int ricardo, vicente, resultado = 0;
	int casos;

	scanf("%ds", &casos);

	while (casos--)
	{

		scanf("%d %d", &ricardo, &vicente);

		// MDC simples;
		while (vicente != 0)
		{

			resultado = ricardo % vicente;
			ricardo = vicente;
			vicente = resultado;

		}

		printf("%d\n", ricardo);

	}
}
