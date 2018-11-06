/*
	@autor: Malbolge;
	@data: 06/11/2018;
	@nome: Pontos de Feno;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	char cargo[20];
	unsigned comissao;

} funcao;

typedef struct{

	char palavra[300];

} string;

bool procuraPalavra(funcao *, char *, unsigned short);
unsigned short posicao;

void main ()
{

	unsigned short numPalavras, qtsCargos;
	unsigned short i, j;
	char texto[10000], *palavraTmp, ponto;
	string dicionario[10000];
	unsigned long qtsSalarioTotal;

	scanf("%hu %hu", &numPalavras, &qtsCargos);


	funcao cargos[numPalavras];

	memset(cargos, 0, sizeof(cargos));
	for (i = 0; i < numPalavras; i++)
			scanf(" %s %u", cargos[i].cargo, &cargos[i].comissao);
	/*
	// Teste de preechimento;
	for (i = 0; i < numPalavras; i++)
			printf("%s %u\n", cargos[i].cargo, cargos[i].comissao);
	printf("\n");
	*/

	while (qtsCargos)
	{

			printf("TESTE000001\n");
			// Leitura do texto descritivo de funções;
			scanf(" %[^\n]", texto);

			printf("TESTE\n");
			printf("%s\n", texto);
			if (strcmp(texto, ".") != 0)
			{

				qtsCargos--;
				// printf("TESTE01\n");
				// printf("%s\n", texto);
				// scanf(" %c", &ponto);

				printf("TESTE01\n");
				i = 0;
				palavraTmp = strtok(texto, " ");
				strcpy(dicionario[i++].palavra, palavraTmp);

				// Separação da string em palavras individuais
				// Usando o caractere espaço como token;
				do
				{

					palavraTmp = strtok('\0', " ");

					if (palavraTmp)
						strcpy(dicionario[i++].palavra, palavraTmp);


				} while (palavraTmp);

				/*
				// Segundo teste de preenchimento;
				for (j = 0; j < i; j++)
						printf("%s\n", dicionario[j].palavra);

				printf("\n");
				*/

				// Laço itera sobre as structs dicionario e cargos e soma
				// Os valores para os quais existem descrição na string texto;
				qtsSalarioTotal = 0;
				for (j = 0; j < i; j++)
					if (procuraPalavra(cargos, dicionario[j].palavra, numPalavras))
						qtsSalarioTotal += cargos[posicao].comissao;

				// Impressão do resultado final;
				printf("%lu\n", qtsSalarioTotal);
		}

		printf("TESTE0001\n");
	}

}

// Função procura no vetor determinada palavra passada como parâmetro;
bool procuraPalavra(funcao *cargos, char *palavra, unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (strcmp(cargos[i].cargo, palavra) == 0)
		{	
			posicao = i;
			return true;
		}

	return false;

}