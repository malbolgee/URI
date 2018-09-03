/*
	@autor: Malbolge;
	@data: 03/09/2018;
	@nome: O Matemático;
*/

#include <stdio.h>

void main (void)
{

	int numero1, numero2, i, casos, j;
	unsigned char vezes;

	scanf("%d", &casos);

	for (i = 0; i < casos; i++)
	{

		scanf("%d%c%d", &numero1, &vezes, &numero2);

		if (numero1 == numero2)
			for (j = 5; j <= 10; j++)
				printf("%d x %d = %d\n", numero1, j, numero1*j);
		else
			for (j = 5; j <= 10; j++)
				printf("%d x %d = %d && %d x %d = %d\n", numero1, j, numero1*j, numero2, j, numero2*j);
	}
}