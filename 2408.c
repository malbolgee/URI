/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Vice-Campeão;
*/

#include <stdio.h>

void ordena(short *);

void main ()
{

	unsigned short competidorA, competidorB, competidorC;
	short pontuacao[3], i;

	for (i = 0; i < 3; i++)
		scanf("%hd", &pontuacao[i]);

	ordena(pontuacao);

	printf("%hd\n", pontuacao[1]);

}

void ordena(short *vetor)
{

	short i = 1, j;
	short pivo;

	while (i < 3)
	{

		j = i - 1;
		pivo = vetor[i];

		while (j >= 0 && vetor[j] < pivo)
		{

			vetor[j + 1] = vetor[j];
			j--;

		}
		vetor[j + 1] = pivo;
		i++;

	}

}
