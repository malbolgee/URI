/*
	@autor: Malbolge;
	@data: 07/11/2018;
	@nome: Array Hash;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	unsigned short casos, qtsLinhas;
	unsigned short i, qtsCaso;
	unsigned short qtsLetra;
	unsigned somaLetras;

	char string[60];

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &qtsLinhas);

		qtsCaso = 0;
		somaLetras = 0;
		while (qtsLinhas--)
		{

			scanf(" %s", string);

			i = 0;
			qtsLetra = 0;

			while (string[i])
			{

				somaLetras += (string[i] - 65) + qtsCaso + qtsLetra++;

				i++;

			}

			qtsCaso++;

			memset(string, 0, sizeof(string));
		}

		printf("%u\n", somaLetras);

	}

}
