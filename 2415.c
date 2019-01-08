/*
	@autor: Malbolge;
	@data: 08/01/2019;
	@nome: Consecutivos;
*/

#include <stdio.h>

#define MAXSIZE 10500

void main ()
{

	int num[MAXSIZE];
	int qtsPontos, atual;
	unsigned i, numValores;

	scanf("%u", &numValores);

	for (i = 0; i < numValores; ++i)
		scanf("%d", &num[i]);

	i = 1;
	qtsPontos = atual = 0;
	while (i <= numValores)
	{

		if (num[i - 1] == num[i])
			atual++;
		else
			if (atual > qtsPontos)
				qtsPontos = atual, atual = 0;
			else
				atual = 0;

		++i;
	}

	printf("%u\n", qtsPontos + 1);

}
