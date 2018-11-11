/*
	@autor: Malbolge;
	@data: 30/10/2018;
	@nome: Maiúsculas, Por Quê?;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct string{

	char palavra[25];

}string;

int compara(const void *a, const void *b);

void main ()
{

	unsigned short qtsPalavras;
	unsigned short i, j;

	scanf("%hu", &qtsPalavras);

	i = 0;
	string palavras[qtsPalavras];
	while (qtsPalavras--)
		scanf(" %s", palavras[i++].palavra);

	qsort(palavras, i, sizeof(string), compara);

	for (j = 0; j < i; j++)
		printf("%s\n", palavras[j].palavra);

}

int compara(const void *a, const void *b)
{

	if (strcasecmp((*(struct string*)a).palavra, (*(struct string*)b).palavra) == 0)
	{
		if ((strcmp((*(struct string*)a).palavra, (*(struct string*)b).palavra) > 0))
			return 1;
		else
			return -1;
	}
	else if (strcasecmp((*(struct string*)a).palavra, (*(struct string*)b).palavra) > 0)
		return 1;
	else
		return -1;

}
