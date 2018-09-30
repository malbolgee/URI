/*
	@autor: Malbolge;
	@data: 29/09/2018;
	@nome: Zerinho ou Um;
*/

#include <stdio.h>

void main ()
{

	short numeros[3], posicao;
	unsigned short i, j, diferencas;

	while (scanf("%hu %hu %hu", &numeros[0], &numeros[1], &numeros[2]) != EOF)
	{
		posicao = -1;
		for (i = 0; i < 3; i++)
		{	
			// Se um número tiver duas diferenças, esse número é único;
			// Não há como dois números diferentes possuirem duas diferenças;
			diferencas = 0;
			for (j = 0; j < 3; j++)
				if (numeros[i] != numeros[j])
					diferencas++;
			
			if (diferencas == 2)
				posicao = i;
		}

		// Verifica em que posição está o número para dar a responta adequada;
		if (posicao == 0)
			printf("A\n");
		else if (posicao == 1)
			printf("B\n");
		else if (posicao == 2)
			printf("C\n");
		else
			printf("*\n");
	}
	
}