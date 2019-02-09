/*
	@autor: Malbolge;
	@data: 03/02/2019;
	@nome: Caçadores de Mitos;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 600

unsigned short grid[MAXSIZE][MAXSIZE];

void main ()
{

	unsigned n, x, y;
	_Bool flag = false;
	unsigned linha, coluna;

	scanf("%d", &n);

	while (n--)
	{

		scanf("%u %u", &x, &y);

		if (grid[x][y])
			flag = true;
		else
			grid[x][y] = 1;

	}

	printf("%c\n", flag ? '1' : '0');

}
