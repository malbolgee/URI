/*
	@autor: Malbolge;
	@data: 20/01/2019;
	@nome: Infixa para Posfixa;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct tipoNo{

	char caractere;
	struct tipoNo *proximo;

} tipoNo;

typedef struct tipoPilha{

	tipoNo *topo;

} tipoPilha;

char top(tipoPilha *);
void pop(tipoPilha *);
void stack(tipoPilha *);
void infixaToPosfixa(char *);
void push(tipoPilha *, char );
int prioridade(char , char );

void main ()
{

	char expressao[400];
	unsigned short qtsCasos;

	scanf("%hu", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%s", expressao);
		infixaToPosfixa(expressao);

	}

}

void infixaToPosfixa(char *expressao)
{

	int i = 0;
	char c, t;
	tipoPilha pilha;
	stack(&pilha);
	push(&pilha, '(');

	do
	{

		c = expressao[i];
		++i;

		if (c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' || c >= 'a' && c <= 'z')
			printf("%c", c);
		else if (c == '(')
			push(&pilha, '(');
		else if (c == ')' || c == '\0')
		{

			do
			{

				t = top(&pilha);
				pop(&pilha);
				if (t != '(')
					printf("%c", t);

			} while (t != '(');

		}
		else if (c == '+' || c == '-' || c == '*' || c == '^' || c == '/')
		{

			while (true)
			{

				t = top(&pilha);
				pop(&pilha);
				if (prioridade(c, t))
				{

					push(&pilha, t), push(&pilha, c);
					break;

				}
				else
					printf("%c", t);
			}

		}

	} while (c != '\0');

	printf("\n");

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

char top(tipoPilha *pilha)
{

	return (pilha->topo->caractere);

}

int prioridade(char c, char t)
{

	int pc, pt;

	if (c == '^')
		pc = 3;
	else if (c == '*' || c == '/')
		pc = 2;
	else if (c == '+' || c == '-')
		pc = 1;
	else if (c == '(')
		pc = 4;

	if (t == '^')
		pt = 3;
	else if (t == '*' || t == '/')
		pt = 2;
	else if (t == '+' || t == '-')
		pt = 1;
	else if (t == '(')
		pt = 0;

	return (pc > pt);

}
