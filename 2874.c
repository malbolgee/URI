/*
	@autor: Malbolge;
	@data: 14/10/2018;
	@nome: Frase Binária;
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

void convertStrToInt(char *binarioStr, short *binarioInt, unsigned short tam);
unsigned char calcBinario(short *binarioInt, unsigned short tam);

void main ()
{

	unsigned casos, tamanho;
	short binarioInt[10];
	char binarioStr[10];

	while (scanf("%u", &casos) != EOF)
	{

		while (casos--)
		{

			scanf(" %s", binarioStr);

			tamanho = strlen(binarioStr);

			convertStrToInt(binarioStr, binarioInt, tamanho);

			printf("%c", calcBinario(binarioInt, tamanho));

			memset(binarioStr, 0, sizeof(binarioStr));

		}

		printf("\n");

	}
}

// Função para converter um número binário em decimal;
unsigned char calcBinario(short *binarioInt, unsigned short tam)
{

	short i, j, soma = 0;

	// Laço converte um binario para decimal utilizando o sistema de
	// numeração posicional;
	// Se tem dúvidas de como funciona, veja esse link: https://bit.ly/2QM7uFF;
	for (i = tam - 1, j = 0; i >= 0; i--, j++)
		soma += (binarioInt[i] * pow(2, j));

	return soma;

}

// Função para converter cada caracter de uma string em um inteiro individual;
void convertStrToInt(char *binarioStr, short *binarioInt, unsigned short tam)
{

	unsigned short i;

	// Como a entrada é uma string, se faz necessário converter cada caractere
	// Para um inteiro, só assim é possível fazer as operações aritiméticas
	// Necessárias;
	for (i = 0; i < tam; i++)
		binarioInt[i] = (short)binarioStr[i] - 48;

}
