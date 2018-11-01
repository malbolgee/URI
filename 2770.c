/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Tamanho da Placa;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned alturaPlaca, larguraPlaca, qtsPedidos;
	unsigned alturaPci, larguraPci;
	unsigned areaPlaca, i;

	while (scanf("%u %u %u", &alturaPlaca, &larguraPlaca, &qtsPedidos) != EOF)
	{

		for (i = 0; i < qtsPedidos; i++)
		{
			scanf("%u %u", &alturaPci, &larguraPci);

			if ((alturaPci <= alturaPlaca && larguraPci <= larguraPlaca) || (alturaPci <= larguraPlaca && larguraPci <= alturaPlaca))
				printf("Sim\n");
			else
				printf("Nao\n");
		}

	}
}
