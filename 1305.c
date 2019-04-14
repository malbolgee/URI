/*
	@autor: Malbolge;
	@data: 09/04/2019;
	@nome: Arredondamento por Valor de Corte;
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

void main ()
{

	char num[100];
	char cutoff[100];

	while (scanf("%s %s", num, cutoff) != EOF)
	{

		int inteiro = atoi(num);
		double frac = atof(num) - inteiro;
		double _cutoff = atof(cutoff);

		if (frac > _cutoff)
			inteiro++;

		printf("%d\n", inteiro);

	}	

}