/*
	@autor: Malbolge;
	@data: 01/10/2018;
	@nome: O Retorno do Rei;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	char numeroSrt[101];
	short numeroInt[101];
	unsigned short i, j;
	float media = 0;

	scanf("%s", numeroSrt);

	i = 0;
	j = 0;
	while (numeroSrt[i])
	{

		while (true)
		{	
			// Caso o caractere na posição atual seja um 0 ou seja o final da string
			// O laço para;
			if (numeroSrt[i] == '0' || numeroSrt[i] == '\0')
				break;

			// Converte um caractere para inteiro e o coloca num vetor de inteiro;
			numeroInt[j++] = (int)numeroSrt[i++] - 48;

		}

		// Só multiplica por 10 a posição anterior caso o caractere
		// Na posição atual seja um 0;
		// Essa multiplicação acontce porque se foi encontrado um 0 na posição
		// Atual, quer dizer que o número na posição anterior está na casa da dezena
		// Uma vez que não há numeros com 0's à esquerda na entrada;
		if (numeroSrt[i] == '0')
			numeroInt[--j] *= 10;

		// Só incrementa os índices se não for o final da string;
		if (numeroSrt[i] != '\0')
		{
			i++; 
			j++;
		}

	}

	// Cálculo da média;
	for (i = 0; i < j; i++)
		media += numeroInt[i];

	printf("%.2f\n", (media/j));

}
