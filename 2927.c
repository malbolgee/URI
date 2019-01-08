/*
	@autor: Malbolge;
	@data: 07/01/2019;
	@nome: Imprevistos Natalinos;
*/

#include <stdio.h>

void main ()
{

	unsigned short numAlunos, numPc;
	unsigned short qtsPcsQuebrados, qtsPcsSemComp;

	scanf("%hu %hu %hu %hu", &numAlunos, &numPc, &qtsPcsQuebrados, &qtsPcsSemComp);

	if (numPc - qtsPcsQuebrados - qtsPcsSemComp > numAlunos)
		printf("Igor feliz!\n");
	else
	{

		if (qtsPcsQuebrados > qtsPcsSemComp / 2)
			printf("Caio, a culpa eh sua!\n");
		else
			printf("Igor bolado!\n");

	}

}
