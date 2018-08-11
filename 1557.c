/*
	@autor: Malbolge;
	@data: 09/08/2018;
	@nome: Matriz Quadrada III;
*/

#include <stdio.h>

int main ()
{

	unsigned short int tamanho, linha, coluna;
 	int elemento;

	while (1)
	{

		scanf("%hd", &tamanho);

		//Caso o tamanho seja 0, o programa termina;
		if (tamanho == 0)
			return 0;

		int matriz[tamanho][tamanho];

		elemento = 1;

		for (linha = 0; linha < tamanho; linha++)
		{
			for (coluna = 0; coluna < tamanho; coluna++)
			{
				matriz[linha][coluna] = elemento;
				elemento *= 2;
			}

			//Elemento recebe o valor da linha atual vezes 2;
			elemento = (matriz[linha][0]) * 2;

		}

		unsigned short int digitos = 0;
		int t;

		//Determinar o maior número da matriz
		//Sempre vai ser o elemento da última linha e coluna;
		t = (matriz[tamanho - 1][tamanho - 1]);

		//Conta os dígitos do maior número da matriz;
		do
		{

			t % 10;
			t = t/10;
			digitos++;

		} while (t > 0);

		for (linha = 0; linha < tamanho; linha++)
		{
			for (coluna = 0; coluna < tamanho; coluna++)
			{
				if (coluna == 0)
					//Prints com tamanho variado para o campo de espaços;
					printf("%*d", digitos, matriz[linha][coluna]);
				else
					printf(" %*d", digitos, matriz[linha][coluna]);
			}

			printf("\n");
		}

		printf("\n");

	}
}
