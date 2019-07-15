/*
	@autor: Malbolge;
	@data: 09/12/2018;
	@nome: Luzes de Natal;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef long long unsigned llu;

char valueToChar(llu a);
llu decimalToBase(llu x, llu base);

int main(int argc, char **argv)
{

	llu light, n;
	scanf("%llu", &n);

	while (n--)
	{

		scanf("%llu", &light);
		printf("%llu\n", decimalToBase(light, 2LLU));

	}

	return 0;

}

llu decimalToBase(llu x, llu base)
{

	llu count, ans = 0;

	count = 0;
	while (x > 0)
	{

		if (valueToChar(x % base) == '1')
			count++;
		else
			count = 0;

		if (count > ans)
			ans = count;

		x /= base;

	}

	return ans;

}

char valueToChar(llu a)
{

	if (a >= 0 && a <= 9)
		return (char)(a + '0');
	else
		return (char)(a - 10 + 'a');

}