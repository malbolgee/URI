/*
	@autor: Malbolge;
	@data: 12/11/2018;
	@nome:Presentes de Natal;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct presente{

	char nome[100];
	double preco;
	char preferencia;

} presente;

int compara(const void *a, const void *b);

void main ()
{

	unsigned short qtsPresentes;
	unsigned short i;
	char nome[100];

	while (scanf(" %s %hu", nome, &qtsPresentes) != EOF)
	{

		presente lista[qtsPresentes];

		memset(lista, 0, sizeof(lista));
		for (i = 0; i < qtsPresentes; i++)
		{

			scanf(" %[^\n]", lista[i].nome);
			scanf("%lf %hhd", &lista[i].preco, &lista[i].preferencia);

		}

		qsort(lista, qtsPresentes, sizeof(presente), compara);

		printf("Lista de %s\n", nome);
		for (i = 0; i < qtsPresentes; i++)
			printf("%s - R$%.2lf\n", lista[i].nome, lista[i].preco);

		printf("\n");
	}

}

int compara(const void *a, const void *b)
{

	if ((*(struct presente *)a).preferencia == (*(struct presente *)b).preferencia)
	{
		if ((*(struct presente *)a).preco == (*(struct presente *)b).preco)
		{
			if (strcmp((*(struct presente *)a).nome, (*(struct presente *)b).nome) == 0)
				return 0;
			else if (strcmp((*(struct presente *)a).nome, (*(struct presente *)b).nome) > 0)
				return 1;
			else
				return -1;

		}
		else if ((*(struct presente *)a).preco > (*(struct presente *)b).preco)
			return 1;
		else
			return -1;
	}
	else if ((*(struct presente *)a).preferencia < (*(struct presente *)b).preferencia)
		return 1;
	else
		return -1;

}
