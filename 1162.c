/*
	@autor: Malbolge;
	@data: 05/09/2018;
	@nome: Organizador de Vagões;
*/

#include <stdio.h>

unsigned ordena(int vet[], unsigned);

void main (void)
{

	unsigned casos, tamTrem;
	unsigned i;

	scanf("%u", &casos);

	while (casos--)
	{

		scanf("%u", &tamTrem);
		int vagoes[tamTrem];

		for (i = 0; i < tamTrem; i++)
			scanf("%d", &vagoes[i]);

		printf("Optimal train swapping takes %u swaps.\n", ordena(vagoes, tamTrem));

	}
}


unsigned ordena(int vet[], unsigned tam)
{

	unsigned i, j, contador = 0, aux;

	//A máquina só rotaciona 2 vagões por vez
	//Por isso, um ínico 'for' que compara 2 a 2 elementos e faz a troca
	//Enquanto o tamanho do vetor não chegar a 0;
	while (tam--)
	{

		for (i = 0, j = 1; i < tam; i++, j++)
			if (vet[i] > vet[j])
			{	
				contador++;
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
	}
	return contador;
}