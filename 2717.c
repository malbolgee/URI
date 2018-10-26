/*
	@autor: Malbolge;
	@data: 25/10/2018;
	@nome: Tempo do Duende;
*/

#include <stdio.h>

void main ()
{

	unsigned short qtsMinutosRestantes;
	unsigned short minutosNecessariosA, minutosNecessariosB;

	scanf("%hu", &qtsMinutosRestantes);

	scanf("%hu %hu", &minutosNecessariosA, &minutosNecessariosB);

	if (minutosNecessariosA + minutosNecessariosB > qtsMinutosRestantes)
		printf("Deixa para amanha!\n");
	else
		printf("Farei hoje!\n");


}
