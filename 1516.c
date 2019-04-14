/*
	@autor: Malbolge;
	@data: 09/04/2019;
	@nome: Imagem;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSZIE 500

char grid[MAXSZIE][MAXSZIE];

void main ()
{

	char i, j, k, z;
	char linha, coluna;
	char altura, largura;
	char nova_altura, nova_largura;
	char proporcao_largura, proporcao_altura;

	while (scanf("%hhd %hhd", &altura, &largura), altura)
	{

		for (linha = 0; linha < altura; ++linha)
			for (coluna = 0; coluna < largura; ++coluna)
				scanf(" %c", &grid[linha][coluna]);

		scanf(" %hhd %hhd", &nova_altura, &nova_largura);

		proporcao_largura = nova_largura / largura;
		proporcao_altura = nova_altura / altura;

		for (i = 0; i < altura; ++i)
		{
			
			for (z = 0; z < proporcao_altura; ++z)
			{
				for (j = 0; j < largura; ++j)
				{

					for (k = 0; k < proporcao_largura; ++k)
						printf("%c", grid[i][j]);

				}

				printf("\n");

			}

		}

		printf("\n");

	}

}