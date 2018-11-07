/*
	@autor: Malbolge;
	@data: 06/11/2018;
	@nome: Godofor;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{

	char nome[150];
	unsigned short qtsPoder;
	unsigned short qtsMatou;
	unsigned short qtsMorreu;

} heroi;

void ordenaPoder(heroi *, unsigned short);
void ordenaQtsMatou(heroi *, unsigned short);
void ordenaQtsMorreu(heroi *, unsigned short);
void ordenaNome(heroi *, unsigned short);
bool verificaRepedito(heroi *, unsigned short);

void main ()
{

	unsigned short qtsInscritos;
	unsigned short i;

	scanf("%hu", &qtsInscritos);

	heroi candidatos[qtsInscritos], candidatos2[qtsInscritos];
	for (i = 0; i < qtsInscritos; i++)
		scanf(" %s %hu %hu %hu", candidatos[i].nome, &candidatos[i].qtsPoder, &candidatos[i].qtsMatou, &candidatos[i].qtsMorreu);

	ordenaNome(candidatos, qtsInscritos);
	ordenaQtsMorreu(candidatos, qtsInscritos);
	ordenaQtsMatou(candidatos, qtsInscritos);
	ordenaPoder(candidatos, qtsInscritos);

	printf("%s\n", candidatos[0].nome);


}

void ordenaPoder(heroi *candidatos, unsigned short tam)
{

	short i = 1, j;
	heroi pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = candidatos[i];

		while (j >= 0 && candidatos[j].qtsPoder < pivo.qtsPoder)
		{

			candidatos[j + 1] = candidatos[j];
			j--;

		}

		candidatos[j + 1] = pivo;
		i++;

	}


}

void ordenaQtsMatou(heroi *candidatos, unsigned short tam)
{

	short i = 1, j;
	heroi pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = candidatos[i];

		while (j >= 0 && candidatos[j].qtsMatou < pivo.qtsMatou)
		{

			candidatos[j + 1] = candidatos[j];
			j--;

		}

		candidatos[j + 1] = pivo;
		i++;

	}

}


void ordenaQtsMorreu(heroi *candidatos, unsigned short tam)
{

	short i = 1, j;
	heroi pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = candidatos[i];

		while (j >= 0 && candidatos[j].qtsMorreu > pivo.qtsMorreu)
		{

			candidatos[j + 1] = candidatos[j];
			j--;

		}

		candidatos[j + 1] = pivo;
		i++;

	}

}

void ordenaNome(heroi *candidatos, unsigned short tam)
{

	short i = 1, j;
	heroi pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = candidatos[i];

		while (j >= 0 && strcmp(candidatos[j].nome, pivo.nome) > 0)
		{

			candidatos[j + 1] = candidatos[j];
			j--;

		}

		candidatos[j + 1] = pivo;
		i++;

	}

}
