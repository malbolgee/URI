/*
	@autor: Malbolge;
	@data: 10/06/2019;
	@nome: Eachianos II;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char s1[200];

} string;

#define true 1
#define false 0

int main(int argc, char **argv)
{

	char palavra[200];
	string texto[200];
	char tmp[200], *aux;
	unsigned n, i, j, k;

	scanf("%u", &n);

	while (n--)
	{

		i = 0;
		scanf(" %[^\n]", tmp);
		scanf(" %s", palavra);

		aux = strtok(tmp, " ");
		strcpy(texto[i++].s1, aux);

		do
		{

			aux = strtok(0, " ");
			if (aux)
				strcpy(texto[i++].s1, aux);

		} while (aux);

		_Bool flag = true;
		unsigned tam = 0;
		for (j = 0; j < i; ++j)
		{

			if (strcmp(texto[j].s1, palavra) == 0)
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