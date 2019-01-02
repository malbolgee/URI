/*
	@autor: Malbolge;
	@data: 31/12/2018;
	@nome: Enigma;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned short enigma(char *, char *);

void main ()
{

	char crib[10500];
	char cifra[10500];

	scanf("%s %s", cifra, crib);

	enigma(cifra, crib);

	printf("%hu\n", enigma(cifra, crib));

}

unsigned short enigma(char *cifra, char *crib)
{

	bool igualdades = false;
	unsigned short i, j, k;
	unsigned limite = strlen(cifra) - strlen(crib);
	unsigned short qtsPosicoesPossiveis;

	i = j = k = 0;
	igualdades = 0;
	qtsPosicoesPossiveis = 0;

	if (!limite)
	{

		while (cifra[i])
		{

			if (cifra[i] == crib[j])
			{
				igualdades = true;
				break;
			}

			i++;
			j++;

		}

		if (!igualdades)
			return 1;
		else
			return 0;

	}

	while (k <= limite)
	{

		j = 0;
		i = k;
		igualdades = 0;
		while (cifra[i] && crib[j])
		{

			if (cifra[i] == crib[j])
			{

				igualdades = true;
				break;

			}

			++j;
			++i;

		}

		k++;

		if (!igualdades)
			qtsPosicoesPossiveis++;

	}

	return qtsPosicoesPossiveis;

}
