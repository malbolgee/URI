/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: A Última Criança Boa;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char nome[100];

} lista;

void ordena(lista *, unsigned short);

void main ()
{

	lista criancas[1100];
	unsigned short i, j;

	i = 0;
	while (scanf(" %[^\n]", criancas[i].nome) != EOF)
		i++;

	ordena(criancas, i);

	printf("%s\n", criancas[i - 1].nome);

}

void ordena(lista *criancas, unsigned short tam)
{

	short i = 1, j;
	lista pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = criancas[i];

		while (j >= 0 && strcasecmp(criancas[j].nome, pivo.nome) > 0)
		{

			criancas[j + 1] = criancas[j];
			j--;

		}

		criancas[j + 1] = pivo;
		i++;

	}

}
