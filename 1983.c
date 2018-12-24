/*
	@autor: Malbolge;
	@data: 23/12/2018;
	@nome: O Escolhido;
*/

#include <stdio.h>

typedef struct aluno{

	unsigned matricula;
	float nota;

} aluno;

void ordena(aluno *classe, unsigned short tam);

void main ()
{

	unsigned short i;
	unsigned short qtsAlunos;

	scanf("%hu", &qtsAlunos);
	aluno classe[qtsAlunos];

	for (i = 0; i < qtsAlunos; i++)
		scanf("%u %f", &classe[i].matricula, &classe[i].nota);

	ordena(classe, qtsAlunos);

	if (classe[0].nota < 8)
		printf("Minimum note not reached\n");
	else
		printf("%u\n", classe[0].matricula);

}

void ordena(aluno *classe, unsigned short tam)
{

	short i = 1, j;
	aluno pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = classe[i];

		while (j >= 0 && classe[j].nota < pivo.nota)
		{

			classe[j + 1] = classe[j];
			j--;

		}

		classe[j + 1] = pivo;
		i++;

	}

}
