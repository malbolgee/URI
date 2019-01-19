/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Expressões;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

typedef struct tipoNo{

	char caractere;
	struct tipoNo *proximo;

} tipoNo;

typedef struct tipoPilha{

	tipoNo *topo;

} tipoPilha;

void pop(tipoPilha *);
char top(tipoPilha *);
void stack(tipoPilha *);
_Bool empty(tipoPilha *);
void push(tipoPilha *, char );

void main ()
{

	int n;
	char lixo;
	unsigned i, caso;
	_Bool flag;
	char string[MAXSIZE];

	scanf("%d", &n);

	caso = 0;
	while (n--)
	{

		// memset(string, 0, sizeof(string));
		scanf("%s", string);

		// printf("%u) String: %s\n\n", ++caso, string);

		flag = true;
		tipoPilha pilha;
		stack(&pilha);

		for (i = 0; string[i]; ++i)
		{

			if (string[i] == '{' || string[i] == '[' || string[i] == '(')
				push(&pilha, string[i]);
			else
			{

				if (empty(&pilha))
				{

					flag = false;
					break;

				}

				// printf("%c\n", top(&pilha));

				if (string[i] == '}' && top(&pilha) == '{')
					pop(&pilha);
				else if (string[i] == ']' && top(&pilha) == '[')
					pop(&pilha);
				else if (string[i] == ')' && top(&pilha) == '(')
					pop(&pilha);
				else
				{

					flag = false;
					break;

				}

			}

		}

		if (!empty(&pilha))
			flag = false;

		printf("%s\n", flag ? "S" : "N");

	}

}

void stack(tipoPilha *pilha)
{

	pilha->topo = NULL;

}

void push(tipoPilha *pilha, char caractere)
{

	tipoNo *auxiliar;
	auxiliar = (tipoNo *) malloc(sizeof(tipoNo));

	if (!auxiliar)
		exit(1);

	auxiliar->proximo = pilha->topo;
	pilha->topo = auxiliar;
	auxiliar->caractere = caractere;

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

}

char top(tipoPilha* pilha)
{

	return pilha->topo->caractere;

}

_Bool empty(tipoPilha *pilha)
{

	return pilha->topo == NULL;

}
