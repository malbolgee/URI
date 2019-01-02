/*
	@autor: Malbolge;
	@data: 02/01/2018;
	@nome: Pesos;
*/

#include <stdio.h>
#define true 1
#define false 0

int caixas[10005];

void main ()
{

	unsigned short pesos, i;
	_Bool ehpossivel = true;
	unsigned short numCaixas;

	scanf("%hu", &numCaixas);

	for (i = 1; i <= numCaixas; ++i)
		scanf("%d", &caixas[i]);

	for (i = 1; i <= numCaixas && ehpossivel == true; ++i)
		if (caixas[i] - caixas[i - 1] > 8)
			ehpossivel = false;

	if (!ehpossivel)
		printf("N\n");
	else
		printf("S\n");

}
