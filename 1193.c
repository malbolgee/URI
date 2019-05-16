/*
	@autor: Malbolge;
	@data: 15/05/2019;
	@nome: Conversão entre Bases;
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0

void strrev(char *);
char valueToChar(unsigned);
unsigned int StrToInt(char *);
unsigned baseToDec(char *, int);
char * decimalToBase(unsigned, unsigned , char *);

int main (int argc, char **argv)
{

	int n, caso = 0;
	char ans[1000];
	char numero[1000], base[6];

	scanf("%d", &n);

	while (n--)
	{

		scanf("%s%*c%s", numero, base);
		
		if (strcmp(base, "bin") == 0)
		{

			printf("Case %d:\n", ++caso);
			printf("%u dec\n", baseToDec(numero, 2));
			printf("%s hex\n\n", decimalToBase(baseToDec(numero, 2), 16, ans));

		}
		else if (strcmp(base, "dec") == 0)
		{

			printf("Case %d:\n", ++caso);
			printf("%s hex\n", decimalToBase(StrToInt(numero), 16, ans));
			printf("%s bin\n\n", decimalToBase(StrToInt(numero), 2, ans));

		}
		else
		{

			printf("Case %d:\n", ++caso);
			printf("%u dec\n", baseToDec(numero, 16));
			printf("%s bin\n\n", decimalToBase(baseToDec(numero, 16), 2, ans));

		}

	}

}

// Converte um número numa base b para decimal;
unsigned baseToDec(char *str, int base)
{

	int i;
	unsigned ans = 0;
	int power = 1;
	int len = strlen(str);

	for (i = len - 1; i >= 0; --i, power *= base)
		if (str[i] >= '0' && str[i] <= '9')
			ans += ((int)str[i] - '0') * power;
		else
			ans += ((int)str[i] - 'a' + 10) * power;

	return ans;

}

// Transforma um número decimal para uma base b
char * decimalToBase(unsigned x, unsigned base, char *dest)
{

	unsigned idx = 0;

	while (x > 0)
		dest[idx++] = valueToChar(x % base), x /= base;

	dest[idx] = '\0';
	strrev(dest);
	return dest;

}

// Função auxiliar
char valueToChar(unsigned a)
{

	if (a >= 0 && a <= 9)
		return (char)(a + '0');
	else
		return (char)(a - 10 + 'a');

}

// reverte uma string;
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

unsigned StrToInt(char *str)
{

	int tamanho;
	unsigned ret, multiplicador;

	for(tamanho = strlen(str) - 1, multiplicador = 1, ret = 0; tamanho >= 0; tamanho--, multiplicador *= 10)
		ret +=  (str[tamanho] - 48) * multiplicador;

	return ret;

}