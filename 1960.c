/*
	@autor: Malbolge;
	@data: 18/01/2019;
	@nome: Numeração Romana para Números de Página;
*/

#include <stdio.h>

int decimal[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
char *romano[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

void converter(int num);

void main ()
{

	int num;

	scanf("%d", &num);

	converter(num);
	printf("\n");

}

void converter(int num)
{

	int i;

	i = 0;
	while (num)
	{
		while (num / decimal[i])
		{

			printf("%s", romano[i]);
			num -= decimal[i];

		}

		++i;

	}
}
