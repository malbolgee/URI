/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Álbum da Copa;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 101

void main ()
{

	unsigned short i, tmp;
	unsigned short qtsFigurinhas;
	unsigned short figurinhasCompradas;

	scanf("%hu %hu", &qtsFigurinhas, &figurinhasCompradas);

	_Bool album[MAXSIZE] = { false };

	for (i = 0; i < figurinhasCompradas; ++i)
	{

		scanf("%hu", &tmp);
		album[tmp] = true;

	}

	unsigned short faltam = 0;
	for (i = 1; i <= qtsFigurinhas; ++i)
		if (!album[i])
			faltam++;

	printf("%hu\n", faltam);

}
