/*
	@autor: Malbolge;
	@data: 13/01/2019;
	@nome: Cigarras Periódicas;
*/

#include <stdio.h>

long long mdc(long long, long long);
long long mmc(long long, long long);

void main ()
{

	long long i, ciclos, tmp;
	long long qtsPopulacoes, limite;
	long long melhor, melhorMmc, mmc2;

	scanf("%lld %lld", &qtsPopulacoes, &limite);

	tmp = 1;
	// A quantidade de iterações necessária até que os ciclos coicidam
	// É o mmc dos cliclos de todas as populações em questão;
	for (i = 0; i < qtsPopulacoes; ++i)
		scanf("%lld", &ciclos), tmp = mmc(tmp, ciclos);

	melhor = 1;
	melhorMmc = tmp;

	// O resultado tem de respeitar o limite superior "limite"
	// Então, não faz sentido que a nova população tenha um ciclo de vida
	// maior que 'limite';
	for (i = 2; i <= limite; ++i)
	{

		mmc2 = mmc(tmp, i);
		if (mmc2 <= limite && mmc2 > melhorMmc)
			melhorMmc = mmc2, melhor = i;

	}

	printf("%lld\n", melhor);

}

long long mdc(long long a, long long b)
{

	long resto;

	resto = a % b;
	while (resto != 0)
	{

		a = b;
		b = resto;
		resto = a % b;

	}

	return b;

}

long long mmc(long long a, long long b)
{

	return (a / mdc(a, b)) * b;

}
