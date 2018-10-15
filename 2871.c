/*
	@autor: Malbolge;
	@data: 14/10/2018;
	@nome: Colheita de Café;
*/

#include <stdio.h>

void main ()
{

	unsigned qtsLinhas, qtsColunas;
	unsigned aux, lavoura, i;
	unsigned qtsSacaCafe, qtsLitrosCafe;

	while (scanf("%u %u", &qtsLinhas, &qtsColunas) != EOF)
	{

		int limite = qtsColunas * qtsLinhas;

		qtsSacaCafe = 0;
		for (i = 0; i < limite; i++)
		{
			scanf("%u", &lavoura);
			qtsSacaCafe += lavoura;
		}

		aux = qtsSacaCafe;
		qtsSacaCafe = qtsSacaCafe / 60;
		qtsLitrosCafe = aux % 60;

		printf("%u saca(s) e %u litro(s)\n", qtsSacaCafe, qtsLitrosCafe);

	}

}
