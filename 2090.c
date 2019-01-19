/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Fui ao Mercado e Comprei...;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

typedef struct string{

	char produto[30];

} string;

void main ()
{

	unsigned i, j;
	unsigned n, k, tmp;
	string shepa[MAXSIZE];

	while (true)
	{


		scanf("%u %u", &n, &k);

		if (!n)
			break;

		for (i = 0; i < n; ++i)
			scanf("%s", shepa[i].produto);

		tmp = 1;
		for (i = 0; i < n; ++i)
			for (j = 0; j <= i; ++j)
			{
				if (tmp == k)
				{

					printf("%s\n", shepa[j].produto);
					// Colocar uma flag pra sair do for mais externo
					// Deixa o código lento;
					goto end;

				}

				++tmp;

			}

		end: ;

	}

}
