/*
    @autor: Malbolge;
    @data: 20/08/2019;
    @nome: Oceano Profundo! Faça-o Raso!!;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MOD 131071

char tmp[101];
char string[10110];

_Bool check(char *);

int main(int argc, char **argv)
{

	while (true)
	{

		char c;
		int i = 0;
		while (true)
		{

			c = getchar_unlocked();

			if (c == '#' || c == EOF)
				break;

			if (c != '\n')
				string[i++] = c;

		}

		string[i] = 0;

		if (c == EOF)
			break;

		printf("%s\n", check(string) ? "YES" : "NO");

	}

	return 0;

}

_Bool check(char *s1)
{

	unsigned i = 0;
	unsigned resto = 0;
	while (s1[i])
	{

		if ((s1[i] - '0') == 1)
			resto = (resto * 2 + 1) % MOD;
		if ((s1[i] - '0') == 0)
			resto = (resto * 2) % MOD;

		i++;
	}

	if (resto % MOD == 0)
		return true;
	else
		return false;

}