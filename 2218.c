/*
	@autor: Malbolge;
	@data: 09/12/2018;
	@nome: O Temível Evil-Son;
*/

#include <stdio.h>

void main ()
{

	unsigned qtsCasos;
	unsigned qtsLinhas;

	scanf("%u", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%u", &qtsLinhas);

		printf("%u\n", (((qtsLinhas * (qtsLinhas + 1)) / 2) + 1));

	}

}
