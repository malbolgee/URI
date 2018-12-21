/*
	@autor: Malbolge;
	@data: 21/12/2018;
	@nome: Mergulho;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main ()
{

	short i;
	short tmp;
	short qtsMergulhou, qtsRetornou;
	bool iguais = false;

	while (scanf("%hd %hd", &qtsMergulhou, &qtsRetornou) != EOF)
	{

		if (qtsMergulhou == qtsRetornou)
			iguais = true;

		if (iguais)
		{

			for (i = 0; i < qtsRetornou; i++)
				scanf("%hd", &tmp);

			printf("*\n");

		}
		else
		{

			short retornou[qtsMergulhou + 1];
			memset(retornou, 0, sizeof(retornou));

			for (i = 0; i < qtsRetornou; i++)
			{

				scanf("%hd", &tmp);
				retornou[tmp] = tmp;

			}

			for (i = 1; i <= qtsMergulhou; i++)
				if (retornou[i] == 0)
					printf("%hd ", i);

			printf("\n");

		}

		iguais = false;

	}

}
