/*
	@autor: Malbolge;
	@data: 29/09/2018;
	@nome: Lavanderia;
*/

#include <stdio.h>

void main ()
{

	unsigned short roupas;
	unsigned short lavaRoupasMim, lavaRoupasMax;
	unsigned short secaRoupasMim, secaRoupasMax;

	scanf("%hu", &roupas);

	scanf("%hu %hu", &lavaRoupasMim, &lavaRoupasMax);
	scanf("%hu %hu", &secaRoupasMim, &secaRoupasMax);

	if (((roupas >= lavaRoupasMim) && (roupas <= lavaRoupasMax)) && ((roupas >= secaRoupasMim) && (roupas <= secaRoupasMax)))
		printf("possivel\n");
	else
		printf("impossivel\n");

}