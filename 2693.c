/*
	@autor: Malbolge;
	@data: 25/10/2018;
	@nome: Van;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char nomeAlunos[100];
	char regiao;
	unsigned short distancia;

} alunos;

void ordenaDistancia(alunos *, unsigned short tam);
void ordenaRegiao(alunos *, unsigned short tam);
void ordenaNome(alunos *, unsigned short tam);

void main ()
{

	unsigned short qtsAlunos, i;

	while (scanf("%hu", &qtsAlunos) != EOF)
	{

		alunos listaAlunos[qtsAlunos];

		for (i = 0; i < qtsAlunos; i++)
		{
			scanf("%s", listaAlunos[i].nomeAlunos);
			scanf(" %c", &listaAlunos[i].regiao);
			scanf("%hu", &listaAlunos[i].distancia);
		}

		ordenaNome(listaAlunos, qtsAlunos);
		ordenaRegiao(listaAlunos, qtsAlunos);
		ordenaDistancia(listaAlunos, qtsAlunos);
		
		for (i = 0; i < qtsAlunos; i++)
			printf("%s\n", listaAlunos[i].nomeAlunos);

	}

}

void ordenaDistancia(alunos *listaAlunos, unsigned short tam)
{

	short i = 1, j;
	alunos pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = listaAlunos[i];

		while (j >= 0 && listaAlunos[j].distancia > pivo.distancia)
		{

			listaAlunos[j + 1] = listaAlunos[j];
			j--;

		}

		listaAlunos[j + 1] = pivo;
		i++;

	}

}

void ordenaRegiao(alunos *listaAlunos, unsigned short tam)
{

	short i = 1, j;
	alunos pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = listaAlunos[i];

		while (j >= 0 && listaAlunos[j].regiao > pivo.regiao)
		{

			listaAlunos[j + 1] = listaAlunos[j];
			j--;

		}

		listaAlunos[j + 1] = pivo;
		i++;

	}

}

void ordenaNome(alunos *listaAlunos, unsigned short tam)
{

	short i = 1, j;
	alunos pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = listaAlunos[i];

		while (j >= 0 && strcmp(listaAlunos[j].nomeAlunos, pivo.nomeAlunos) > 0)
		{

			listaAlunos[j + 1] = listaAlunos[j];
			j--;

		}

		listaAlunos[j + 1] = pivo;
		i++;

	}

}
