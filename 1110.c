/*
	@autor: Malbolge;
	@data: 28/11/2018;
	@nome: Jogando Cartas Fora;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tipoNo{

	int numero;
	struct tipoNo *proximo;

} tipoNo;

typedef struct tipoPilha{

	tipoNo *topo;

} tipoPilha;

void pop(tipoPilha *pilha, int *descartes);
void push(tipoPilha *pilha, int numero);
void moveTopo(tipoPilha *pilha);
void stack(tipoPilha *pilha);
void erase(tipoPilha *pilha);
short qtsDescartes;

void main ()
{

	unsigned short carta;
	tipoPilha pilha;
 	short i;

	while (true)
	{

		scanf("%hu", &carta);

		if (carta == 0 || carta > 50)
			return;

		stack(&pilha);
		int descartes[carta];

		for (i = carta; i > 0; i--)
			push(&pilha, i);

		qtsDescartes = 0;
		pop(&pilha, descartes);

		printf("Discarded cards:");
		for (i = 0; i < qtsDescartes; i++)
		{

			printf(" %d", descartes[i]);
			if (i != qtsDescartes - 1)
				printf(",");

		}

		printf("\nRemaining card: %d\n", pilha.topo->numero);
		erase(&pilha);

	}

}

// Função cria uma pilha;
void stack(tipoPilha *pilha)
{

	pilha->topo = NULL;

}

// Função coloca elementos na pilha;
void push(tipoPilha *pilha, int carta)
{

	tipoNo *auxiliar;

	auxiliar = (tipoNo *) malloc(sizeof(tipoNo));

	if (!auxiliar)
		exit(1);

	auxiliar->proximo = pilha->topo;
	pilha->topo = auxiliar;
	auxiliar->numero = carta;

}

// Função retira elementos da pilha;
void pop(tipoPilha *pilha, int *descartes)
{

	tipoNo *auxiliar;

	if (auxiliar)
	{

		// Se houver apenas um elemento na pilha, não houve descartes;
		if (!pilha->topo->proximo)
			return;

		do
		{

			auxiliar = pilha->topo;
			descartes[qtsDescartes++] = auxiliar->numero;
			pilha->topo = pilha->topo->proximo;
			free(auxiliar);
			moveTopo(pilha);

		} while (pilha->topo->proximo);

	}

}

// Função move o topo atual para a base da pilha;
void moveTopo(tipoPilha *pilha)
{

	tipoNo *auxiliar, *base;

	base = pilha->topo;
	auxiliar = pilha->topo;

	if (base->proximo)
	{

		while (base->proximo)
			base = base->proximo;

		pilha->topo = pilha->topo->proximo;
		auxiliar->proximo = base->proximo;
		base->proximo = auxiliar;

	}
}

// Função apaga a pilha;
void erase(tipoPilha *pilha)
{

	tipoNo *auxiliar;

	auxiliar = pilha->topo;
	pilha->topo = NULL;
	free(auxiliar);

}
