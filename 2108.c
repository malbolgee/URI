#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main ()
{

	char texto[101], maiorPalavra[101], temp[101], lixo;
	short qtsCarac[101], maior;
	unsigned short caracteres, i, j, k;
	

	while (true)
	{

		scanf(" %[^\n]", texto);

		// printf("%s\n", texto);
		if (strcmp(texto, "0") == 0)
			break;

		i = 0;
		j = 0;
		k = 0;
		maior = 0;
		caracteres = 0;
		
		printf("caractere contino no índice 0 da string: %c\n", texto[0]);
		printf("caractere contino no índice 1 da string: %c\n", texto[1]);
		printf("%d\n", texto[1] == ' ');

		while (texto[i])
		{
			while (texto[i] != ' ' || texto[i] != '\0')
			{	
				printf("Valor atual de texto[%hu]: %c\n",i , texto[i]);
				temp[j++] = texto[i++];
				caracteres++;
				// printf("valor atual de i: %hu\n", i);
			}

			printf("TESTE\n");
			qtsCarac[k++] = caracteres;

			if (caracteres > maior)
			{
				maior = caracteres;
				strcpy(maiorPalavra, temp);
			}

			caracteres = 0;
			i++;
		}

	}

	printf("%s\n", maiorPalavra);
	printf("%hd\n", caracteres);

}