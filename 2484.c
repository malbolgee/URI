/*
	@autor: Malbolge;
	@data: 29/08/2018;
	@nome: Abracadabra;
*/


#include <stdio.h>
#include <string.h>

void main (void)
{

	char palavra[110];
	unsigned short i, j, tamanho, aux, k,m;

	while (scanf("%s", palavra) != EOF)
	{

		tamanho = strlen(palavra);
		aux = tamanho;
		k = tamanho;

		for (i = 0; i < tamanho; i++)
		{
			for(m = 0 ; m < i ; m++) printf(" ");
	
			for (j = 0; j < aux-1; j++)
				printf("%c ", palavra[j]);
			printf("%c\n",palavra[j]);

			aux = --k;
		}
		printf("\n");
	}
}