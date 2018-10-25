/*
	@autor: Malbolge;
	@data: 25/10/2018;
	@nome: A Única Chance;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool verificaOrdenacao(char *);

void main ()
{

	unsigned short casos, qtsLetras;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &qtsLetras);

		char alfabeto[qtsLetras + 1];

		scanf("%s", alfabeto);

		if (verificaOrdenacao(alfabeto))
			printf("There are the chance.\n");
		else
			printf("There aren't the chance.\n");
	}

}

bool verificaOrdenacao(char *alfabeto)
{

	unsigned short i, qtsMudancas;
	char comparacao[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	i = 0;
	qtsMudancas = 0;
	while (alfabeto[i])
	{
		// Se a letra na posição 'i' da string 'alfabeto' é diferente da letra
		// na mesma posição 'i' da string comparacao, então essa é uma letra que
		// não está onde deveria estar, seria preciso uma movimentaçõa para colocá-la
		// no lugar correto.
		if (alfabeto[i] != comparacao[i])
			qtsMudancas++;
		i++;

	}

	// Caso haja só uma letra que esteja fora de lugar, o contador irá contar duas vezes,
	// Pois irá char a letra fora de lugar e depois o lugar onde ela deveria estar
	// Que também tem uma letra errada;
	// No final das contas, se o contador contar 2 vezes, é porque tem uma letra
	// Fora de lugar, se for mais do que isso, tem mais letras fora de lugar;
	if (qtsMudancas > 2)
		return false;
	else
		return true;

}
