/*
	@autor: Malbolge;
	@data: 27/10/2018;
	@nome: Ajude!;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool procuraQuestao(const char *idQuestoes, char questao);
unsigned short procuraQuestaoPosi(const char *idQuestoes, char questao);

void main ()
{

	unsigned short casos, i, tempoQuestao;
	unsigned short qtsTempoTotal, qtsCertas;
	char julgamento[15], questao;

	while (true)
	{

		scanf("%hu", &casos);

		if (casos == 0)
			break;

		i = 0; // 'i' será o índice do banco de questões;
		qtsCertas = 0; // Essa variável fará a contagem da quantidade de questões corretas;
		qtsTempoTotal = 0; // Essa variável acumulará a quantidade de tempo total das questões corretas;
		char idQuestoes[casos]; // Vetor que será o banco de questões;
		unsigned short qtsErros[casos]; // Vetor guardará a penalidade das questões incorretas;
		// memset preenche com 0 o bloco de memória, dessa forma
		// Todas as posições de ambos os vetores começam com 0;
		memset(qtsErros, 0, sizeof(qtsErros));
		memset(idQuestoes, 0, sizeof(idQuestoes));
		while (casos--)
		{

			scanf(" %c %hu %s", &questao, &tempoQuestao, julgamento);

			if (procuraQuestao(idQuestoes, questao))
				if (strcmp(julgamento, "correct") == 0)
				{
					qtsCertas++;
					qtsTempoTotal += tempoQuestao + qtsErros[procuraQuestaoPosi(idQuestoes, questao)];
					// Se a questão existe e está correta, apenas soma o tempo total da questão
					// Mais o tempo das eventuais penalidades que essa questão já teve ao tempo total;

				}
				else
				{
					qtsErros[procuraQuestaoPosi(idQuestoes, questao)] += 20;
					// Se a questão já existe, mas está incorreta, apenas some 20
					// Segundos no vetor de penalidades na posição dessa questão;

				}
			else
				if (strcmp(julgamento, "correct") == 0)
				{
					qtsCertas++;
					idQuestoes[i] = questao;
					qtsTempoTotal += tempoQuestao;
					// Se a questão não existe e está correta, adiciona essa questão
					// No banco, incrementa a quantidade de questões corretas e
					// Soma ao tempo total o tempo da questão;

					i++;
				}
				else
				{
					idQuestoes[i] = questao;
					qtsErros[i] += 20;
					// Se a questão não existe e está incorreta, adiciona a questão
					// No banco e soma 20 segundos no vetor de penalidades na posição da questão;

					i++;

				}

			memset(julgamento, 0, sizeof(julgamento));
		}

		if (qtsCertas == 0)
			printf("0 0\n");
		else
			printf("%hu %hu\n", qtsCertas, qtsTempoTotal);

	}

}

// Função verifica se uma questão existe no banco de questões;
bool procuraQuestao(const char *idQuestoes, char questao)
{

	while (*idQuestoes)
		if (*(idQuestoes++) == questao)
			return true;

	return false;
}

// Função procura a posição de uma questão existente no banco de questões;
unsigned short procuraQuestaoPosi(const char *idQuestoes, char questao)
{

	unsigned short i = 0;

	while (idQuestoes[i])
	{
		if (idQuestoes[i] == questao)
			return i;

		i++;
	}

}
