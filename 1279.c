/*
	@autor: Malbolge;
	@data: 21/01/2019;
	@nome: Ano Bissexto ou Ano não Bissexto;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 3000

_Bool isDiv(char *, int);

void main ()
{

	int tam;
	char numero[MAXSIZE];
	_Bool leap, huluculu, bulukulu, flag;
	long long multi55, multi400, multi4, multi100, multi15;

	flag = false;
	while (scanf("%s", numero) != EOF)
	{

		if (flag)
			printf("\n");

		flag = true;
		leap = huluculu = bulukulu = false;

		multi4 = isDiv(numero, 4);
		multi15 = isDiv(numero, 15);
		multi55 = isDiv(numero, 55);
		multi100 = isDiv(numero, 100);
		multi400 = isDiv(numero, 400);

		if (multi400 || (multi4 && !multi100))
			printf("This is leap year.\n"), leap = true, bulukulu = true;
		if (multi15)
			printf("This is huluculu festival year.\n"), leap = true;
		if (multi55 && bulukulu)
			printf("This is bulukulu festival year.\n");
		if (!leap)
			printf("This is an ordinary year.\n");

	}

}

_Bool isDiv(char *numero, int divisor)
{

	int i, j;

	j = 0;
	for (i = 0; numero[i]; ++i)
		j = ((numero[i] - '0') + j * 10) % divisor;

	if (j == 0)
		return true;
	else
		return false;

}
