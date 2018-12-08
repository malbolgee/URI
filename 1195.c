/*
	@autor: Malbolge;
	@data: 08/12/2018;
	@nome: Árvore Binária de Busca;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct noArv{

	int numero;
	struct noArv *esquerda;
	struct noArv *direita;

} noArv;

noArv* insere(noArv *, int);
void showPre(noArv *);
void showIn(noArv *);
void showPost(noArv *);
void erase(noArv *);

void main ()
{

	unsigned short i;
	int numero;

	unsigned short qtsNos;
	unsigned short qtsCasos, caso = 0;

	scanf("%hu", &qtsCasos);

	while (qtsCasos--)
	{

		noArv *arvore = NULL;
		scanf("%hu", &qtsNos);

		for (i = 0; i < qtsNos; i++)
		{

			scanf("%d", &numero);
			arvore = insere(arvore, numero);

		}

		printf("Case %hu:\n", ++caso);
		printf("Pre.:");
		showPre(arvore);
		printf("\n");
		printf("In..:");
		showIn(arvore);
		printf("\n");
		printf("Post:");
		showPost(arvore);
		printf("\n\n");
		erase(arvore);

	}
}

noArv* insere(noArv *arvore, int numero)
{

	if (!arvore)
	{

		arvore = (noArv *) malloc(sizeof(noArv));
		arvore->numero = numero;
		arvore->esquerda = arvore->direita = NULL;

	}
	else if (arvore->numero > numero)
		arvore->esquerda = insere(arvore->esquerda, numero);

	else
		arvore->direita = insere(arvore->direita, numero);

	return arvore;

}

void showPost(noArv *arvore)
{

	if (arvore)
	{

		showPost(arvore->esquerda);
		showPost(arvore->direita);
		printf(" %d", arvore->numero);

	}

}

void showPre(noArv *arvore)
{

	if (arvore)
	{

		printf(" %d", arvore->numero);
		showPre(arvore->esquerda);
		showPre(arvore->direita);

	}

}
void showIn(noArv *arvore)
{

	if (arvore)
	{

		showIn(arvore->esquerda);
		printf(" %d", arvore->numero);
		showIn(arvore->direita);

	}

}

void erase(noArv *arvore)
{

	if (arvore)
	{

		erase(arvore->esquerda);
		erase(arvore->direita);
		free(arvore);
		arvore = NULL;

	}

}
