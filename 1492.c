/*
	@autor: Malbolge;
	@data: 24/12/2018;
	@nome: Contando Uns;
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

long long bigNum[60][60][2];

long long qts1s(const long long *n, int i, int acc, int top);

void main ()
{

	long long numeroA, numeroB;

	while (scanf("%lld %lld", &numeroA, &numeroB) != EOF)
	{

		numeroA--;
		memset(bigNum, -1, sizeof(bigNum));
		long long qtsUns = qts1s(&numeroB, 55, 0, 1);
		memset(bigNum, -1, sizeof(bigNum));
		qtsUns -= qts1s(&numeroA, 55, 0, 1);

		printf("%lld\n", qtsUns);

	}

}

long long qts1s(const long long *n, int i, int acc, int top)
{

	if (i == -1)
		return acc;

	if (bigNum[i][acc][top] != -1)
		return bigNum[i][acc][top];

	// printf("%lld\n", *n);
	// sleep(2);
	long long retorno = qts1s(n, i - 1, acc, !(((*n) >> i) & (long long)1) && top);

	if (!top || (((*n) >> i) & 1))
		retorno += qts1s(n, i - 1, acc + 1, (((*n) >> i) & (long long)1) && top);

	return bigNum[i][acc][top] = retorno;

}
