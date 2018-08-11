/*
	@autor: Malbolge;
	@data: 09/08/2018;
	@nome: Matriz Quadrada II;
*/

#include <stdio.h>

int main ()
{

	unsigned short int tamanho, linha, coluna;

	do
	{

		scanf("%hd", &tamanho);
		short matriz[tamanho][tamanho];

		if (tamanho == 0)
			return 0;

		for(linha = 0; linha < tamanho; linha++)
			for(coluna = 0; coluna < tamanho; coluna++)
			{

				if (linha == coluna)
					matriz[linha][coluna] = 1;
				if (linha < coluna)
					matriz[linha][coluna] = 1 + coluna - linha;
				if (linha > coluna)
					matriz[linha][coluna] = 1 + linha - coluna;
			}

		for (linha = 0; linha < tamanho; linha++)
		{
			for (coluna = 0; coluna < tamanho; coluna++)
			{
				if (coluna == 0)
					printf("%3hd", matriz[linha][coluna]);
				else
					printf(" %3hd", matriz[linha][coluna]);

			}

			printf("\n");
		}

		printf("\n");

	} while (tamanho != 0);
}
