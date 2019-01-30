/*
	@autor: Malbolge;
	@data: 30/01/2019;
	@nome: Acerte o Presente;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define SRC busca(arvore, nome, presente)

typedef struct presente{

	char string[30];

} presente;

typedef struct pessoa{

	char nome[30];
	presente presentes[3];

} pessoa;

typedef struct noArv{

	pessoa dado;
	struct noArv *esquerda;
	struct noArv *direita;

} noArv;

noArv* push(noArv *, pessoa);
_Bool busca(noArv *, char *, char *);

void main ()
{

	pessoa amigo;
	unsigned short i, j;
	unsigned short qtsAmigos;

	scanf("%hu", &qtsAmigos);

	noArv *arvore = NULL;
	for (i = 0; i < qtsAmigos; ++i)
	{
		scanf("%s", amigo.nome);
		for (j = 0; j < 3; ++j)
			scanf("%s", amigo.presentes[j].string);

		arvore = push(arvore, amigo);
	}

	char nome[30], presente[30];
	while (scanf("%s %s", nome, presente) != EOF)
		printf("%s\n", SRC ? "Uhul! Seu amigo secreto vai adorar o/" : "Tente Novamente!");

}

noArv* push(noArv *arvore, pessoa amigo)
{

	if (!arvore)
	{

		arvore = (noArv *) malloc(sizeof(noArv));
		arvore->dado = amigo;
		arvore->direita = arvore->esquerda = NULL;

	}
	else if (strcmp(arvore->dado.nome, amigo.nome) > 0)
		arvore->esquerda = push(arvore->esquerda, amigo);
	else
		arvore->direita = push(arvore->direita, amigo);

	return arvore;

}

_Bool busca(noArv *arvore, char *nome, char *presente)
{

	_Bool direita, esquerda;

	if (!arvore)
		return false;

	if (strcmp(arvore->dado.nome, nome) == 0)
		for (int i = 0; i < 3; ++i)
			if (strcmp(arvore->dado.presentes[i].string, presente) == 0)
				return true;

	if (strcmp(arvore->dado.nome, nome) > 0)
		esquerda = busca(arvore->esquerda, nome, presente);
	else
		direita = busca(arvore->direita, nome, presente);

}
