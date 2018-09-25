/*
	@autor: Malbolge;
	@data: 25/09/2018;
	@nome: Kage Bunshin no Jutsu;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned long long resultado, ninja;
	unsigned i;

	while (scanf("%llu", &ninja) != EOF)
	{

		if (ninja == 1)
			printf("0\n");
		else
			for (i = 0; i < ninja; i++)
			{

				resultado = (unsigned long long)pow(2, i);
				if (resultado == ninja)
				{
					printf("%u\n", i);
					break;
				}
			}

	}
}