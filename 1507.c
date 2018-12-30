/*
	@autor: Malbolge;
	@data: 29/12/2018;
	@nome: Subsequências;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubString(char *string1, char *string2);

void main ()
{

	unsigned short i, j;
	char string[100060];
	char subString[1100];
	unsigned short qtsCasos, qtsStrings;

	scanf("%hu", &qtsCasos);
	scanf("%s", string);

	for (i = 0; i < qtsCasos; ++i)
	{

		scanf("%hu", &qtsStrings);

		for (j = 0; j < qtsStrings; ++j)
		{

			scanf("%s", subString);

			if (isSubString(subString, string))
				printf("Yes\n");
			else
				printf("No\n");

		}

		scanf("%s", string);

	}

}

bool isSubString(char *string1, char *string2)
{

	unsigned short i, j;
	unsigned short tamString1, tamString2;

	tamString1 = strlen(string1);
	tamString2 = strlen(string2);

	for (i = 0, j = 0; i < tamString2 && j < tamString1; i++)
		if (string1[j] == string2[i])
			j++;

	// Se todos os caracteres do padrão existirem na string principal
	// Então o padrão é uma substring;
	if (j == tamString1)
		return true;
	else
		return false;

}
