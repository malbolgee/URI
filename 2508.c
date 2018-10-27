/*
	@autor: Malbolge;
	@data: 27/10/2018;
	@nome: Guru da Sorte;
*/

#include <stdio.h>
#include <ctype.h>

unsigned short tabela(char);
unsigned short numBruto(const char *nome);
unsigned short numSorte(unsigned short numero);

void main ()
{

	unsigned short numeroSorte;
	char nome[110];

	while (scanf(" %[^\n]", nome) != EOF)
		printf("%hu\n", numSorte(numBruto(nome)));

}

// Função converte o caractere para um numero;
unsigned short tabela(char caractere)
{

	switch (caractere) {
		case 'A': case 'J': case 'S':
			return 1;
		case 'B': case 'K': case 'T':
			return 2;
		case 'C': case 'L': case 'U':
			return 3;
		case 'D': case 'M': case 'V':
			return 4;
		case 'E': case 'N': case 'W':
			return 5;
		case 'F': case 'O': case 'X':
			return 6;
		case 'G': case 'P': case 'Y':
			return 7;
		case 'H': case 'Q': case 'Z':
			return 8;
		case 'I': case 'R':
			return 9;
	}

}

// Função calcula a soma bruta do número gerado pela função 'tabela';
unsigned short numBruto(const char *nome)
{

	short soma = 0;

	while (*nome)
	{

		if (*nome == ' ')
			nome++;

		soma += tabela(toupper(*(nome++)));

	}

	return soma;

}

// Função calcula a soma dos digitos do número bruto gerado pela função 'numBruto';
unsigned short numSorte(unsigned short numero)
{

	short soma = 0;

	if (numero < 10)
		return numero;
	else
	{

		do
		{

			soma += numero % 10;
			numero /= 10;

		} while (numero > 9);
		soma += numero;
		return numSorte(soma);

	}

}
