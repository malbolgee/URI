/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Figurinhas da Copa;
*/

#include <stdio.h>

#define MAXSIZE 101
#define true 1
#define false 0

typedef struct figurinha{

	_Bool figCarimbada;
	_Bool figPossuida;

} figurinha;

figurinha album[MAXSIZE] = { false };

void main ()
{

	unsigned short i, tmp;
	unsigned short qtsFigurinhas;
	unsigned short qtsFigurinhasCompradas;
	unsigned short qtsFigurinhasCarimbadas;

	scanf("%hu %hu %hu", &qtsFigurinhas, &qtsFigurinhasCarimbadas, &qtsFigurinhasCompradas);

	for (i = 0; i < qtsFigurinhasCarimbadas; ++i)
	{

		scanf("%hu", &tmp);
		album[tmp].figCarimbada = true;

	}

	for (i = 0; i < qtsFigurinhasCompradas; ++i)
	{

		scanf("%hu", &tmp);
		album[tmp].figPossuida = true;

	}

	for (i = 1; i <= qtsFigurinhas; ++i)
		if (album[i].figPossuida && album[i].figCarimbada)
			qtsFigurinhasCarimbadas--;


	printf("%hu\n", qtsFigurinhasCarimbadas);
}
