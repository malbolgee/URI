/*
	@autor: Malbolge;
	@data: 07/11/2018;
	@nome: Variações;
*/

#include <stdio.h>
#include <ctype.h>

void main ()
{

	unsigned qtsPossibilidades;
	unsigned short casos;
	unsigned short i;
	char string[20];

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s", string);

		i = 0;
		qtsPossibilidades = 1;
		while (string[i])
		{

			if (tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 's')
				qtsPossibilidades *= 3;
			else
				qtsPossibilidades *= 2;

			i++;
		}

		printf("%u\n", qtsPossibilidades);

	}

}
