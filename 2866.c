/*
	@autor: Malbolge;
	@data: 18/09/2018;
	@nome: Criptotexto;
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main ()
{

	char palavra[101], saida[101];
	unsigned short casos, i, j, tamanho;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s", palavra);

		tamanho = strlen(palavra);

		i = tamanho - 1;
		j = 0;

		// Leio a string de trás para frente
		// Visando pegar os caracteres na ordem certa
		// E colocá-los na string de saída;
		while (tamanho--)
		{
			// O padrão da questão são os caracteres minúsculos
			// Lidos de trás para frente, formam uma palavra;
			if (islower(palavra[i]))
				saida[j++] = palavra[i--];
			else
				i--;
		}

		saida[j] = '\0';
		printf("%s\n", saida);
	}
}
