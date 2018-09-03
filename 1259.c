/*
	@autor: Malbolge;
	@data: 02/09/2018;
	@nome: Pares e Ímpares;
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int vet[], unsigned inicio, unsigned meio, unsigned fim);
void mergeSort(int vet[], unsigned inicio, unsigned fim);

void main (void)
{

	int casos, numero, tamanhoPares = 0, tamanhoImpares = 0;
	int i = 0, j = 0;

	scanf("%u", &casos);
	int impares[casos], pares[casos];

	while (casos--)
	{
		scanf("%u", &numero);

		if (numero % 2 == 0)
		{	
			tamanhoPares++;
			pares[i++] = numero;
		}
		else
		{	
			tamanhoImpares++;
			impares[j++] = numero;
		}
	}

	mergeSort(pares, 0, tamanhoPares - 1);
	mergeSort(impares, 0, tamanhoImpares - 1);

	for (i = 0; i < tamanhoPares; i++)
		printf("%u\n", pares[i]);
	for (i = tamanhoImpares - 1; i > -1; i--)
		printf("%u\n", impares[i]);

	tamanhoImpares = 0;
	tamanhoPares = 0;

	j = 0;
	i = 0;

}

void mergeSort(int vet[], unsigned inicio, unsigned fim)
{

	unsigned meio;
	if (inicio < fim)
	{
		meio = ((inicio + fim)/2);
		mergeSort(vet, inicio, meio);
		mergeSort(vet, meio + 1, fim);
		merge(vet, inicio, meio, fim);
	}
}

void merge(int vet[], unsigned inicio, unsigned meio, unsigned fim)
{

	int *vetAux, p1, p2, tamanho, i ,j, k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim - inicio + 1;
	p1 = inicio;
	p2 = meio + 1;
	vetAux = (int *) malloc(tamanho*sizeof(int));

	if (vetAux != NULL)
	{

		for (i = 0; i < tamanho; i++)
		{

			if (!fim1 && !fim2)
			{
				if (vet[p1] <vet[p2])
					vetAux[i] = vet[p1++];
				else
					vetAux[i] = vet[p2++];

				if (p1 > meio)
					fim1 = 1;
				if (p2 > fim)
					fim2 = 1;
			}
			else
			{

				if (!fim1)
					vetAux[i] = vet[p1++];
				else
					vetAux[i] = vet[p2++];

			}
		}

		for (j = 0, k = inicio; j < tamanho; j++, k++)
			vet[k] = vetAux[j];

	}

	free(vetAux);
}