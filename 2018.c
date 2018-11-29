/*
	@autor: Malbolge;
	@data: 29/11/2018;
	@nome: Olimpíadas de Natal;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipoDado{

	char nome[50];
	unsigned short ouro;
	unsigned short prata;
	unsigned short bronze;

} tipoDado;

struct noArv{

	tipoDado dado;
	struct noArv *esquerdo;
	struct noArv *direito;

};

typedef struct noArv Arv;

Arv* insereOuro(Arv *a, tipoDado dado);
Arv* insereBronze(Arv *a, tipoDado dado);
Arv* inserePrata(Arv *a, tipoDado dado);
void treeToVector(Arv *a, tipoDado *vetor);
int compara(const void *a, const void *b);
unsigned short i = 0;

void main ()
{

	unsigned short j;
	char modalidade[300];
	Arv *a = NULL;

	while (scanf(" %[^\n]", modalidade) != EOF)
	{

		tipoDado pais = { 0 };
		scanf(" %[^\n]", pais.nome);
		a = insereOuro(a, pais);
		scanf(" %[^\n]", pais.nome);
		a = inserePrata(a, pais);
		scanf(" %[^\n]", pais.nome);
		a = insereBronze(a, pais);

	}

	tipoDado competidores[300] = { 0 };
	printf("Quadro de Medalhas\n");
	treeToVector(a, competidores);
	qsort(competidores, i, sizeof(tipoDado), compara);

	for (j = 0; j < i; j++)
		printf("%s %hu %hu %hu\n", competidores[j].nome, competidores[j].ouro, competidores[j].prata, competidores[j].bronze);

}

// Função passa todos os elementos da árvore para um vetor;
void treeToVector(Arv *a, tipoDado *vetor)
{

	if (a != NULL)
	{

		treeToVector(a->esquerdo, vetor);
		vetor[i++] = a->dado;
		treeToVector(a->direito, vetor);

	}

}

// Função insere um elemento na árvore e incrementa a quantidade de ouro;
Arv* insereOuro(Arv *a, tipoDado dado)
{

	if (!a)
	{

		a = (Arv *) malloc(sizeof(Arv));
		a->dado = dado;
		a->dado.ouro++;
		a->esquerdo = a->direito = NULL;

	}
	else if (strcmp(a->dado.nome, dado.nome) > 0)
		a->esquerdo = insereOuro(a->esquerdo, dado);
	else if (strcmp(a->dado.nome, dado.nome) < 0)
		a->direito = insereOuro(a->direito, dado);
	else
		a->dado.ouro++;

	return a;

}

// Função insere um elemento na árvore e incrementa a quantidade de prata;
Arv* inserePrata(Arv *a, tipoDado dado)
{


	if (!a)
	{

		a = (Arv *) malloc(sizeof(Arv));
		a->dado = dado;
		a->dado.prata++;
		a->esquerdo = a->direito = NULL;

	}
	else if (strcmp(a->dado.nome, dado.nome) > 0)
		a->esquerdo = inserePrata(a->esquerdo, dado);
	else if (strcmp(a->dado.nome, dado.nome) < 0)
		a->direito = inserePrata(a->direito, dado);
	else
		a->dado.prata++;

	return a;

}

// Função insere um elemento na árvore e incrementa a quantidade de bronze;
Arv* insereBronze(Arv *a, tipoDado dado)
{

	if (!a)
	{

		a = (Arv *) malloc(sizeof(Arv));
		a->dado = dado;
		a->dado.bronze++;
		a->esquerdo = a->direito = NULL;

	}
	else if (strcmp(a->dado.nome, dado.nome) > 0)
		a->esquerdo = insereBronze(a->esquerdo, dado);
	else if (strcmp(a->dado.nome, dado.nome) < 0)
		a->direito = insereBronze(a->direito, dado);
	else
		a->dado.bronze++;

	return a;

}

// Função de comparação para o qSort;
int compara(const void *a, const void *b)
{

	if ((*(struct tipoDado*)a).ouro == (*(struct tipoDado*)b).ouro)
	{
		if ((*(struct tipoDado*)a).prata == (*(struct tipoDado*)b).prata)
		{
			if ((*(struct tipoDado*)a).bronze == (*(struct tipoDado*)b).bronze)
			{
				if (strcmp((*(struct tipoDado*)a).nome, (*(struct tipoDado*)b).nome) == 0)
					return 0;
				else if ((strcmp((*(struct tipoDado*)a).nome, (*(struct tipoDado*)b).nome) > 0))
					return 1;
				else
					return -1;
			}
			else if ((*(struct tipoDado*)a).bronze > (*(struct tipoDado*)b).bronze)
				return -1;
			else
				return 1;
		}
		else if ((*(struct tipoDado*)a).prata > (*(struct tipoDado*)b).prata)
			return -1;
		else
			return 1;
	}
	else if ((*(struct tipoDado*)a).ouro > (*(struct tipoDado*)b).ouro)
		return -1;
	else
		return 1;
}
