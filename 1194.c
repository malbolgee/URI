/*
	@autor: Malbolge;
	@data: 15/01/2019;
	@nome: Prefixa, Infixa e Posfixa;
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

typedef struct noArv{

	char letra;
	struct noArv *direita;
	struct noArv *esquerda;

} noArv;

noArv* novoNo(char letra);
void showposfixa(noArv *arvore);
int src(char *str, int inicio, int fim, char letra);
noArv* tree(char *infixa, char *prefixa, int inInicio, int inFim);

short indice;

void main ()
{

	short qtsCasos;
	short qtsNodes, i;
	char prefixa[MAXSIZE], infixa[MAXSIZE];

	scanf("%hu", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%hu %s %s%*c", &qtsNodes, prefixa, infixa);
		indice = 0;
		noArv *raiz = tree(infixa, prefixa, 0, qtsNodes - 1);
		showposfixa(raiz);
		printf("\n");

	}

}

noArv* novoNo(char letra)
{

	noArv *no = (noArv *) malloc(sizeof(noArv));
	no->letra = letra;
	no->esquerda = no->direita = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char letra)
{

	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra)
			return i;

	return -1;

}

noArv* tree(char *infixa, char *prefixa, int inInicio, int inFim)
{

	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	noArv *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, no->letra);
	no->esquerda = tree(infixa, prefixa, inInicio, infixaIndice - 1);
	no->direita = tree(infixa, prefixa, infixaIndice + 1, inFim);

	return no;

}

void showposfixa(noArv *no)
{

	if (no == NULL)
		return;

	showposfixa(no->esquerda);
	showposfixa(no->direita);
	printf("%c", no->letra);

}
