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

		// Declaração de uma matriz onde a quantidade de linhas e colunas
		// Tem uma unidade a mais, pois a questão considera a primeira linha e coluna
		// Como sendo 1 e não 0 como é o padrão;
		unsigned floresta[ordem + 1][ordem + 1];
		// Vetor onde irão ficar as espécies já vistas;
		unsigned especiesVistas[ordem * ordem];

		aux = ordem + 1;
		// Inicializa a matriz com todos os valores como 0;
		memset(floresta, 0, sizeof(floresta));
		// Preenche a matriz;
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

			// Se a especie achada ainda não foi vista, a quantidade de espécies
			// Capturadas incrementa e a especie atual é colocada no vetor de
			// Espécies já vistas;
			if (!procuraEspecie(especiesVistas, floresta[linha][coluna], i))
			{
				qtsEspecies++;
				especiesVistas[i++] = floresta[linha][coluna];
			}

		}

		printf("%hu\n", qtsEspecies);

	}

}

// Função que procura uma espécie no vetor de espécies;
bool procuraEspecie(unsigned *especiesVistas, unsigned numero, unsigned tam)
{

	unsigned i;
	for (i = 0; i < tam; i++)
		if (especiesVistas[i] == numero)
			return true;

	return false;

}
