/*
	@autor: Malbolge;
	@data: 05/12/2018;
	@nome: Quem Vai Ser Reprovado?;
*/

#include <stdio.h>
#include <string.h>

typedef struct aluno{

	char nome[30];
	unsigned short qtsProblemasResolvidos;

} aluno;

int compara(const void *a, const void *b);

void main ()
{

	unsigned short i;
	unsigned short qtsAlunos;
	unsigned short qtsInstnacia = 0;

	while (scanf("%hu", &qtsAlunos) != EOF)
	{

		aluno classe[qtsAlunos];
		memset(classe, 0, sizeof(aluno));

		for (i = 0; i < qtsAlunos; i++)
			scanf("%s %hu", classe[i].nome, &classe[i].qtsProblemasResolvidos);

		qsort(classe, qtsAlunos, sizeof(aluno), compara);

		printf("Instancia %hu\n", ++qtsInstnacia);

		printf("%s\n\n", classe[qtsAlunos - 1].nome);


	}

}

int compara (const void *a, const void *b)
{


	if ((*(struct aluno*)a).qtsProblemasResolvidos == (*(struct aluno*)b).qtsProblemasResolvidos)
	{

		if (strcmp((*(struct aluno*)a).nome, (*(struct aluno*)b).nome) == 0)
			return 0;
		else if (strcmp((*(struct aluno*)a).nome, (*(struct aluno*)b).nome) < 0)
			return -1;
		else
			return 1;

	}
	else if ((*(struct aluno*)a).qtsProblemasResolvidos > (*(struct aluno*)b).qtsProblemasResolvidos)
		return -1;
	else
		return 1;


}
