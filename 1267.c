/*

	@autor: Malbolge;
	@data: 13/07/2019;
	@nome: Biblioteca Pascal;

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{

	int linhas, colunas, i, j;

	while (scanf("%d %d", &colunas, &linhas), linhas)
	{

		char matrix[linhas][colunas];

		for (i = 0; i < linhas; ++i)
			for (j = 0; j < colunas; ++j)
				scanf("%hhd", &matrix[i][j]);

		int cont;
		_Bool is = false;
		for (j = 0; j < colunas; ++j)
		{

			cont = 0;
			for (i = 0; i < linhas; ++i)
				if (matrix[i][j])
					cont++;
			
			if (cont == linhas)
				is = true;

		}

		printf("%s\n", is ? "yes" : "no");

	}

	return 0;

}