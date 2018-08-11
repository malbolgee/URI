/*
	@autor: Malbolge;
	@data: 06/08/2018;
	@nome: Sequência IJ 2;
*/

#include "stdio.h"

int main ()
{

	unsigned short int i, j;


	i = 1;
	while (i < 10)
	{
		j = 7;
		while (j > 4)
		{

			printf("I=%d J=%d\n",i, j);
			j--;

		}

		i += 2;
	}
}
