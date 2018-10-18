/*
	@autor: Malbolge;
	@data: 17/10/2018;
	@nome: Contando Carneirinhos;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

void quickSort(long long *carneiros, unsigned tam);
void quickSortInterno(long long *carneiros, long inicio, long fim);

void main ()
{

	unsigned casos, i;
	unsigned qtsCarneiros;
	unsigned qtsVistos;

	scanf("%u", &casos);

	while (casos--)
	{

		scanf("%u", &qtsCarneiros);
		long long carneiros[qtsCarneiros];

		for (i = 0; i < qtsCarneiros; i++)
			scanf("%lld", &carneiros[i]);

		// Ordenar antes de ver quem não é repetido é bem menos custoso;
		quickSort(carneiros, qtsCarneiros);

		qtsVistos = 0;
		// Aqui se o elemento da próxima posição é diferente do elemento da posição
		// Atual, então quer dizer que não é um repetido, conta 1 nos carneiros
		// vistos;
		for (i = 0; i < qtsCarneiros; i++)
			if (carneiros[i + 1] != carneiros[i])
				qtsVistos++;

		printf("%u\n", qtsVistos);

	}

}

// QuickSort;
void quickSortInterno(long long *carneiros, long inicio, long fim)
{

	long long pivo;
 	long long temp;
	long int i, j;

	if (fim - inicio > 0)
	{

		i = inicio;
		j = fim;
		pivo = carneiros[(i + j) / 2];

		do
		{

			while (carneiros[i] < pivo)
				i++;
			while (carneiros[j] > pivo)
				j--;

			if (i <= j)
			{

				temp = carneiros[i];
				carneiros[i] = carneiros[j];
				carneiros[j] = temp;
				i++; j--;

			}

		} while (i <= j);

		quickSortInterno(carneiros, inicio, j);
		quickSortInterno(carneiros, i, fim);

	}
}

// Função que dispara a chamada recursiva;
void quickSort(long long *carneiros, unsigned tam)
{

	quickSortInterno(carneiros, 0, tam - 1);

}
