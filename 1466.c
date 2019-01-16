/*
	@autor: Malbolge;
	@data: 16/01/2019;
	@nome: Percurso em Árvore por Nível;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct noArv{

	unsigned numero;
	struct noArv *direita;
	struct noArv *esquerda;

} noArv;

void bfs(noArv *);
noArv* push(noArv *, unsigned );

unsigned qtsNos;

void main ()
{

	unsigned i, num, qtsNum;
	unsigned qtsCasos, caso;

	scanf("%u", &qtsCasos);

	caso = 0;
	while (qtsCasos--)
	{

		scanf("%u", &qtsNum);

		qtsNos = 0;
		noArv *no = NULL;
		for (i = 0; i < qtsNum; ++i)
		{

			scanf("%u", &num);
			no = push(no, num);
			++qtsNos;

		}

		printf("Case %u:\n", ++caso);
		bfs(no);
		printf("\n\n");

	}

}

noArv* push(noArv *no, unsigned numero)
{

	if (!no)
	{

		no = (noArv *) malloc(sizeof(noArv));
		no->numero = numero;
		no->esquerda = no->direita = NULL;

	}
	else if (no->numero > numero)
		no->esquerda = push(no->esquerda, numero);
	else
		no->direita = push(no->direita, numero);

	return no;

}

void bfs(noArv *no)
{

	noArv *fila;
	unsigned i, f;
	_Bool flag = false;

	fila = (noArv *) malloc(qtsNos * sizeof(noArv));
	fila[0] = *no;
	i = 0; f = 1;

	while (f > i)
	{

		*no = fila[i++];
		if (!flag)
			printf("%u", no->numero), flag = true;
		else
			printf(" %u", no->numero);

		if (no->esquerda)
			fila[f++] = *no->esquerda;
		if (no->direita)
			fila[f++] = *no->direita;

	}

	free(fila);

}
