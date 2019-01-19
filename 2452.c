/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Semente;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAXSIZE 100100

typedef struct tipoNo{

	int numero;
	struct tipoNo *proximo;

}tipoNo;

typedef struct tipoFila{

	tipoNo *primeiro;
	tipoNo *ultimo;

} tipoFila;

void queue(tipoFila *);
_Bool empty(tipoFila *);
void push(tipoFila *, int );
_Bool pop(tipoFila *, int *);

void main ()
{

	tipoFila fila;
	_Bool flag = false;
	int k, i, x, res, dias;
	unsigned comprimento, numGotas;

	queue(&fila);
	int vetor[MAXSIZE];

	scanf("%d %d", &comprimento, &numGotas);

	for (i = 0; i < numGotas; ++i)
		scanf("%d", &x), push(&fila, x);

	for (i = 1; i <= comprimento; ++i)
		vetor[i] = 0;

	x = k = 0;
	res = dias = 0;
	while (!empty(&fila))
	{

		pop(&fila, &x);
		++res;

		vetor[x] = 1;
		if (vetor[x - 1] == 0 && x - 1 > 0)
			push(&fila, x - 1), ++k, vetor[x - 1] = 1;
		if (vetor[x + 1] == 0 && x + 1 <= comprimento)
			push(&fila, x + 1), ++k, vetor[x + 1] = 1;

		if (res == numGotas)
		{

			numGotas = k;
			k = 0;
			if (flag)
				++dias;

			res = 0;
			flag = true;

		}

	}

	printf("%d\n", dias);

}

void queue(tipoFila *fila)
{

	fila->primeiro = NULL;
	fila->ultimo = NULL;

}

void push(tipoFila *fila, int numero)
{

	tipoNo *auxiliar;

	auxiliar = (tipoNo *) malloc(sizeof(tipoNo));

	if (!auxiliar)
		exit(1);

	if (fila->primeiro)
	{

		fila->ultimo->proximo = auxiliar;
		auxiliar->proximo = NULL;

	}
	else
		fila->primeiro = auxiliar;

	fila->ultimo = auxiliar;
	auxiliar->numero = numero;

}

_Bool pop(tipoFila *fila, int *retorno)
{

	tipoNo *auxiliar;

	if (fila->primeiro)
	{

		if (fila->primeiro->proximo)
		{

			*retorno = fila->primeiro->numero;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->primeiro->proximo;
			free(auxiliar);
			return true;

		}
		else
		{

			*retorno = fila->primeiro->numero;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->ultimo = NULL;
			free(auxiliar);
			return true;

		}

	}
	else
		return false;

}

_Bool empty(tipoFila *fila)
{

	return (fila->primeiro == NULL);

}
