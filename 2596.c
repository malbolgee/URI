/*
	@autor: Malbolge;
	@data: 11/10/2018;
	@nome: Xenlonguinho;
*/

#include <stdio.h>
#include <math.h>

#define MAXSIZE 1000

short numeros[MAXSIZE];

void calcDivPar();

void main ()
{

	unsigned short casos;
	unsigned qtsEsferas, qtsDivPar;
	unsigned i;

	calcDivPar();
	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%u", &qtsEsferas);

		qtsDivPar = 1;
		// o laço só verifica quantos divisores são pares
		// o algoritmo é rápido porque o cálculo de divisores
		// Só acontece uma vez e fica salvo num vetor
		// Declarado globalmente;
		for (i = 3; i <= qtsEsferas; i++)
		{

			if (numeros[i] % 2 == 0)
				qtsDivPar++;

		}

		printf("%u\n", qtsDivPar);
	}

}
// Função que calcula a quantidade de divisores de um número;
// A função calcula a quantidade de divisores de cada número no intervalo
// de 1 a 1000 e salva os resultados num vetor;
void calcDivPar()
{
	unsigned i, j, limite;
	unsigned qtsNumDiv;

	numeros[0] = 3;
	numeros[1] = 1;

	for (i = 2; i <= 1000; i++)
	{
		qtsNumDiv = 2;
		limite = i / 2;
		for (j = 2; j <= limite; j++)
		{
			if (i % j == 0)
				qtsNumDiv++;

		}

		numeros[i] = qtsNumDiv;
	}

}
