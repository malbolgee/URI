/*
	@autor: Malbolge;
	@data: 08/10/2018;
	@nome: Ordenação por Tamanho;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{

	char texto[3000];

} string;

void ordena(string *palavras, unsigned tam);

void main ()
{

	unsigned short casos;
	unsigned short i, j, k;

	scanf("%hu", &casos);

	// Vetor do tipo string onde ficarão as strings separadas do texto;
	string palavras[60];
	// String de entrada;
	char entrada[3000];


	while (casos--)
	{
		// Função memset preenche o bloco de memória com 0's para a próxima
		// Iteração, tratando possíveis lixos de memória da iteração
		// Passada;
		memset(palavras, 0, sizeof(palavras));
		memset(entrada, 0, sizeof(entrada));
		scanf(" %[^\n]", entrada);

		i = j = k = 0;
		while (true)
		{
			// Enquanto o caractere na posição atual for diferente de
			// Espaço, segue passando os caracteres da string de entrada
			// Para a struct de saída;
			// Se por um acaso, esse caractere na posição atual for um '\0'
			// Significa que a string acabou, então pare o laço;
			while (entrada[i] != ' ')
			{
				if (entrada[i] == '\0')
					break;
				else
					palavras[j].texto[k++] = entrada[i++];
			}

			// caractere nulo na posição atual para marcar o fim da string de saída;
			palavras[j].texto[k] = '\0';

			// Se o caractere na posição atual for o caractere nulo, pare o
			// laço mais externo;
			if (entrada[i] == '\0')
				break;

			// Se não, o código segue e os índices incrementam;
			i++; j++;
			k = 0;

		}

		j++;
		ordena(palavras, j);

		// Imprime as strings ordenadas por tamanho;
		for (i = 0; i < j; i++)
		{
			if (i != j && i != 0)
				printf(" ");
			printf("%s", palavras[i].texto);
		}
		printf("\n");

	}
}

// Insertion sorte para ordenar as strings dentro do Struct pelo tamanho;
void ordena(string *palavras, unsigned tam)
{

	short i = 1, j;
	string pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = palavras[i];

		while (j >= 0 && strlen(palavras[j].texto) < strlen(pivo.texto))
		{

			palavras[j + 1] = palavras[j];
			j--;

		}

		palavras[j + 1] = pivo;
		i++;

	}

}
