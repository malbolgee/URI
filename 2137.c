/*
	@autor: Malbolge;
	@data: 01/09/2018;
	@nome: A Biblioteca do Senhor Severino;
*/

#include <stdio.h>

void ordena(short vet[], int);

void main (void)
{

	unsigned short casos, i;
	short id[1005], aux;
	char digitos = 0, j;

	while (scanf("%hu", &casos) != EOF)
	{
		for (i = 0;  i < casos; i++)
			scanf("%hd", &id[i]);

		//Função para ordenar os valores;
		ordena(id, casos);

		for (i = 0; i < casos; i++)
		{	
			digitos = 0;
			aux = id[i];

			//O número '0000' teria, na prática, 1 digito, então é melhor printá-lo de imediato;
			if (id[i] == 0)
				printf("0000\n");
			else
			{	
				//Laço para contar quantos digitos o número tem;
				while (aux > 0)
				{		

					aux = aux /10;
					digitos++;
				}

				//Se tiver 4 digitos, imprimie esse número diretamente;
				if (digitos == 4)
					printf("%d\n", id[i]);
				
				else
				{	
				
					j = 0;
					
					//Caso contrário, imprime (4 - digitos) 0's na frente do número;
					while (j < 4 - digitos)
					{
						
						printf("0");
						j++;
						
					}

					printf("%d\n", id[i]);
				}
			}
		}
	}
}

//InsertionSort;
void ordena(short vet[], int tam)
{

	short i = 1, j, pivot;

	while (i < tam)
	{
		pivot = vet[i];
		j = i - 1;

		while (j >= 0 && vet[j] > pivot)
		{

			vet[j + 1] = vet[j];
			j--;

		}

		vet[j + 1] = pivot;
		i++;
	}
}