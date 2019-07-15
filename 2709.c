/*
	@autor: Malbolge;
	@data: 15/07/2019;
	@nome: As Moedas de Robbie;
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0
#define WIN "You’re a coastal aircraft, Robbie, a large silver aircraft."
#define LOSE "Bad boy! I’ll hit you."

_Bool is_prime(unsigned);

int main(int argc, char **argv)
{

	int vet[30];
	int n, i, s, ans;

	while (scanf("%d", &n) != EOF)
	{

		for (i = 0; i < n; ++i)
			scanf("%d", &vet[i]);

		scanf("%d", &s);

		ans = 0;
		i = n - 1;
		while (i >= 0)
			ans += vet[i], i -= s;

		printf("%s\n", is_prime(ans) ? WIN : LOSE);

	}

	return 0;

}

_Bool is_prime(unsigned num)
{

	unsigned i;
	unsigned raiz = (int)sqrt(num);

	if (num != 2  && num % 2 == 0 || num == 1)
		return false;

	for (i = 3; i <= raiz; i += 2)
		if (num % i == 0)
			return false;

	return true;

}