/*
	@autor: Malbolge;
	@data: 10/06/2019;
	@nome: Eachianos I;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char s1[200];

} string;

char palavra[10050];
string texto[10050];
string palavras[200];

#define true 1
#define false 0

int main(int argc, char **argv)
{

	char tmp[10050], *aux;
	unsigned n, i, j, k;

	scanf(" %[^\n]", tmp);
	scanf("%*c%u", &n);

	for (i = 0; i < n; ++i)
		scanf("%s", palavras[i].s1);

	i = 0;
	aux = strtok(tmp, " ");
	strcpy(texto[i++].s1, aux);

	do
	{

		aux = strtok(0, " ");
		if (aux)
			strcpy(texto[i++].s1, aux);

	} while (aux);

	for (k = 0; k < n; ++k)
	{

		unsigned tam = 0;
		_Bool flag = true;

		for (j = 0; j < i; ++j)
		{

			if (strcmp(texto[j].s1, palavras[k].s1) == 0)
				if (!flag)
					printf(" %u", tam);
				else
					printf("%u", tam), flag = false;

			tam += strlen(texto[j].s1) + 1;

		}

		if (flag)
			printf("-1\n");
		else
			printf("\n");

	}

	return 0;

}