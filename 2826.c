/*
	@autor: Malbolge;
	@data: 04/09/2018;
	@nome: Léxico;
*/

#include <stdio.h>
#include <string.h>

void main (void)
{

	char palavra1[25], palavra2[25];
	unsigned short i, j, tamanho1, tamanho2;

	scanf("%s %s", palavra1, palavra2);

	if (strcmp(palavra1, palavra2) > 0)
	{	
		printf("%s\n", palavra2);
		printf("%s\n", palavra1);
	}
	else if (strcmp(palavra1, palavra2) < 0)
	{
		printf("%s\n", palavra1);
		printf("%s\n", palavra2);
	}
}