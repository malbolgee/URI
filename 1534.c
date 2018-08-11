/*
	@autor: Malbolge;
	@data: 09/08/2018;
	@nome: Matriz 123;
*/

#include <stdio.h>

int main ()
{

	unsigned short int tamanho, linha, coluna;

	while (scanf("%hd", &tamanho) != EOF)
	{
		short matriz[tamanho][tamanho];

		for (linha = 0; linha < tamanho; linha++)
			for (coluna = 0; coluna < tamanho; coluna++)
			{
				if (linha == coluna)
					matriz[linha][coluna] = 1;
				if (linha == tamanho - coluna - 1)
					matriz[linha][coluna] = 2;
				if (linha != coluna && linha != tamanho - coluna - 1)
					matriz[linha][coluna] = 3;
			}

		for (linha = 0; linha < tamanho; linha++)
		{
			for (coluna = 0; coluna < tamanho; coluna++)
				printf("%d", matriz[linha][coluna]);

			printf("\n");
		}
	}
}
