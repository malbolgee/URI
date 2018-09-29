/*
	@autor: Malbolge;
	@data: 28/09/2018;
	@nome: Quadro De Medalhas;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char pais[20];
	unsigned short ouro, prata, bronze;

} medalhas;

void preencheQuadro(medalhas vet[], unsigned short tam);
void ordena(medalhas vet[], unsigned short tam);
void ordenaAlpha(medalhas vet[], unsigned short tam);
void ordenaPrata(medalhas vet[], unsigned short tam);
void ordenaBronze(medalhas vet[], unsigned short tam);
void structPress(medalhas vet[], unsigned short tam);

void main ()
{

	unsigned short casos;

	scanf("%hu", &casos);

	// Vetor de Structs do tipo Medalha;
	medalhas paisMedalhas[casos + 1];

	preencheQuadro(paisMedalhas, casos);

	ordenaAlpha(paisMedalhas, casos);
	ordenaBronze(paisMedalhas, casos);
	ordenaPrata(paisMedalhas, casos);
	ordena(paisMedalhas, casos);

	structPress(paisMedalhas, casos);

}

void preencheQuadro(medalhas vet[], unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		scanf(" %s %hu %hu %hu", vet[i].pais, &vet[i].ouro, &vet[i].prata, &vet[i].bronze);


}

void ordena(medalhas vet[], unsigned short tam)
{

	short i = 1, j;
	medalhas pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = vet[i];

		while (j >= 0 && vet[j].ouro < pivo.ouro)
		{
			
				vet[j + 1] = vet[j];
				j--;
		
		}

		vet[j + 1] = pivo;
		i++;

	}

}

void structPress(medalhas vet[], unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		printf("%s %hu %hu %hu\n", vet[i].pais, vet[i].ouro, vet[i].prata, vet[i].bronze);

}

void ordenaAlpha(medalhas vet[], unsigned short tam)
{

	short i = 1, j;
	medalhas pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = vet[i];

		while (j >= 0 && strcmp(vet[j].pais, pivo.pais) > 0)
		{
			
				vet[j + 1] = vet[j];
				j--;
		
		}

		vet[j + 1] = pivo;
		i++;

	}

}

void ordenaBronze(medalhas vet[], unsigned short tam)
{

	short i = 1, j;
	medalhas pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = vet[i];

		while (j >= 0 && vet[j].bronze < pivo.bronze)
		{
			
				vet[j + 1] = vet[j];
				j--;
		
		}

		vet[j + 1] = pivo;
		i++;

	}

}

void ordenaPrata(medalhas vet[], unsigned short tam)
{

	short i = 1, j;
	medalhas pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = vet[i];

		while (j >= 0 && vet[j].prata < pivo.prata)
		{
			
				vet[j + 1] = vet[j];
				j--;
		
		}

		vet[j + 1] = pivo;
		i++;

	}

}