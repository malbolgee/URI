/*
    @autor: Malbolge;
    @data: 23/03/2019;
    @nome: Marianne e os Primos Gêmeos;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 1000010

int twins[MAXSIZE];
_Bool primes[MAXSIZE];

void sieve();

void main ()
{	

	sieve();
	unsigned i, j;

	for (i = 3; i <= MAXSIZE; ++i)
	{
		if (!primes[i])
		{
			
			if (i > 1)
				if (!primes[i - 2])
					twins[i] = 1;
			if (i + 2 < MAXSIZE)
				if (!primes[i + 2])
					twins[i] = 1;

		}

		if (i)
			twins[i] += twins[i - 1];

	}

	unsigned n;
	unsigned x, y;
	scanf("%u", &n);

	while (n--)
	{

		scanf("%u %u", &x, &y);
		if (x > y)
			x = x ^ y, y = y ^ x, x = x ^ y;

		printf("%d\n", twins[y] - twins[x - 1]);

	}

}

void sieve()
{

	primes[0] = true;
	primes[1] = true;
	unsigned i, j;

	for (i = 2; i <= 1000; ++i)
		if (!primes[i])
			for (j = i * i; j < MAXSIZE; j += i)
				primes[j] = true;

}
