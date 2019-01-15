/*
	@autor: Malbolge;
	@data: 14/01/2019;
	@nome: Jogo de Boca;
*/

#include <stdio.h>

int boca(char *);

void main ()
{

	char string[150];

	scanf("%s", string);

	printf("%d\n", boca(string));

}

int boca(char *str)
{

	int retorno = 0;
	unsigned short i;

	for (i = 0; str[i]; ++i)
		retorno = ((retorno * 10) + (str[i] - '0')) % 3;

	return retorno;

}
