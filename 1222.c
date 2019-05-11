/*
	@autor: Malbolge;
	@data: 11/05/2019;
	@nome: Concurso de Contos;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

#define MAXSIZE 70

void main ()
{

	int i, l, c, n, x;
	int linhas, paginas, letras;
	char palavra[MAXSIZE + 1];

	while (scanf("%d %d %d", &n, &l, &c) != EOF)
	{

		paginas = linhas = 1;
		scanf("%s", palavra);
		letras = strlen(palavra);

		n--;
		for (i = 0; i < n; ++i)
		{

			scanf("%s", palavra);

			x = strlen(palavra);

			if ((letras + x + 1) <= c)
				letras += x + 1;
			else
			{

				++linhas;
				if (linhas > l)
					++paginas, linhas = 1;

				letras = x;

			}

		}

		printf("%d\n", paginas);

	}

}