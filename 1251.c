/*
	@autor: Malbolge;
	@data: 12/10/2018;
	@nome: Diga-me a Frequência;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

	char ascii;
	unsigned short frequencia;

} dados;

// Declaração de função;
void quickSortInterno(dados *caractere, int inicio, int fim);
void quickSort(dados *caractere, int tam);
void insertionSort(dados *caractere, unsigned short tam);

void main ()
{

	unsigned short i, j, k, z = 0;
	char texto[1001];
	short frequencia;
	bool foivisto[1001];
	dados caractere[1001];

	while (scanf(" %[^\n]", texto) != EOF)
	{
		k = 0;
		// Função memset preenche um bloco de memória com um conteúdo especificado
		// No parâmetro;
		memset(foivisto, false, sizeof(foivisto));
		for (i = 0; texto[i]; i++)
		{
			frequencia = 0;
			// Se o caractere na posição atual não foi visto, prossegue para o
			// Próximo laço;
			if (!foivisto[i])
			{

				for (j = 0; texto[j]; j++)
				{

					if (texto[i] == texto[j])
					{
						// Se o caractere na posição 'j' é igual ao caractere
						// Na posição 'i', variável frequência incrementa
						// E sua posição é marcada como já verificada, para evitar
						// Repetições;
						foivisto[j] = true;
						frequencia++;
					}

				}

				// Escreve o caractere e a sua frequência em seus
				// Respectivos campos na Struct;
				caractere[k].ascii = texto[i];
				caractere[k].frequencia = frequencia;
				k++;
			}
		}

		// Ordena primeiro por caractere, depois por frequência;
		quickSort(caractere, k);
		insertionSort(caractere, k);

		// Tratamento da quebra de linha no último caso;
		if (z)
			printf("\n");
		else
			z++;

		// Impressão dos resultados;
		for (i = 0; i < k; i++)
			printf("%hhd %hu\n", caractere[i].ascii, caractere[i].frequencia);

	}
}

// Função para ordenação;
void quickSortInterno(dados *caractere, int inicio, int fim)
{

	dados pivo;
	dados temp;
	int i, j;

	if (fim - inicio > 0)
	{
		if (inicio < fim)
		{
			i = inicio;
			j = fim;
			pivo = caractere[(i + j) / 2];

			do
			{

				while (caractere[i].ascii > pivo.ascii)
					i++;
				while (caractere[j].ascii < pivo.ascii)
					j--;

				if (i <= j)
				{

					temp = caractere[i];
					caractere[i] = caractere[j];
					caractere[j] = temp;
					i++; j--;

				}

			} while (i <= j);

			quickSortInterno(caractere, inicio, j);
			quickSortInterno(caractere, i, fim);
		}
	}
}

// Função que dispara a chamada recursiva;
void quickSort(dados *caractere, int tam)
{

	quickSortInterno(caractere, 0, tam - 1);

}

// Função para ordenação;
void insertionSort(dados *caractere, unsigned short tam)
{

	short i = 1, j;
	dados pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = caractere[i];

		while (j >= 0 && caractere[j].frequencia > pivo.frequencia)
		{

			caractere[j + 1] = caractere[j];
			j--;

		}

		caractere[j + 1] = pivo;
		i++;

	}

}
