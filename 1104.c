/*
	@autor: Malbolge;
	@data: 03/01/2019;
	@nome: Troca de Cartas;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100101

typedef struct Cartas{

	_Bool alice;
	_Bool beatriz;

} Cartas;

Cartas cartas[MAXSIZE];

void main ()
{

	unsigned i, tmp;
	unsigned alice, beatriz;

	while (scanf("%u %u", &alice, &beatriz), alice)
	{

		memset(cartas, false, sizeof(cartas));

		for (i = 0; i < alice; ++i)
			scanf("%u", &tmp), cartas[tmp].alice = true;

		for (i = 0; i < beatriz; ++i)
			scanf("%u", &tmp), cartas[tmp].beatriz = true;

		alice = beatriz = 0;
		for (i = 0; i < MAXSIZE; ++i)
		{

			if (cartas[i].alice && !cartas[i].beatriz)
				++alice;

			if (!cartas[i].alice && cartas[i].beatriz)
				++beatriz;

		}

		printf("%d\n", beatriz > alice ? alice : beatriz);

	}

}
