/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Câmara de Compensação;
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1010
int cheques[MAXSIZE] = { 0 };

void main ()
{

	unsigned i;
	unsigned short cheque;
	unsigned soma, somaEquivalente;
	unsigned habitanteA, habitanteB;
	unsigned qtsCheques, qtsHabitantes;

	scanf("%u %u", &qtsCheques, &qtsHabitantes);

	somaEquivalente = soma = 0;
	for (i = 0; i < qtsCheques; ++i)
	{

		scanf("%u %hu %u", &habitanteA, &cheque, &habitanteB);
		cheques[habitanteA] -= cheque;
		cheques[habitanteB] += cheque;
		soma += cheque;

	}

	for (i = 1; i <= qtsHabitantes; ++i)
		somaEquivalente += abs(cheques[i]);

	somaEquivalente /= 2;

	if (somaEquivalente == soma)
		printf("N\n");
	else
		printf("S\n");

	printf("%u\n", somaEquivalente);

}
