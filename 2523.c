/*
	@autor: Malbolge;
	@data: 24/10/2018;
	@nome: A Mensagem de Will;
*/

#include <stdio.h>

void main ()
{

	unsigned short i, numLampadas;
	char stringAlfabeto[30];
	unsigned lampadas;

	while (scanf("%s", stringAlfabeto) != EOF)
	{

		scanf("%hu", &numLampadas);

		while (numLampadas--)
		{

			scanf("%u", &lampadas);
			printf("%c", stringAlfabeto[lampadas - 1]);

		}

		printf("\n");

	}

}
