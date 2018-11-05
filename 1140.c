/*
	@autor: Malbolge;
	@data: 04/11/2018;
	@nome: Flores Florescem da França;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct{

	char palavra[21];

} string;

bool isTautograma(string *, unsigned short tam);

void main ()
{

	unsigned short i;

	while (true)
	{

		char frase[2000] = { 0 }, *palavraTmp;
		string palavras[100];

		scanf(" %[^\n]", frase);

		if (strcmp(frase, "*") == 0)
			break;

		i = 0;
		palavraTmp = strtok(frase, " ");
		strcpy(palavras[i++].palavra, palavraTmp);

		do
		{

			palavraTmp = strtok('\0', " ");

			if (palavraTmp)
				strcpy(palavras[i++].palavra, palavraTmp);

		} while (palavraTmp);

		// Resultado final;
		if (isTautograma(palavras, i))
			printf("Y\n");
		else
			printf("N\n");

	}

}

bool isTautograma(string *palavras, unsigned short tam)
{

	unsigned short i;

	for (i = 1; i < tam; i++)
		if (tolower(palavras[i].palavra[0]) != tolower(palavras[i - 1].palavra[0]))
			return false;

	return true;

}
