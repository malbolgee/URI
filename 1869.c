/*
	@autor: Malbolge;
	@data: 15/05/2019;
	@nome: Base 32;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned long long llu;

void strrev(char *);
char valueToChar(llu);
char * baseToDecimal(llu, unsigned, char *);

int main (int argc, char **argv)
{

	llu n;
	char *string = (char *) calloc(100, sizeof(char));

	do
	{

		scanf("%llu", &n);
		printf("%s\n", n ? baseToDecimal(n, 32, string) : "0");

	} while (n);

	free(string);

}

char valueToChar(llu a)
{

	if (a >= 0 && a <= 9)
		return (char)(a + '0');
	else
		return (char)(a - 10 + 'A');

}

void strrev(char *str)
{

	unsigned i;
	unsigned len = strlen(str);
	unsigned max = len / 2;

	for (i = 0; i < max; ++i)
	{

		char tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;

	}

}

char * baseToDecimal(llu x, unsigned base, char *dest)
{

	unsigned idx = 0;

	while (x > 0)
		dest[idx++] = valueToChar(x % base), x /= base;

	dest[idx] = '\0';
	strrev(dest);
	return dest;

}