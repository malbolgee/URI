/*
	@autor: Malbolge;
	@data: 05/05/2019;
	@nome: Problema com Mediana e Média;
*/

#include <stdio.h>

void main ()
{

	unsigned a, b;
	while (scanf("%u %u", &a, &b), a && b)
		printf("%d\n", 2 * a - b);

}