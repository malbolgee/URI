/*
	@autor: Malbolge;
	@data: 15/01/2019;
	@nome: Procurando Subsequências;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZESTR 100

unsigned pos;
_Bool compare(char *string, char *sub);
char * contaSubstrings(char *string, char *sub);

void main ()
{

	char *ptr;
	unsigned cont, caso;
	char sub[MAXSIZESTR];
	char string[MAXSIZESTR];

	caso = 0;
	while (scanf("%s %s", sub, string) != EOF)
	{

		pos = cont = 0;
		ptr = contaSubstrings(string, sub);

		while (ptr != NULL)
			++cont, ptr = contaSubstrings(ptr + 1, sub);

		if (cont)
			printf("Caso #%d:\nQtd.Subsequencias: %d\nPos: %d\n\n", ++caso, cont, pos);
		else
			printf("Caso #%d:\nNao existe subsequencia\n\n", ++caso);

	}

}

_Bool compara(char *string, char *sub)
{

	unsigned i, j;

	i = j = 0;
	while (string[i] && sub[j])
	{

		if (string[i] != sub[j])
			return false;

		++i;
		++j;

	}

	return (sub[j] == '\0');

}

char* contaSubstrings(char *string, char *sub)
{

	unsigned i;

	i = 0;
	while (string[i])
	{

		if ((string[i] == *sub) && compara(&string[i], sub))
		{

			pos += i + 1;
			return &string[i];

		}

		++i;

	}

	return NULL;

}
