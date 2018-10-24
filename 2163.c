/*
	@autor: Malbolge;
	@data: 24/10/2018;
	@nome: O Despertar da Força;
*/

#include <stdio.h>

void main ()
{

	unsigned short posiLinha, posiColuna;
	unsigned short qtsLinha, qtsColuna;
	short linha, coluna;

	scanf("%hu %hu", &qtsLinha, &qtsColuna);

	short matriz[qtsLinha][qtsColuna];

	for (linha = 0; linha < qtsLinha; linha++)
		for (coluna = 0; coluna < qtsColuna; coluna++)
			scanf("%hd", &matriz[linha][coluna]);

	qtsLinha--; qtsColuna--;
	posiLinha = posiColuna = 0;
	for (linha = 1; linha < qtsLinha; linha++)
		for (coluna = 1; coluna < qtsColuna; coluna++)
			if (matriz[linha][coluna] == 42)
				{

					if (matriz[linha - 1][coluna - 1] == 7 && matriz[linha - 1][coluna] == 7 && matriz[linha - 1][coluna + 1] == 7 && matriz[linha][coluna - 1] == 7 && matriz[linha][coluna + 1] == 7
						&& matriz[linha + 1][coluna - 1] == 7 && matriz[linha + 1][coluna] == 7 && matriz[linha + 1][coluna + 1] == 7)
						{
							
							posiLinha = linha;
							posiColuna = coluna;

						}

				}

	if (posiLinha == 0 && posiColuna == 0)
		printf("%hu %hu\n", posiLinha, posiColuna);
	else
		printf("%hu %hu\n", posiLinha + 1, posiColuna + 1);

}
