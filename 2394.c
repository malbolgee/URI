/*
	@autor: Malbolge;
	@data: 23/01/2019;
	@nome: Corrida 1;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 110

void main ()
{
	unsigned tmp;
	unsigned short i;
	unsigned short n, m;
	long long tempos[MAXSIZE] = { 0 };

	scanf("%hu %hu", &n, &m);

	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%u", &tmp), tempos[i] += tmp;

	int pos = 1;
	int menor = tempos[1];
	for (int i = 2; i <= n; ++i)
		if (tempos[i] < menor)
			menor = tempos[i], pos = i;

	printf("%d\n", pos);

}
