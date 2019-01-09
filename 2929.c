/*
	@autor: Malbolge;
	@data: 09/01/2019;
	@nome: Menor da Pilha;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef struct tipoNo{

	long long numero;
	struct tipoNo *proximo;

} tipoNo;

typedef struct tipoPilha{

	tipoNo *topo;

} tipoPilha;


void pop(tipoPilha *pilha);
void criaPilha(tipoPilha *pilha);
long long menorDaPilha(tipoPilha *pilha);
void push(tipoPilha *pilha, long long numero);

void main ()
{

	tipoPilha pilha;
	char operacao[10];
	unsigned numOperacoes;
	long long numero, tmp;

	scanf("%u", &numOperacoes);

	criaPilha(&pilha);

	while (numOperacoes--)
	{

		scanf("%s", operacao);

		if (strcmp(operacao, "PUSH") == 0)
		{

			scanf("%lld", &numero);
			push(&pilha, numero);

		}
		else if (strcmp(operacao, "POP") == 0)
			pop(&pilha);
		else
		{

			tmp = menorDaPilha(&pilha);
			if (tmp == -1)
				printf("EMPTY\n");
			else
				printf("%lld\n", tmp);

		}

	}

}

void criaPilha(tipoPilha *pilha)
{

	pilha->topo = NULL;

}

void push(tipoPilha *pilha, long long numero)
{

	tipoNo *auxiliar;

	auxiliar = (tipoNo *) malloc(sizeof(tipoNo));

	if (!auxiliar)
		exit(1);

	auxiliar->proximo = pilha->topo;
	pilha->topo = auxiliar;
	auxiliar->numero = numero;

}

void pop(tipoPilha *pilha)
{

	tipoNo *auxiliar;
	auxiliar = pilha->topo;

	if (auxiliar)
	{

		pilha->topo = auxiliar->proximo;
		free(auxiliar);

	}
	else
		printf("EMPTY\n");

}

long long menorDaPilha(tipoPilha *pilha)
{

	tipoNo *auxiliar;
	auxiliar = pilha->topo;

	if (!auxiliar)
		return -1;

	long long menor = auxiliar->numero;

	while (auxiliar)
	{

		if (auxiliar->numero < menor)
			menor = auxiliar->numero;

		auxiliar = auxiliar->proximo;

	}

	return menor;

}
