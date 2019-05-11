/*
	@autor: Malbolge;
	@data: 10/05/2019;
	@nome: Fatorial de Novo!;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef long long unsigned llu;

llu fat(int );

void main ()
{

	llu tot;
	char i, j;
	char string[10];

	while (scanf("%s", string))
	{

		if (strcmp(string, "0") == 0)
			break;

		tot = 0;
		char tam = strlen(string);

		for (i = 0, j = tam; i < tam; ++i, --j)
			tot += (int)(string[i] - '0') * fat(j);

		printf("%llu\n", tot);

	}

}

llu fat(int a)
{

	llu ans = 1;
	while (a > 1)
		ans *= a--;

	return ans;

}