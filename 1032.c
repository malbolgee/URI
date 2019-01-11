/*
	@autor: Malbolge;
	@data: 11/01/2019;
	@nome: O Primo de Josephus;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 3502
#define MAXPRIME 32650

int josephus(int n);
_Bool isPrime(int x);
void preenchePrimo();

int primos[MAXSIZE] = { 0 };

void main ()
{

	preenchePrimo();
	int n;

	while (true)
	{

		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%d\n", josephus(n));

	}

}


int josephus(int n)
{

	int i;
	int retorno = 0;

	// Recorrência;
	for (i = 1; i <= n; ++i)
		retorno = (retorno + primos[n - i]) % i;

	return ++retorno;

}

_Bool isPrime(int x)
{

	int i;
	if (x == 2)
		return true;

	if (!(x & 1))
		return false;

	for (i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;

	return true;

}

void preenchePrimo()
{

	int i, j;
	for (i = 2, j = 0; i < MAXPRIME; ++i)
		if (isPrime(i))
			primos[j++] = i;

}
