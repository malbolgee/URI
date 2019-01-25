/*
	@autor: Malbolge;
	@data: 24/01/2019;
	@nome: Notas;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

typedef struct Notas{

	unsigned nota;
	unsigned posicao;

} Notas;

int compara(Notas *, Notas *);

void main ()
{

	unsigned i, n, tmp;
	Notas notas[MAXSIZE];

	scanf("%u", &n);
	memset(notas, 0, sizeof(notas));

	while (n--)
	{

		scanf("%u", &tmp);
		notas[tmp].nota++;
		notas[tmp].posicao = tmp;

	}

	qsort(notas, MAXSIZE, sizeof(Notas), compara);
	printf("%u\n", notas[0].posicao);

}

int compara(Notas *a, Notas *b)
{

	if (a->nota == b->nota)
	{

		if (a->posicao > b->posicao)
			return -1;
		else
			return 1;

	}
	else if (a->nota > b->nota)
		return -1;
	else
		return 1;

}
