/*
	@autor: Malbolge;
	@data: 14/09/2018;
	@nome: Link Bolado;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool zelda(char *nome);

void main ()
{

	char nome[100001];
	int i, j, contador = 0;

	scanf("%s", nome);

	if (!zelda(nome))
		printf("Link Tranquilo\n");
	else
		printf("Link Bolado\n");

}

bool zelda(char *nome)
{

	unsigned contador = 0, i, j;
	char comparacao[6] = "zelda";

	for (i = 0, j = 0; nome[i]; i++)
	{
		if (nome[i] == comparacao[j] || nome[i] == comparacao[j] + 32 || nome[i] == comparacao[j] - 32)
		{
			j++;
			contador++;

			if (contador == 5)
				return true;
		}
		else
		{
			contador = 0;
			j = 0;
		}

	}

	return false;

}