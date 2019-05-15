/*
	@autor: Malbolge;
	@data: 15/05/2019;
	@nome: Estrela;
*/

// https://bit.ly/2Hk49vF - TCC sobre polígonos estraldos;
// https://bit.ly/2JGrOrE - Artigo sobre função totiente de Euler;

#include <stdio.h>

#define true 1
#define false 0

unsigned n;

// Função totiente de Euler;
unsigned phi(unsigned p, unsigned k);

int main (int argc, char **argv)
{	

	_Bool is_divisor;	
	unsigned i, power, ans;

	while (scanf("%u", &n) != EOF)
	{	

		ans = 1;
		for (i = 2; i <= (n / i); ++i)
		{

			power = 0;
			is_divisor = false;
			
			// Fatores primos;
			while (!(n % i))
				is_divisor = true, ++power, n /= i;

			if (is_divisor)
				ans *= phi(i, power);	

		}

		if (n > 1)
			ans *= phi(n, 1);

		printf("%u\n", ans / 2);

	}

	return 0;

}

unsigned phi(unsigned p, unsigned k)
{

	if (p == 1)
		return 1;

	unsigned i; --k;
	unsigned ans = 1;
	for (i = 0; i < k; ++i)
		ans *= p;

	return ans *= (p - 1);

}