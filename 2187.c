/*
	@autor: Malbolge;
	@data: 01/11/2018;
	@nome: Bits Trocados;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	short bit, aux;
	unsigned short qtsBits50, qtsBits10, qtsBits5, qtsBits1;
	unsigned short qtsTestes = 0;

	while (true)
	{

		scanf("%hu", &bit);

		if (!bit)
			break;

		qtsBits50 = qtsBits10 = qtsBits5 = qtsBits1 = 0;

		qtsBits50 = bit / 50;
		bit = bit % 50;

		qtsBits10 = bit / 10;
		bit = bit % 10;

		qtsBits5 = bit / 5;
		bit = bit % 5;

		qtsBits1 = bit;

		printf("Teste %hu\n", ++qtsTestes);
		printf("%hu %hu %hu %hu\n\n", qtsBits50, qtsBits10, qtsBits5, qtsBits1);


	}

}
