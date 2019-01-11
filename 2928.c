/*
	@autor: Malbolge;
	@data: 11/01/2019;
	@nome: Cruzando Lagos;
*/

#include <stdio.h>

typedef struct gelo{

	char linha[10];

}gelo;

#define true 1
#define false 0

void main ()
{

	_Bool pulo = false;
	gelo lago[105] = { 0 };
	unsigned short qtsPulos, i;
	unsigned short qtsLinhas, geloMetros;

	scanf("%hu", &qtsLinhas);

	for (i = 0; i < qtsLinhas; ++i)
		scanf("%s", lago[i].linha);

	geloMetros = qtsPulos = i = 0;
	while (i < qtsLinhas)
	{

		if (lago[i].linha[0] == '.')
		{

			while (lago[i].linha[0] == '.' && i < qtsLinhas)
				++geloMetros, ++i;

			if (geloMetros < 3)
				++qtsPulos, geloMetros = 0;
			else
			{
				printf("N\n");
				return;
			}

		}

	 	++i;

	}

	printf("%hu\n", qtsPulos);

}
