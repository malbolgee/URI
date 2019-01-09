/*
	@autor: Malbolge;
	@data: 08/01/2019;
	@nome: Ações;
*/

#include <stdio.h>

void main ()
{

	int D, I, X, F;

	scanf("%d %d %d %d", &D, &I, &X, &F);

	int soma = I;

	for (int i = D + 1; i <= D + F; i++)
		if (i % 2 != 0)
			soma -= X;
		else
			soma += X;

	printf("%d\n", soma);

}
