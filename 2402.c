/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Selos;
*/

#include <stdio.h>

#define true 1
#define false 0

_Bool isPrime(long long);

void main ()
{

	long long n;

	scanf("%lld", &n);
	// printf("%s\n", ((n & 1) || n == 2) ? "N" : "S");
	printf("%s\n", isPrime(n) ? "N" : "S");

}

_Bool isPrime(long long x)
{

	long long i;

	if (x == 1 || x == 2)
		return true;

	if (!(x & 1))
		return false;

	for (i = 3; i * i <= x; i += 2)
		if (x % i == 0)
			return false;

	return true;

}
