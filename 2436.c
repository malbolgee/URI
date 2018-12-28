/*
	@autor: Malbolge;
	@data: 28/12/2018;
	@nome: Robô;
*/

#include <stdio.h>

#define MAXSIZE 1000
char salao[MAXSIZE + 2][MAXSIZE + 2];

int main ()
{

	unsigned short qtsVizinhos;
	unsigned short linha, coluna;
	unsigned short qtsLinhas, qtsColunas;
	unsigned short linhaInicial, colunaInicial;

	scanf("%hu %hu", &qtsLinhas, &qtsColunas);
	scanf("%hu %hu", &linhaInicial, &colunaInicial);

	// Como os índices das linhas e colunas começam em 1
	// rodeio o tabuleiro com 0's, assim tenho certeza que
	// Mesmo que, se alguma hora o laço sair do caminho,
	// O robô não sairá da trilha;
	for (linha = 0; linha <= qtsLinhas + 1; ++linha)
	{

		salao[linha][0] = 0;
		salao[linha][qtsColunas + 1] = 0;

	}

	for (coluna = 0; coluna <= qtsColunas + 1; ++coluna)
	{

		salao[0][coluna] = 0;
		salao[coluna + 1][coluna] = 0;

	}

	// preenchimento da matriz;
	for (linha = 1; linha <= qtsLinhas; ++linha)
		for (coluna = 1; coluna <= qtsColunas; ++coluna)
			scanf("%hhd", &salao[linha][coluna]);

	qtsVizinhos = 0;
	for (linha = 1; linha <= qtsLinhas; ++linha)
	{

		for (coluna = 1; coluna <= qtsColunas; ++coluna)
		{

			// A keyword 'continue' força o laço a executar a próxima iteração
			// Ignorando qualquer código após ela;
			// Se a célula que eu estiver analisando contiver um 0, quer dizer que o Robô
			// Não passará por aqui, por isso posso ignorar;
			 if (salao[linha][coluna] == 0)
				continue;

			// Se não for um 0 na célula, quer dizer que é um 1, as únicas células que têm apenas 1 vizinho
			// são as células de início e de fim, por isso, somo todas as células ao redor e verifico se
			// o resultado é 1;
			qtsVizinhos = salao[linha + 1][coluna] + salao[linha - 1][coluna] + salao[linha][coluna + 1] + salao[linha][coluna - 1];


			if (qtsVizinhos == 1 && (linha != linhaInicial || coluna != colunaInicial))
			{

				printf("%hu %hu\n", linha, coluna);
				return 0;

			}

		}

	}

}
