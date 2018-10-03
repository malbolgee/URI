/*
	@autor: Malbolge;
	@data: 03/10/2018;
	@nome: Justificador II;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{

	char palavra[51];

} string;

typedef struct{

	char saida[51];

} saida;


void main ()
{

	unsigned short casos, aux, tam, j, i, k;
	unsigned char posicao;

	while (true)
	{	
		scanf("%hu", &casos);

		if (casos == 0)
			break;

		aux = casos;
		string palavra[aux];
		saida textoSaida[aux];

		i = 0;
		while (casos--)
			scanf(" %[^\n]", palavra[i++].palavra);

		i = 0;
		j = 0;
		k = 0;
		tam = aux;
		while (aux--)
		{
			j = 0;
			k = 0;
			while (true)
			{

				if (palavra[i].palavra[j] == '\0')
					break;

				while (!isalpha(palavra[i].palavra[j]))	
					j++;

				while (isalpha(palavra[i].palavra[j]))
					textoSaida[i].saida[k++] = palavra[i].palavra[j++];

				if (palavra[i].palavra[j] != '\0')
					textoSaida[i].saida[k++] = ' ';

				printf("textoSaida[%hu].saida[%hu]: %c\n", i, k, textoSaida[i].saida[k]);
			}
				
				textoSaida[i].saida[k] = '\0';
				i++;
			/*
			j--;
			while (true)
			{
				
				palavra[i].palavra[posicao++] = palavra[i].palavra[j++];
				// printf("palavra[%hu].palavra[%hu]: %c\n", i, j, palavra[i].palavra[j]);

				if (palavra[i].palavra[j] == ' ' || palavra[i].palavra[j] == '\0')
					break;

				// printf("palavra[%hu].palavra[%hu]: %c\n", i, j, palavra[i].palavra[j]);
				// printf("valor atual de j: %hu\n", j);
			}


			// printf("Isso é o que tem na posicao: %c\n", palavra[i].palavra[posicao]);
			// printf("Isso é o que tem na posicao: %c\n", palavra[i].palavra[posicao - 1]);
			palavra[i].palavra[posicao] = '\0';
			*/
		}

		for (i = 0; i < k; i++)
			printf("%s\n", textoSaida[i].saida);
	}
}