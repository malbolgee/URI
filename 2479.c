/*
	@autor: Malbolge;
	@data: 28/09/2018;
	@nome: Ordenando a Lista de Crianças do Papai Noel;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char nome[21];

} nomes;

void ordena(nomes vet[], unsigned short);
void impressao(nomes vet[], unsigned short);

void main ()
{

	char comportamento;
	unsigned short bemComportado = 0, mauComportado = 0;
	unsigned short casos, aux, i;

	scanf("%hu", &casos);

	aux = casos;

	nomes lista[aux];

	i = 0;
	while (casos--)
	{

		scanf(" %c %s", &comportamento, lista[i].nome);
		i++;

		if (comportamento == '+')
			bemComportado++;
		else
			mauComportado++;

	}

	ordena(lista, aux);
	impressao(lista, aux);
	printf("Se comportaram: %hu | Nao se comportaram: %hu\n", bemComportado, mauComportado);

}

void ordena(nomes vet[], unsigned short tam)
{

	short i = 1, j;
	nomes pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = vet[i];

		while (j >= 0 && strcmp(vet[j].nome, pivo.nome) > 0)
		{

			vet[j + 1] = vet[j];
			j--;

		}

		vet[j + 1] = pivo;
		i++;

	}

}

void impressao(nomes vet[], unsigned short tam)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		printf("%s\n", vet[i].nome);

}