/*
	@autor: Malbolge;
	@data: 01/01/2019;
	@nome: Encaixa ou Não II;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main ()
{


	unsigned short qtsCasos;
	short tamString1, tamString2;
	char string1[1100], string2[1100];

	scanf("%hu", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%s %s", string1, string2);

		tamString1 = strlen(string1);
		tamString2 = strlen(string2);

		if (tamString1 == tamString2)
			if (strcmp(string1, string2) == 0)
				printf("encaixa\n");
			else
				printf("nao encaixa\n");
		else if (tamString1 < tamString2)
			printf("nao encaixa\n");
		else if (strstr(&string1[tamString1 - tamString2 - 1], string2))
			printf("encaixa\n");
		else
			printf("nao encaixa\n");

	}

}
