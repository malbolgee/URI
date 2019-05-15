/*
	@autor: Malbolge;
	@data: 13/05/2019;
	@nome: Ones;
*/

#include <stdio.h>

#define true 1
#define false 0

typedef unsigned long long llu;

int main (int argc, char **argv)
{

	llu i, n, ans;
	while (scanf("%llu", &n) != EOF)
	{

		i = 1; ans = 1;
		while (i % n)
			i = ((i * 10) + 1) % n, ++ans, printf("%llu\n", i);

		printf("%llu\n", ans);

	}

	return 0;

}