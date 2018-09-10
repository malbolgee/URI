/*
	@autor: Malbolge;
	@data: 10/09/2018;
	@nome: Frase Completa;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main ()
{

	char frase[1100];
	unsigned short casos, qtsLetras = 0, i, j, tam, tam2;
	bool haletra = false;

	scanf("%hu", &casos);
	
	while (casos--)
	{
		char alfabeto[30] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0' };

		scanf(" %[^\n]", frase);

		tam = strlen(alfabeto);
		tam2 = strlen(frase);

		for (i = 0; i < tam2; i++)
		{

			for (j = 0; j < tam; j++)
				if (frase[i] == alfabeto[j])
				{
					haletra = true;
					alfabeto[j] = '1';
					break;
				}


			if (haletra)
				qtsLetras++;

			haletra = false;

		}

		if (qtsLetras == 26)
			printf("frase completa\n");
		else if (qtsLetras > 12 && qtsLetras < 26)
			printf("frase quase completa\n");
		else
			printf("frase mal elaborada\n");

		qtsLetras = 0;

		memset(frase, 0, sizeof(frase));
	}

}