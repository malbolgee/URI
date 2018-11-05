/*
	@autor: Malbolge;
	@data: 05/11/2018;
	@nome: Ajude Girafales;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	char nome[30];
	char assinaturaOriginal[30];

} aluno;

bool validaAssinatura(aluno *, char *, unsigned short, unsigned short );
unsigned short procuraAluno(aluno *, char *, unsigned short);

void main ()
{

	unsigned short qtsAlunos, qtsAlunosPresentes;
	unsigned short i, qtsAssinaturasFalsas;
	char nomeAluno[30], assinaturaAula[30];

	while (true)
	{

		scanf("%hu", &qtsAlunos);

		if (qtsAlunos == 0)
			break;

		aluno classe[qtsAlunos];

		for (i = 0; i < qtsAlunos; i++)
			scanf(" %s %s", classe[i].nome, classe[i].assinaturaOriginal);

		scanf("%hu", &qtsAlunosPresentes);

		qtsAssinaturasFalsas = 0;
		for (i = 0; i < qtsAlunosPresentes; i++)
		{

			scanf("%s %s", nomeAluno, assinaturaAula);

			if (!validaAssinatura(classe, assinaturaAula, procuraAluno(classe, nomeAluno, qtsAlunos), qtsAlunos))
				qtsAssinaturasFalsas++;

		}

		printf("%hu\n", qtsAssinaturasFalsas);

	}

}

// Função verifica a assinatura do aluno na posição passada como parâmetro;
// Essa posição é dada pela função procuraAluno(), implementada a partir da linha 74;
bool validaAssinatura(aluno *classe, char *assinaturaAula, unsigned short posicao, unsigned short tam)
{

	unsigned short i;
	unsigned short qtsDiferencas;

 	i = 0;
	qtsDiferencas = 0;

	while (classe[posicao].assinaturaOriginal[i])
	{

		if (classe[posicao].assinaturaOriginal[i] != assinaturaAula[i])
			qtsDiferencas++;;

		i++;
	}


	if (qtsDiferencas > 1)
		return false;
	else
		return true;

}

// Função retorna a posição do aluno no vetor;
unsigned short procuraAluno(aluno *classe, char *nome, unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (strcmp(classe[i].nome, nome) == 0)
			return i;

}
