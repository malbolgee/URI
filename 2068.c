/*
	@autor: Malbolge;
	@data: 13/01/2019;
	@nome: Marcando um Encontro;
*/

#include <stdio.h>

unsigned long long mdc(unsigned long long a, unsigned long long b);

void main ()
{

	unsigned long long possibilidade;
	unsigned long long intervalo, total;
	unsigned long long tempo1, tempo2, maxTempo;

	scanf("%llu %llu %llu", &tempo1, &tempo2, &maxTempo);

	intervalo = (tempo2 - tempo1) * 60;

	total = (intervalo * intervalo);
	possibilidade = total - ((intervalo - maxTempo) * (intervalo - maxTempo));

	printf("%llu/%llu\n", possibilidade / mdc(possibilidade, total), total / mdc(possibilidade, total));

}

unsigned long long mdc(unsigned long long a, unsigned long long b)
{

	unsigned long long resto;

	resto = a % b;
	while (resto != 0)
	{

		a = b;
		b = resto;
		resto = a % b;

	}

	return b;

}
