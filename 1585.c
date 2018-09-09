/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: Fazendo Pandorgas;
*/

#include <stdio.h>

void main ()
{

	unsigned short casos, numDiag, num2Diag;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu %hu", &numDiag, &num2Diag);

		printf("%hu cm2\n", (numDiag*num2Diag)/2);


	}

}