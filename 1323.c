/*
	@autor: Malbolge;
	@data: 06/10/2018;
	@nome: Feynman;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned short quadrado;
	unsigned resultado;

	while (true)
	{
		scanf("%hu", &quadrado);

		if (quadrado == 0)
			break;

		resultado = 0;
		while (quadrado)
		{
			resultado += (quadrado * quadrado);
			quadrado--;
		}

		printf("%u\n", resultado);

	}
}
