/*
	@autor: Malbolge;
	@data: 02/09/2018;
	@nome: Construindo Muralhas;
*/

#include <stdio.h>
#include <string.h>

void main (void)
{

	char titan[110];
	unsigned short qtdTitan, tamMuralha, i, alturaTitan, tamanho;

	scanf("%hu %hu", &qtdTitan, &tamMuralha);

	for (i = 0; i < qtdTitan; i++)
	{	
		//"%[a-z A-Z]" para ignorar números;
		scanf(" %[a-z A-Z] %hu", titan, &alturaTitan);
		tamanho = strlen(titan);

		if (tamMuralha < alturaTitan)
		{	
			// Escrever 0 na última posição da string para eliminar
			// o espaço que fica na impressão;
			titan[tamanho-1] = 0;
			printf("%s\n", titan);
		}
	}
}