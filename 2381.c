/*
	@autor: Malbolge;
	@data: 24/11/2018;
	@nome: Lista de Chamada;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char nome[30];

} string;

void ordena(string *, unsigned short tam);

void main ()
{

	unsigned short i;
	unsigned short qtsAlunos, alunoPremiado;

	scanf("%hu %hu", &qtsAlunos, &alunoPremiado);
	string alunos[qtsAlunos];

	for (i = 0; i < qtsAlunos; i++)
		scanf("%s", alunos[i].nome);

	ordena(alunos, qtsAlunos);
	
	printf("%s\n", alunos[alunoPremiado - 1].nome);


}

void ordena(string *alunos, unsigned short tam)
{

	short i = 1, j;
	string pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = alunos[i];

		while (j >= 0 && strcmp(alunos[j].nome, pivo.nome) > 0)
		{

			alunos[j + 1] = alunos[j];
			j--;

		}

		alunos[j + 1] = pivo;
		i++;

	}

}
