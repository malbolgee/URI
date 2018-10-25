/*
	@autor: Malbolge;
	@data: 24/10/2018;
	@nome: Nova Senha RA;
*/

#include <stdio.h>
#include <ctype.h>

char autenticacao(char caractere);

void main ()
{

	unsigned short casos, i;
	char qtsDigitos, texto[1000];

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %[^\n]", texto);

		i = 0;
		qtsDigitos = 0;
		while (texto[i])
		{

			if (isalpha(texto[i]))
				if (qtsDigitos < 12)
				{
					printf("%hhd", autenticacao(texto[i]));
					qtsDigitos++;
				}
			i++;
		}

		printf("\n");
	}
}

char autenticacao(char caractere)
{

	switch (caractere) {
		case 'G': case 'Q': case 'a': case 'k': case 'u':
			return 0;
		case 'I': case 'S': case 'b': case 'l': case 'v':
			return 1;
		case 'E': case 'O': case 'Y': case 'c': case 'm': case 'w':
			return 2;
		case 'F': case 'P': case 'Z': case 'd': case 'n': case 'x':
			return 3;
		case 'J': case 'T': case 'e': case 'o': case 'y':
			return 4;
		case 'D': case 'N': case 'X': case 'f': case 'p': case 'z':
			return 5;
		case 'A': case 'K': case 'U': case 'g': case 'q':
			return 6;
		case 'C': case 'M': case 'W': case 'h': case 'r':
			return 7;
		case 'B': case 'L': case 'V': case 'i': case 's':
			return 8;
		case 'H': case 'R': case 'j': case 't':
			return 9;

	}

}
