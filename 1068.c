/*
	@autor: Malbolge;
	@data: 09/10/2018;
	@nome: Balanço de Parênteses I;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool verificaBalancoParenteses (char *);

void main ()
{

	char expressao[1100];

	while (scanf(" %s", expressao) != EOF)
	{

		if(verificaBalancoParenteses(expressao))
			printf("correct\n");
		else
			printf("incorrect\n");

	}

}

bool verificaBalancoParenteses(char *str)
{

	short qtsP = 0;

	// Se a expressão começar com uma parêntese que fecha
	// Já não esta balanceada;
	if (*str == ')')
		return false;

	// Enquanto a string não acabar ou o balanço for irrecuperável
	while ((*str) && (qtsP >= 0))
	{
		// Se achar um parentese que abre, incrementa variável;
		if (*str == '(')
			qtsP++;

		// Se achar um parentese que fecha, decrementa;
		if (*str == ')')
			qtsP --;

		str++;

		// Se por um acaso foram encontrados mais parênteses de fechamento do que
		// de abertura, a variável 'qtsP' irá para a próxima iteração negativa;
		// O que fará o laço while mais externo sair pois o balanço estará
		// Irrecuperrável;

	}

	if (qtsP == 0)
		return true;
	else
		return false;

}
