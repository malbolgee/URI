/*
	@autor: Malbolge;
	@data: 22/09/2018;
	@nome: Loteria;
*/

#include <stdio.h>

void main()
{

	short numJogador[6], numSorteados[6];
	unsigned short i, j, contador = 0;

	for (i = 0; i < 6; i++)
		scanf("%hu", &numJogador[i]);

	for (i = 0; i < 6; i++)
		scanf("%hu", &numSorteados[i]);

	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			if (numJogador[i] == numSorteados[j])
				contador++;

	if (contador == 3)
		printf("terno\n");
	else if (contador == 4)
		printf("quadra\n");
	else if (contador == 5)
		printf("quina\n");
	else if (contador == 6)
		printf("sena\n");
	else if (contador < 3)
		printf("azar\n");
}