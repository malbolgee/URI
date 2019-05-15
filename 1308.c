/*
	@autor: Malbolge;
	@data: 15/05/2019;
	@nome: Guerreiros Etruscos Nunca Jogam Xadrez;
*/

// s = (n * (n - 1)) /  2;

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

typedef long long unsigned llu;

int main (int argc, char **argv)
{

	llu s;
	unsigned n, i;

	scanf("%u", &n);
	for (i = 0; i < n; ++i)
		scanf("%llu", &s), printf("%llu\n", (llu)(-1 + sqrt(1 + 8 * s)) / 2);

}
