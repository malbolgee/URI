/*
	@autor: Malbolge;
	@data: 24/09/2018;
	@nome: Perguntas mais Frequentes;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned short i, contador = 0;
	unsigned short numPerguntas, frequencia, k;
	unsigned short resposta = 0, j;


	while (true)
	{

		scanf("%hu %hu", &numPerguntas, &frequencia);

		if (numPerguntas == 0 && frequencia == 0)
			break;

		// Declaração de deois vetores
		// Um 'original' e um 'cópia';
		short perguntas[numPerguntas];
		short perguntasCpy[numPerguntas];

		// Aqui preencho o vetor original com os dados de entrada;
		for (i = 0; i < numPerguntas; i++)
			scanf("%hu", &perguntas[i]);

		// Aqui copio os dados do original para a cópia;
		for (i = 0; i < numPerguntas; i++)
			perguntasCpy[i] = perguntas[i];

		// Laço que itera no vetor original e na cópia;
		for (i = 0; i < numPerguntas; i++)
		{	
			contador = 0;
			for (j = 0; j < numPerguntas; j++)
			{	
				// Não há pergunta com identificador número 0;
				// Por isso, podemos, caso encontremos o mesmo identificador no vetor cópia, substituir esse id
				// Pelo 0. Isso evitará comparações futuras nas próximas iterações;
				if (perguntas[i] == perguntasCpy[j])
				{
					perguntasCpy[j] = 0;
					contador++;
				}

				// Se o 'contador' chegar à quantidade de frquência estabelecida na entrada;
				// Quer dizer que é preciso adicionar uma pergunta ao FAQ;
				// E, portanto, não é necessário verificar por mais aparições do mesmo id no vetor;
				// O laço 'for' interno trata as outras aparições do id a partir do 'j' até o fim do vetor;
				// Logo em seguida para o laço 'j' para que o laço 'i' incremente;
				if (contador == frequencia)
				{	
					resposta++;
					for (k = j + 1; k < numPerguntas; k++)
						if (perguntas[i] == perguntasCpy[k])
							perguntasCpy[k] = 0;

					break;
				}
				
			}

			// Grava 0 na própria posição que estava sendo comparada para evitar comparações futuras;
			perguntasCpy[i] = 0;

		}


		printf("%hu\n", resposta);
		resposta = 0;

	}
}