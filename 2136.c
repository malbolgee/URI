/*
	@autor: Malbolge;
	@data: 01/02/2019;
	@nome: Amigos do Habay;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXX 10100
#define INF 0x3f3f3f3f
#define MAX(a, b) a > b ? a : b
#define T printf("TESTE\n")

typedef struct noArv{

	char nome[50];
	struct noArv *direita;
	struct noArv *esquerda;

} noArv;

typedef struct string{

	char nome[50];

} string;

void show(noArv *);
int compara(char *, char *);
noArv *push(noArv *, char *);

void main ()
{

	noArv *arvore;
	string nao[MAXX];
	int maior, i, j;
	char nome[50], tmp[50], opcao[50];

	i = 0;
	maior = -INF;
	arvore = NULL;
	while (scanf("%s", nome), strcmp(nome, "FIM") != 0)
	{

		scanf("%s", opcao);
		if (strcmp(opcao, "YES") == 0)
		{

			int tam = strlen(nome);
			if (tam > maior)
				strcpy(tmp, nome), maior = tam;

			arvore = push(arvore, nome);

		}
		else
			strcpy(nao[i++].nome, nome);

	}

	qsort(nao, i, sizeof(string), compara);
	show(arvore);
	for (j = 0; j < i; ++j)
		printf("%s\n", nao[j].nome);

	printf("\nAmigo do Habay:\n%s\n", tmp);

}

noArv *push(noArv *arvore, char *nome)
{

	if (!arvore)
	{

		arvore = (noArv *) malloc(sizeof(noArv));
		strcpy(arvore->nome, nome);
		arvore->esquerda = arvore->direita = NULL;

	}
	else if (strcmp(arvore->nome, nome) > 0)
		arvore->esquerda = push(arvore->esquerda, nome);
	else if (strcmp(arvore->nome, nome) < 0)
		arvore->direita = push(arvore->direita, nome);

	return arvore;

}

void show(noArv *arvore)
{

	if (arvore)
	{

		show(arvore->esquerda);
		printf("%s\n", arvore->nome);
		show(arvore->direita);

	}

}

int compara(char *a, char *b)
{


	int cmp = strcmp(a, b);
	if (cmp == 0)
		return 0;
	else if (cmp > 0)
		return 1;
	else
		return -1;

}
