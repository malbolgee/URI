/*
	@autor: Malbolge;
	@data: 16/10/2018;
	@nome: Borboletas;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool procuraEspecie(unsigned *, unsigned numero, unsigned tam);

void main ()
{


	unsigned qtsLinhas, ordem, i;
	unsigned linha, coluna;
	unsigned qtsEspecies, aux;

	while (scanf("%u", &ordem) != EOF)
	{

		unsigned floresta[ordem + 1][ordem + 1];
		unsigned especiesVistas[ordem * ordem];

		aux = ordem + 1;
		memset(floresta, 0, sizeof(floresta));
		for (linha = 1; linha < aux; linha++)
			for (coluna = 1; coluna < aux; coluna++)
				scanf("%u", &floresta[linha][coluna]);

		i = 0;
		qtsEspecies = 0;
		qtsLinhas = ordem * 2;
		memset(especiesVistas, 0, sizeof(especiesVistas));
		while (qtsLinhas--)
		{

			scanf("%u %u", &linha, &coluna);

			if (!procuraEspecie(especiesVistas, floresta[linha][coluna], i))
			{
				qtsEspecies++;
				especiesVistas[i++] = floresta[linha][coluna];
			}

		}

		printf("%hu\n", qtsEspecies);

	}

}

bool procuraEspecie(unsigned *especiesVistas, unsigned numero, unsigned tam)
{

	unsigned i;
	for (i = 0; i < tam; i++)
		if (especiesVistas[i] == numero)
			return true;

	return false;

}
