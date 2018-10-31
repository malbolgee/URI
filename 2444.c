/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Volume da TV;
*/

#include <stdio.h>

void main ()
{

	short volInicial, qtsTrocas, volume;
	unsigned short i;

	scanf("%hd %hd", &volInicial, &qtsTrocas);

	for (i = 0; i < qtsTrocas; i++)
	{

		scanf("%hd", &volume);

		if (volInicial + volume > 100)
			volInicial = 100;
		else if (volInicial + volume > 0)
			volInicial += volume;
		else
			volInicial = 0;

	}

	printf("%hd\n", volInicial);

}
