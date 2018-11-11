/*
	@autor: Malbolge;
	@data: 09/11/2018;
	@nome: O Fantástico Jaspion;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct palavra{

	char japones[500];
	char portugues[500];

} palavra;

bool busca(palavra *, char *, unsigned short);
int compara(const void *a, const void *b);
unsigned posicao;

void main ()
{

	unsigned short i;
	unsigned numPalavras;
	short numLinhas, casos, espacos;
	char frase[500] = { 0 }, *palavraTmp;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%u %hu", &numPalavras, &numLinhas);

		palavra dicionario[numPalavras];

		for (i = 0; i < numPalavras; i++)
		{

			scanf(" %[^\n]", dicionario[i].japones);
			scanf(" %[^\n]", dicionario[i].portugues);

		}

		qsort(dicionario, numPalavras, sizeof(palavra), compara);

		while (numLinhas--)
		{

			scanf(" %[^\n]", frase);

			// Se a a frase for fazia, apenas imprima uma quebra de linha;
			if (!strlen(frase))
				printf("\n");
			else
			{

				// Separa a frase em palavras;
				palavraTmp = strtok(frase, " ");

				// Busca a palavra no dicionário, se existir, imprime sua tradução;
				// Se não, imprime a própria palavra;
				if (busca(dicionario, palavraTmp, numPalavras))
					printf("%s", dicionario[posicao].portugues);
				else
					printf("%s", palavraTmp);

				do
				{

					palavraTmp = strtok('\0', " ");

					if (palavraTmp)
						printf(" ");

					if (palavraTmp)
						if (busca(dicionario, palavraTmp, numPalavras))
							printf("%s", dicionario[posicao].portugues);
						else
							printf("%s", palavraTmp);

				} while (palavraTmp);

			}

			printf("\n");
			memset(frase, 0, sizeof(frase));

		}

		printf("\n");

	}

}

// Função implementa busca binária para procura no dicionario;
bool busca(palavra *dicionario, char *palavra, unsigned short tam)
{

	short inicio, fim, meio;
	inicio = 0;
	fim = tam - 1;

	while(inicio <= fim)

	{
		meio = (inicio + fim) / 2;
		if (strcmp(dicionario[meio].japones, palavra) < 0)
			inicio = meio + 1;
		else if(strcmp(dicionario[meio].japones, palavra) > 0)
			fim = meio-1;
		else
		{
			posicao = meio;
			return true;
		}

	}

	return false;
}

// Função de comparação para o qSort do C;
int compara(const void *a, const void *b)
{

	if (strcmp((*(struct palavra*)a).japones, (*(struct palavra*)b).japones) == 0)
		return 0;
	else if ((strcmp((*(struct palavra*)a).japones, (*(struct palavra*)b).japones) > 0))
		return 1;
	else
		return -1;

}
