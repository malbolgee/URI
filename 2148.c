/*
	@autor: Malbolge;
	@data: 19/01/2019;
	@nome: Banco de Dados;
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int s, d;
long long memoria[100][100];

long long pd(int, int);

void main ()
{

	int qtsCasos;

	scanf("%d", &qtsCasos);

	while (qtsCasos--)
	{

		scanf("%d %d", &s, &d);

		memset(memoria, -1, sizeof(memoria));
		printf("%.15Lf\n", pd(0, 0) / (long double)powl(6, d));

	}

}

long long pd(int soma, int dados)
{

	char i;

	if (dados == d)
		return soma == s;

	if (soma >= s)
		return 0;

	if (memoria[soma][dados] != -1)
		return memoria[soma][dados];

	long long retorno = 0;

	for (i = 1; i <= 6; ++i)
		retorno += pd(soma + i, dados + 1);

	return memoria[soma][dados] = retorno;

}
