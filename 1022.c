/*
	@autor: Malbolge;
	@data: 17/01/2019;
	@nome: TDA Racional;
*/

#include <stdio.h>

int mdc(int, int);
int mmc(int, int);
void multi(int, int, int, int, int *, int *);
void soma(int, int, int, int, int *, int *);
void sub(int, int, int, int, int *, int *);
void divv(int, int, int, int, int *, int *);

void main ()
{

	char operacao;
	int a, b, c, d;
	unsigned qtsCasos;
	int numerador, denominador, tmp;

	scanf("%u", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%d / %d %c %d / %d", &a, &b, &operacao, &c, &d);

		if (operacao == '+')
			soma(a, b, c, d, &numerador, &denominador);
		else if (operacao == '-')
			sub(a, b, c, d, &numerador, &denominador);
		else if (operacao == '*')
			multi(a, b, c, d, &numerador, &denominador);
		else if (operacao == '/')
			divv(a, b, c, d, &numerador, &denominador);

		tmp = mdc(numerador, denominador);

		if (tmp < 0)
			printf("%d/%d = %d/%d\n", numerador, denominador, -(numerador / tmp), -(denominador / tmp));
		else
			printf("%d/%d = %d/%d\n", numerador, denominador, numerador / tmp, denominador / tmp);

	}

}

void soma(int a, int b, int c, int d, int *numerador, int *denominador)
{

	*numerador = a * d + c * b;
	*denominador = b * d;

}

void sub(int a, int b, int c, int d, int *numerador, int *denominador)
{

	*numerador = a * d - c * b;
	*denominador = b * d;

}

void multi(int a, int b, int c, int d, int *numerador, int *denominador)
{

	*numerador = a * c;
	*denominador = b * d;

}

void divv(int a, int b, int c, int d, int *numerador, int *denominador)
{

	*numerador = (a * d);
	*denominador = (c * b);

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
