/*
	@autor: Malbolge;
	@data: 22/09/2018;
	@nome: Sucessor Par;
*/

#include <stdio.h>

void main ()
{

	unsigned long numero;

	scanf("%lu", &numero);

	if (numero % 2 == 0)
		printf("%lu\n", numero + 2);
	else
		printf("%lu\n", numero + 1);

}