/*
	@autor: Malbolge;
	@data: 30/10/2018;
	@nome: Leitura Ótica;
*/

#include <stdio.h>
#include <stdbool.h>

char alternativaPrint(unsigned short);

void main ()
{

	unsigned char alternativas[6];
	unsigned short numQuestoes, i;
	unsigned short contador, posicao;
	bool unica;

	while (true)
	{

		scanf("%hu", &numQuestoes);

		if (numQuestoes == 0)
			break;

		while (numQuestoes--)
		{

			for (i = 0; i < 5; i++)
				scanf("%hhd", &alternativas[i]);

			unica = true;
			contador = 0;
			for (i = 0; i < 5; i++)
				if (alternativas[i] <= 127)
				{
					contador++;
					if (contador == 1 && unica == true)
					{
						unica = false;
						posicao = i;
					}

				}

			if (!contador)
				printf("*\n");
			else if (contador == 1)
				printf("%c\n", alternativaPrint(posicao));
			else
				printf("*\n");

		}
	}
}

char alternativaPrint(unsigned short posicao)
{

	switch (posicao) {
		case 0:
			return 'A';
		case 1:
			return 'B';
		case 2:
			return 'C';
		case 3:
			return 'D';
		case 4:
			return 'E';
	}

}
