/*
	@autor: Malbolge;
	@data: 23/10/2018;
	@nome: Adivinha;
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main ()
{

	unsigned short casos, i;
	unsigned short qtsAlunos, numeroSecreto;
	unsigned short alunoGanhador, maisProximo;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu %hu", &qtsAlunos, &numeroSecreto);
		// Declaração de um vetor com o tamanho da quantidade de alunos;
		// Ele irá guardar os palpites de números;
		short numerosTentativa[qtsAlunos];

		// Laço para encher o vetor;
		for (i = 0; i < qtsAlunos; i++)
			scanf("%hd", &numerosTentativa[i]);

		alunoGanhador = 0;
		// Variável 'maisProximo' recebe o valor absoluto da diferença do número
		// Secreto pelo valor do primeiro palpite
		// Por enquanto, esse é o palpite que mais se aproximou do número secreto;
		maisProximo = abs(numeroSecreto - numerosTentativa[0]);
		for (i = 1; i < qtsAlunos; i++)
		{
			// Se o valor absoluto da diferença entre o palpite atual e o número
			// Secreto for menor do que o palpite que é o atual mais próximo
			// Então esse palpite agora é o palpite mais próximo e a posição é guardada;
			if (abs(numeroSecreto - numerosTentativa[i]) < maisProximo)
			{

				maisProximo = abs(numeroSecreto - numerosTentativa[i]);
				alunoGanhador = i;

			}

		}

		printf("%hu\n", alunoGanhador + 1);

	}
}
