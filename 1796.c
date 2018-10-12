/*
	@autor: Malbolge;
	@data: 12/10/2018;
	@nome: Economia Brasileira;
*/

#include <stdio.h>

void main ()
{

	unsigned satisfeitos = 0, naoSatisfeitos = 0;
	unsigned qtsCidadoes, i, opiniao;

	scanf("%u", &qtsCidadoes);

	for (i = 0; i < qtsCidadoes; i++)
	{
		scanf("%u", &opiniao);

		if (opiniao == 0)
			satisfeitos++;
		else
			naoSatisfeitos++;

	}

	if (satisfeitos > naoSatisfeitos)
		printf("Y\n");
	else
		printf("N\n");

}
