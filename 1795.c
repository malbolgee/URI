/*
	@autor: Malbolge;
	@data: 15/05/2019;
	@nome: Triângulo Trinomial;
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define MOD 2147483647

typedef unsigned long long llu;

llu power(int, int);

int main (int argc, char **argv)
{

	int n;
	scanf("%d", &n);
	printf("%llu\n", (llu)pow(3, n));

	return 0;

}