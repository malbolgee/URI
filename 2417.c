/*
	@autor: Malbolge;
	@data: 28/12/2018;
	@nome: Campeonato;
*/

#include <stdio.h>

typedef struct _time{

	unsigned short numWins;
	unsigned short numDraws;
 	short numGols;
	short qtsPontos;

} _time;


void main ()
{

	unsigned short i;
	_time flamengo;
	_time corinthians;

	scanf("%hu %hu %hu", &corinthians.numWins, &corinthians.numDraws, &corinthians.numGols);
	scanf("%hu %hu %hu", &flamengo.numWins, &flamengo.numDraws, &flamengo.numGols);

	corinthians.qtsPontos = corinthians.numWins * 3 + corinthians.numDraws;
	flamengo.qtsPontos = flamengo.numWins * 3 + flamengo.numDraws;

	if (corinthians.qtsPontos == flamengo.qtsPontos)
	{

		if (corinthians.numGols == flamengo.numGols)
			printf("=\n");
		else if (corinthians.numGols > flamengo.numGols)
			printf("C\n");
		else
			printf("F\n");

	}
	else if (corinthians.qtsPontos > flamengo.qtsPontos)
		printf("C\n");
	else
		printf("F\n");

}
