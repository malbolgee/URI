/*
	@autor: Malbolge;
	@data: 28/01/2019;
	@nome: Estágio;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define MAX 1100

typedef struct aluno{

	unsigned short id;
	char media;

} aluno;

aluno turma[MAX];

void main ()
{

	unsigned short i, melhor;
	unsigned short qtsAlunos, caso;

	while (scanf("%hu", &qtsAlunos), qtsAlunos)
	{

		for (i = 0; i < qtsAlunos; ++i)
			scanf("%hu %hhd", &turma[i].id, &turma[i].media);

		melhor = 0;
		for (i = 1; i < qtsAlunos; ++i)
			if (turma[i].media > turma[melhor].media)
				melhor = i;

		printf("Turma %hu\n", ++caso);
		for (i = 0; i < qtsAlunos; ++i)
			if (turma[i].media == turma[melhor].media)
				printf("%hu ", turma[i].id);

		printf("\n\n");

	}

}
