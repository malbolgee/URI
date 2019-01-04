/*
	@autor: Malbolge;
	@data: 03/01/2019;
	@nome: Cápsulas;
*/

#include <stdio.h>

#define MAXSIZE 1000001

unsigned numCapsulas;
unsigned capsulas[MAXSIZE] = { 0 };

unsigned qtsDinheiro(unsigned x);
unsigned buscaBin(unsigned *, unsigned);

void main ()
{

	unsigned i;
	unsigned numMoedasDesejadas;

	scanf("%u %u", &numCapsulas, &numMoedasDesejadas);

	for (i = 0; i < numCapsulas; ++i)
		scanf("%u", &capsulas[i]);

	printf("%u\n", buscaBin(capsulas, numMoedasDesejadas));

}

unsigned buscaBin(unsigned *capsulas, unsigned numMoedasDesejadas)
{

	unsigned esquerda, direita, meio;

	esquerda = 1;
	direita = 100000000;

	while (esquerda < direita)
	{

		meio = (esquerda + direita) / 2;
		if (qtsDinheiro(meio) >= numMoedasDesejadas)
			direita = meio;
		else
			esquerda = meio + 1;

	}

	return esquerda;

}

unsigned qtsDinheiro(unsigned x)
{

	unsigned i;
	unsigned total = 0;

	for (i = 0; i < numCapsulas; ++i)
		total += x / capsulas[i];

	return total;

}
