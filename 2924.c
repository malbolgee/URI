/*
	@autor: Malbolge;
	@data: 10/01/2019;
	@nome: Bigint;
*/

#include <stdio.h>
#include <string.h>

char * soma(char *, char *, char *);
void reverse(char *str, int tam );

void main ()
{

	char numA[500];
	char numB[500];
	char resultado[500] = { 0 };

	scanf("%s %s", numA, numB);

	printf("%s\n", soma(numA, numB, resultado));

}


char * soma(char *str1, char *str2, char *resultado)
{

	int i, j;
	int soma, vaium;
	int tamStr1, tamStr2, diferenca;

	tamStr1 = strlen(str1);
	tamStr2 = strlen(str2);

	if (tamStr2 > tamStr1)
	{

		diferenca = tamStr2 - tamStr1;

		soma = vaium = j = 0;
		for (i = tamStr1 - 1; i >= 0; --i)
		{

			soma = ((str1[i] - '0') + (str2[i + diferenca] - '0') + vaium);
			resultado[j++] = ((soma % 10) + '0');
			vaium = soma / 10;

		}

		for (i = tamStr2 - tamStr1 - 1; i >= 0; --i)
		{

			soma = (str2[i] - '0') + vaium;
			resultado[j++] = ((soma % 10) + '0');
			vaium = soma / 10;

		}

		if (vaium)
			resultado[j++] = vaium + '0';

		resultado[j] = 0;
		reverse(resultado, j);

		return resultado;

	}
	else
	{

		diferenca = tamStr1 - tamStr2;

		soma = vaium = j = 0;
		for (i = tamStr2 - 1; i >= 0; --i)
		{

			soma = ((str2[i] - '0') + (str1[i + diferenca] - '0') + vaium);
			resultado[j++] = ((soma % 10) + '0');
			vaium = soma / 10;

		}

		for (i = tamStr1 - tamStr2 - 1; i >= 0; --i)
		{

			soma = (str1[i] - '0') + vaium;
			resultado[j++] = ((soma % 10) + '0');
			vaium = soma / 10;

		}


		if (vaium)
			resultado[j++] = vaium + '0';

		resultado[j] = 0;
		reverse(resultado, j);

		return resultado;

	}

}

void reverse(char *str, int tam)
{

	char r[500];
	int inicio, fim, i;

	fim = tam - 1;

	for (inicio = 0; inicio < tam; inicio++)
	{

		r[inicio] = str[fim];
		fim--;

	}

	r[inicio] = '\0';

	for (i = 0; i < tam; i++)
		str[i] = r[i];

	str[i] = 0;

}
