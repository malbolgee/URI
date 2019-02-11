/*
	@autor: Malbolge;
	@data: 11/02/2019;
	@nome: ABC;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1500
#define MOD 1000000007

long long vetor[MAXSIZE];

void preenche();

void main ()
{

	preenche();

	short i;
	long long pos, ans;
	char string[MAXSIZE];

	while (scanf("%s", string) != EOF)
	{

		ans = 0;
		pos = strlen(string) - 1;
		for (i = 0; string[i]; ++i, --pos)
			ans = ((ans % MOD) + ((string[i] - 'A') * vetor[pos])) % MOD;

		printf("%lld\n", ans);

	}

}

void preenche()
{

	short i;
	long long ans = 1;

	vetor[0] = ans;
	for (i = 1; i < 1005; ++i)
		ans = (ans * 26) % MOD, vetor[i] = ans;

}
