/*
	@autor: Malbolge;
	@data: 23/01/2019;
	@nome: Dígitos Diferentes;
*/

#include <stdio.h>

#define true 1
#define false 0

int diffDigits(int a, int b);

void main ()
{

	int a, b;

	while (scanf("%d %d", &a, &b) != EOF)
		printf("%d\n", diffDigits(a, b));

}

int diffDigits(int a, int b)
{

	unsigned short i, num;
	unsigned short contador = 0;

	for (i = a; i <= b; ++i)
	{

		num = i;
		_Bool visitados[10] = { false };
		while (num)
		{

			if (visitados[num % 10])
				break;

			visitados[num % 10] = true;

			num = num / 10;

		}

		if (num == 0)
			++contador;

	}

	return contador;

}
