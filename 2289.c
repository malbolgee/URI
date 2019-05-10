/*
	@autor: Malbolge;
	@data: 09/05/2019;
	@nome: Distância Hamming;
*/

#include <stdio.h>

#define true 1
#define false 0

void main ()
{

	unsigned long long x, y;
	while (scanf("%llu %llu", &x, &y))
	{

		if (x == 0 && y == 0)
			break;

		unsigned setBits = 0;
		unsigned long long z = x ^ y;

		while (z > 0)
			setBits += z & 1, z >>= 1;
		
		printf("%u\n", setBits);

	}

}