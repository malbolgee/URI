/*
	@autor: Malbolge;
	@data: 26/10/2018;
	@nome: Botas Perdidas;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

	unsigned short ladoDireito;
	unsigned short ladoEsquerdo;

}bota;

unsigned short min(unsigned short, unsigned short);

void main ()
{

	unsigned short casos, i;
	unsigned short numBota, qtsPares;
	bota botas[70];
	char ladoBota;

	while (scanf("%hu", &casos) != EOF)
	{

		i = 0;
		memset(botas, 0, sizeof(botas));
		while (casos--)
		{

			scanf("%hu", &numBota);
			scanf(" %c", &ladoBota);

			if (ladoBota == 'D')
				botas[numBota].ladoDireito++;
			else
				botas[numBota].ladoEsquerdo++;

		}

		qtsPares = 0;
		for (i = 30; i < 70; i++)
			qtsPares += min(botas[i].ladoDireito, botas[i].ladoEsquerdo);

		printf("%hu\n", qtsPares);
	}

}

unsigned short min(unsigned short ladoDireito, unsigned short ladoEsquerdo)
{

	if (ladoEsquerdo < ladoDireito)
		return ladoEsquerdo;
	else
		return ladoDireito;

}
