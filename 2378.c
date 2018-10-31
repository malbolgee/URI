/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Elevador;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned short qtsLeituras, capacidadeMax;
	unsigned short i, qtsPessoasSairam, qtsPessoasEntraram;
	short lotacaoAtual;
	bool ultrapassou = false;

	scanf("%hu %hu", &qtsLeituras, &capacidadeMax);

	lotacaoAtual = 0;
	for (i = 0; i < qtsLeituras; i++)
	{

		scanf("%hd %hd", &qtsPessoasSairam, &qtsPessoasEntraram);

		lotacaoAtual += qtsPessoasEntraram - qtsPessoasSairam;

		if (lotacaoAtual > capacidadeMax && ultrapassou == false)
			ultrapassou = true;

	}

	if (ultrapassou)
		printf("S\n");
	else
		printf("N\n");
}
