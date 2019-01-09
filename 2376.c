/*
	@autor: Malbolge;
	@data: 09/01/2019;
	@nome: Copa do Mundo;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct tipoNo{

	char _time;
	struct tipoNo *proximo;

} tipoNo;

typedef struct tipoFila{

	tipoNo *primeiro;
	tipoNo *ultimo;

} tipoFila;

void queue(tipoFila *fila);
void push(tipoFila *fila, char _time);
_Bool pop(tipoFila *fila, char *retorno);

void main ()
{

	int a, b;
	tipoFila fila;
	char i, timeA, timeB, retorno;

	queue(&fila);

	for (i = 'A'; i <= 'P'; ++i)
		push(&fila, i);

	for (i = 0; i < 15; ++i)
	{

		pop(&fila, &retorno);
		timeA = retorno;
		pop(&fila, &retorno);
		timeB = retorno;

		scanf("%d %d", &a, &b);

		if (a > b)
			push(&fila, timeA);
		else
			push(&fila, timeB);

	}

	pop(&fila, &retorno);
	printf("%c\n", retorno);

}

void queue(tipoFila *fila)
{

	fila->primeiro = NULL;
	fila->ultimo = NULL;

}

void push(tipoFila *fila, char _time)
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
	auxiliar->_time = _time;

}

_Bool pop(tipoFila *fila, char *retorno)
{
	tipoNo *auxiliar;

	if (fila->primeiro)
	{

		if (fila->primeiro->proximo)
		{

			*retorno = fila->primeiro->_time;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->primeiro->proximo;
			free(auxiliar);
			return true;

		}
		else
		{

			*retorno = fila->primeiro->_time;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->ultimo = NULL;
			free(auxiliar);
			return true;

		}

	}
	else
	{

		retorno = NULL;
		return false;

	}

}
