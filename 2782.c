/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Escadinha;
*/

#include <stdio.h>
#include <stdlib.h>

unsigned escadinha(int *, unsigned short);

void main ()
{

	unsigned short i;
	unsigned short tamSequencia;

	scanf("%hu", &tamSequencia);

	int sequencia[tamSequencia];

	for (i = 0; i < tamSequencia; ++i)
		scanf("%d", &sequencia[i]);

	printf("%u\n", escadinha(sequencia, tamSequencia));

}

unsigned escadinha(int *sequencia, unsigned short tam)
{

	unsigned short i;
	int anterior, atual, qtsEscadinhas;

	if (tam == 1 || tam == 2)
		return 1;

	qtsEscadinhas = 1;
	anterior = sequencia[0] - sequencia[1];

	for (i = 2; i < tam; ++i)
	{

		atual = sequencia[i - 1] - sequencia[i];
		if (atual != anterior)
			anterior = atual, qtsEscadinhas++;

	}

	return qtsEscadinhas;

}
