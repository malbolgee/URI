/*
	@autor: Malbolge;
	@data: 27/10/2018;
	@nome: Avance as Letras;
*/

#include <stdio.h>
#include <stdlib.h>

void main ()
{

	char string1[10010], string2[10010];
	unsigned short i, casos;
	unsigned soma;
	short aux;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s %s", string1, string2);

		for (i = 0; string1[i]; i++)
		{
			aux =  string2[i] - string1[i];
			if (aux < 0)
				soma += aux + 26;
			else
				soma += aux;
		}

		printf("%u\n", soma);
		soma = 0;
	}
}
