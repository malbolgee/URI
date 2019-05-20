/*
	@autor: Malbolge;
	@data: 17/05/2019;
	@nome: Sete;
*/

#include <stdio.h>

#define true 1
#define false 0

typedef unsigned long long llu;

int main (int argc, char **argv)
{

	llu n, m;
	char l_digit[] = { 1, 7, 9, 3 };

	scanf("%llu", &m);

	while (m--)
		scanf("%llu", &n), printf("%hhd\n", l_digit[n % 4]);

	return  0;

}