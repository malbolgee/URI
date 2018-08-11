/*
	@autor: Malbolge;
	@data: 06/08/218;
	@nome: Matriz Quadrada I;
*/

#include <stdio.h>

int main ()
{

	unsigned short int tamanho, coluna, linha, iniMatriz, fimMatriz, elemento;

	do
	{

		scanf("%hd", &tamanho);
		int m[tamanho][tamanho];

		if (tamanho == 0)
			return 0;

		iniMatriz = 0;
		fimMatriz = tamanho;
		elemento = 1;

		while(1)
		{

			for (linha = iniMatriz; linha < fimMatriz; linha++)
				for (coluna = iniMatriz; coluna < fimMatriz; coluna++)
					m[linha][coluna] = elemento;

			if (fimMatriz == 0)
				break;

			fimMatriz--;
			iniMatriz++;
			elemento++;

		}

		for (linha = 0; linha < tamanho; linha++)
		{
			for (coluna = 0; coluna < tamanho; coluna++)
			{
				if (coluna == 0)
					printf("%3hd", m[linha][coluna]);
				else
					printf(" %3hd", m[linha][coluna]);

			}

			printf("\n");
		}

		printf("\n");

	}while(tamanho != 0);
}
