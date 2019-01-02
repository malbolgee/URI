/*
	@autor: Malbolge;
	@data: 02/01/2018;
	@nome: Elevador;
*/

#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int caixas[10005];
int compara(int *, int *);

void main ()
{

	unsigned short pesos, i;
	_Bool ehpossivel = true;
	unsigned short numCaixas;

	scanf("%hu", &numCaixas);

	for (i = 1; i <= numCaixas; ++i)
		scanf("%d", &caixas[i]);

	qsort(caixas, numCaixas + 1, sizeof(int), compara);

	for (i = 1; i <= numCaixas && ehpossivel == true; ++i)
		if (caixas[i] - caixas[i - 1] > 8)
			ehpossivel = false;

	if (!ehpossivel)
		printf("N\n");
	else
		printf("S\n");

}

int compara(int *a, int *b)
{

	if (*a == *b)
		return 0;
	else if (*a > *b)
		return 1;
	else
		return -1;

}
