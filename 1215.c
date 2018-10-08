/*
	@autor: Malbolge;
	@data: 07/10/2018;
	@nome: Primeiro Dicionário de Andy;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{

	char palavras[201];

} string;

bool stringSrc(char *, string *, unsigned);
void ordenaAlpha(string *dicionario, unsigned tam);

int main ()
{

	unsigned i, j, k = 0;
	// Vetores para guardar temporariamente uma string;
	char tempEntrada[201], tempSaida[201];
	// Vetor onde irão ficar as palavras do dicionário;
	string dicionario[5000];

	memset(dicionario, 0, sizeof(dicionario));
	while (scanf(" %[^\n]", tempEntrada) != EOF)
	{
		i = j = 0;
		while (tempEntrada[i])
		{
			// Enquanto o caractere na posição atual da string for uma letra;
			// O passe para a string temporaria de saída já em minúsculo;
			while (isalpha(tempEntrada[i]))
			{
				tempSaida[j++] = tolower(tempEntrada[i++]);
				// printf("Valor de tempSaida caractere: %c\n", tempSaida[j-1]);
			}

			if (tempEntrada[i] == '\0')
			{
				tempSaida[j] = '\0';
				if (!stringSrc(tempSaida, dicionario, k))
					strcpy(dicionario[k++].palavras, tempSaida);

				j = 0;
				memset(tempSaida, 0, sizeof(tempSaida));

				break;

			}

			tempSaida[j] = '\0';

			// printf("Valor de tempSaida: %s\n", tempSaida);
			// Enquanto o caractere atual não for uma letra, apenas avançe;
			while (!isalpha(tempEntrada[i]))
			{
				i++;
				// Caso o caractere na posição atual seja o caractere nulo;
				// Significa que a string acabou, pare o laço;
				if (tempEntrada[i] == '\0')
					break;
			}

			// Se a palavra contida na string temporária ainda não existe
			// No struct das strings de saída, então a coloque lá;
			if (!stringSrc(tempSaida, dicionario, k))
				strcpy(dicionario[k++].palavras, tempSaida);

			j = 0;
			memset(tempSaida, 0, sizeof(tempSaida));

		}

		memset(tempEntrada, 0, sizeof(tempEntrada));
	}

	ordenaAlpha(dicionario, k);

	j = 0;

	if (strcmp(dicionario[0].palavras,"\0") == 0)
		j = 1;

	for (; j < k; j++)
		printf("%s\n", dicionario[j].palavras);

}

bool stringSrc(char *str, string *dicionario, unsigned tam)
{

	unsigned i;

	for (i = 0; i < tam; i++)
		if (strcmp(dicionario[i].palavras, str) == 0)
			return true;

	return false;

}

void ordenaAlpha(string *dicionario, unsigned tam)
{

	short i = 1, j;
	string pivo;

	while (i < tam)
	{
		j = i - 1;
		pivo = dicionario[i];

		while (j >= 0 && strcmp(dicionario[j].palavras, pivo.palavras) > 0)
		{

			dicionario[j + 1] = dicionario[j];
			j--;

		}

		dicionario[j + 1] = pivo;
		i++;

	}
}
