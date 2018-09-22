/*
	@autor: Malbolge;
	@data: 22/09/2018;
	@nome: Papagaio Poliglota;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	char pergunta[10];

	while (scanf(" %[^\n]", pergunta) != EOF)
	{

		if (strcmp(pergunta, "esquerda") == 0)
			printf("ingles\n");
		else if (strcmp(pergunta, "direita") == 0)
			printf("frances\n");
		else if (strcmp(pergunta, "nenhuma") == 0)
			printf("portugues\n");
		else if (strcmp(pergunta, "as duas") == 0)
			printf("caiu\n");

	}

}