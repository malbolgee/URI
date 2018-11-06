/*
	@autor: Malbolge;
	@data: 05/11/2018;
	@nome: Aliteração;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{

	char palavra[60];

} string;


void main ()
{

	unsigned short i, j;
	string palavras[300];
	char texto[10000], *palavraTmp;

	while (scanf(" %[^\n]", texto) != EOF)
	{

		i = 0;
		palavraTmp = strtok(texto, " ");
		strcpy(palavras[i++].palavra, palavraTmp);

		do
		{

			palavraTmp = strtok('\0', " ");

			if (palavraTmp)
				strcpy(palavras[i++].palavra, palavraTmp);

		} while (palavraTmp);

	
		j = 1;
		unsigned short aliteracoes = 0;
		unsigned short contaLetras = 0;

		while (j < i)
		{

			while (tolower(palavras[j].palavra[0]) == tolower(palavras[j - 1].palavra[0]))
			{
				contaLetras += 2;
				j++;
			}

			j++;
			if (contaLetras >= 2)
				aliteracoes++;

			contaLetras = 0;

		}

		printf("%hu\n", aliteracoes);

	}

}
