/*
	@autor: Malbolge;
	@data: 26/12/2018;
	@nome: Tiro ao Alvo;
*/

#include <stdio.h>

long long raios[100010];
int buscaBin(long long, long long);

void main ()
{

	unsigned i;
	long long Px, Py;
	long long qtsPontos, tmp;
	long long qtsCirculos, qtsTiros;

	scanf("%lld %lld", &qtsCirculos, &qtsTiros);

	for (i = 1; i <= qtsCirculos; i++)
	{

		scanf("%lld", &tmp);
		raios[i] = tmp * tmp;

	}

	qtsPontos = 0;
	for (i = 1; i <= qtsTiros; i++)
	{

		scanf("%lld %lld", &Px, &Py);
		qtsPontos += buscaBin((Px * Px + Py * Py), qtsCirculos);

	}

	printf("%lld\n", qtsPontos);

}

// Busca binária;
int buscaBin(long long distancia, long long qtsCirculos)
{

	long long meio;
	long long inicio = 1;
	long long fim = qtsCirculos;

	// Se a distância for maior do que o maior raio
	// Então esse ponto está fora de todos os círculos;
	if (distancia > raios[fim])
		return 0;

	while (inicio < fim)
	{

		meio = (inicio + fim) / 2;

		if (raios[meio] >= distancia)
			fim = meio;
		else
			inicio = meio + 1;

	}

	return qtsCirculos + 1 - fim;

}
