/*
	@autor: Malbolge;
	@data: 28/09/2018;
	@nome: Pokémon!;
*/

#include <stdio.h>
#include <math.h>

int calcHP(unsigned nivel, unsigned base, unsigned gene, unsigned batalhas);
int calcS(unsigned nivel, unsigned base, unsigned gene, unsigned batalhas);

void main ()
{	

	unsigned gene, batalhas, base, nivel;
	unsigned short casos;
	char pokemon[1000], qtsCasos = 1;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s %u %u %u %u", pokemon, &nivel, &base, &gene, &batalhas);

		printf("Caso #%hu: %s nivel %u\n", qtsCasos++, pokemon, nivel);
		printf("HP: %d\n", calcHP(nivel, base, gene, batalhas));

		scanf("%u %u %u", &base, &gene, &batalhas);
		printf("AT: %d\n", calcS(nivel, base, gene, batalhas));

		scanf("%u %u %u", &base, &gene, &batalhas);
		printf("DF: %d\n", calcS(nivel, base, gene, batalhas));

		scanf("%u %u %u", &base, &gene, &batalhas);
		printf("SP: %d\n", calcS(nivel, base, gene, batalhas));

	}

}

int calcHP(unsigned nivel, unsigned base, unsigned gene, unsigned batalhas)
{

	double s;

	s = (((gene + base + (sqrt(batalhas)/8) + 50) * nivel)/50) + 10;

	return (int)s;

}

int calcS(unsigned nivel, unsigned base, unsigned gene, unsigned batalhas)
{

	double s;

	s = (((gene + base + (sqrt(batalhas)/8)) * nivel)/50) + 5;

	return (int)s;

}