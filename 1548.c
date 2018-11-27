/*
	@autor: Malbolge;
	@data: 26/11/2018;
	@nome: Fila do Recreio;
*/

#include <stdio.h>

void selection(short *, unsigned short);
int trocas;

void main ()
{

	unsigned short casos;
	unsigned short numAlunos;
	int i;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &numAlunos);

		short filaAntes[numAlunos];
		short filaDepois[numAlunos];

		for (i = 0; i < numAlunos; i++)
		{
			scanf("%hd", &filaAntes[i]);
			filaDepois[i] = filaAntes[i];
		}

		trocas = 0;
		selection(filaDepois, numAlunos);

		for (i = 0; i < numAlunos; i++)
			if (filaAntes[i] == filaDepois[i])
				trocas++;

		printf("%d\n", trocas);

	}

}

void selection(short *vetor, unsigned short tam)
{

	unsigned short i, j;
	short maior, temp;

	for (i = 0; i < tam - 1; i++)
	{

		maior = i;
		for (j = i + 1; j < tam; j++)
			if (vetor[j] > vetor[maior])
				maior = j;

		if (i != maior)
		{

			temp = vetor[i];
			vetor[i] = vetor[maior];
			vetor[maior] = temp;

		}

	}

}
