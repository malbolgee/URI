/*
	@autor: Malbolge;
	@data: 29/01/2019;
	@nome: Soma de Frações;
*/

#include <stdio.h>

int numerador, denominador;
void soma(int, int, int, int);
int mdc(int, int);
int mmc(int, int);

void main ()
{

	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	soma(a, b, c, d);
	int tmp = mdc(numerador, denominador);
	printf("%d %d\n", numerador / tmp, denominador / tmp);

}

void soma(int a, int b, int c, int d)
{

	numerador = a * d + c * b;
	denominador = b * d;

}

int mdc(int a, int b)
{

	int resto = a % b;

	while (resto != 0)
	{

		a = b;
		b = resto;
		resto = a % b;

	}

	return b;

}

int mmc(int a, int b)
{

	return (a / mdc(a , b)) * b;

}
