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

		if (strcmp(texto, "0") == 0)
			break;

		i = 0;
		j = 0;
		k = 0;
		maior = 0;
		caracteres = 0;

		while (texto[i])
		{	

			while (true)
			{
				if (texto[i] == ' ' || texto[i] == '\0')
					break;

				temp[j++] = texto[i++];
				caracteres++;

			}

			temp[j] = '\0';
			
			qtsCarac[k++] = caracteres;

			for (int z = 0; z < k; z++)
				printf("Valor atual do vetor na posição %hu %hd\n", k, qtsCarac[z]);

			// printf("Esse é o valor de k: %d\n", k);

			if (caracteres > maior)
			{
				maior = caracteres;
				strcpy(maiorPalavra, temp);
			}

			caracteres = 0;
			i++;
			j = 0;

		}


		// printf("Valor atual de k: %hu\n", k);

		for (int l = 0; l < k; l++)
		{
			if (l != 0)
				printf("-");
			printf("%hd", qtsCarac[l]);
		}

		printf("\n");
		memset(qtsCarac, 0, sizeof(qtsCarac));
	}

	printf("The biggest word: %s\n", maiorPalavra);
}