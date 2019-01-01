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

	unsigned short i, j, k;
	unsigned limite = strlen(cifra) - strlen(crib);
	unsigned short igualdades, qtsPosicoesPossiveis;

	i = j = k = 0;
	igualdades = 0;
	qtsPosicoesPossiveis = 0;

	// Se o limite for 0, quer dizer que a cifra e o crib têm o mesmo tamanho;
	// é, por tanto, um caso especial;
	if (!limite)
	{

		while (cifra[i])
		{

			if (cifra[i] == crib[j])
				++igualdades;

			i++;
			j++;

		}

		// Se não encontrou nenhuma igualdade, então só há uma posição possível;
		if (!igualdades)
			return 1;
		else
			return 0;

	}

	// Se as strings forem de tamanhos diferentes;
	while (k <= limite)
	{

		j = 0;
		// A cada iteração, o índice em que a string cifra começa é empurrado uma
		// unidade para a direita;
		i = k;
		igualdades = 0;
		while (cifra[i] && crib[j])
		{

			if (cifra[i] == crib[j])
				++igualdades;

			++j;
			++i;

		}

		k++;

		// Se na iteração passada não houve iguldades, então essa era uma posição possível
		// para o crib;
		if (!igualdades)
			qtsPosicoesPossiveis++;

	}

	return qtsPosicoesPossiveis;

}
