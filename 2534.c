/*
	@autor: Malbolge;
	@data: 24/10/218;
	@nome: Exame Geral;
*/

#include <stdio.h>

void ordena(unsigned short *vetor, unsigned short tam);

void main ()
{

	unsigned short numHabitantes, numConsultas, consulta, i;

	while (scanf("%hu %hu", &numHabitantes, &numConsultas) != EOF)
	{

		unsigned short notas[numHabitantes];

		for (i = 0; i < numHabitantes; i++)
			scanf("%hu", &notas[i]);

		ordena(notas, numHabitantes);

		while (numConsultas--)
		{

			scanf("%hu", &consulta);
			printf("%hd\n", notas[consulta - 1]);

		}

	}

}

void ordena(unsigned short *vetor, unsigned short tam)
{

	short i = 1, j;
	short pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = vetor[i];

		while (j >= 0 && vetor[j] < pivo)
		{

			vetor[j+1] = vetor[j];
			j--;

		}

		vetor[j+1] = pivo;
		i++;

	}

}
