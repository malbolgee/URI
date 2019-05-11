/*
	@autor: Malbolge;
	@data: 10/05/2019;
	@nome: O Teorema de Pitágoras;
*/

#include <stdio.h>

#define true 1
#define false 0
#define TRIPLE(a, b, c) (a * a == b * b + c * c)

int mdc(int a, int b);
_Bool tp(unsigned, unsigned, unsigned);

void main ()
{

	unsigned x, y, z;

	while (scanf("%u %u %u", &x, &y, &z) != EOF)
	{

		_Bool flag = tp(x, y, z);
		if (flag && mdc(x, mdc(y, z) == 1))
			printf("tripla pitagorica primitiva\n");
		else if (flag && mdc(x, mdc(y, z) != 1))
			printf("tripla pitagorica\n");
		else
			printf("tripla\n");

	}

}

_Bool tp(unsigned x, unsigned y, unsigned z)
{

	if (TRIPLE(x, y, z) || TRIPLE(y, x, z) || TRIPLE(z, y, x))
		return true;
	else
		return false;

}

int mdc(int a, int b)
{

	int resto = a % b;

	while (resto != 0)
		a = b, b = resto, resto = a % b;

	return b;

}