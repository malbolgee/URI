/*
	@autor: Malbolge;
	@data: 15/10/2018;
	@nome: Números Divinos;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 1000000

unsigned long divisores[MAXSIZE];
bool foivisto[MAXSIZE];

void calcSomaDiv();
void calcSomaDivTest();

void main ()
{

	unsigned numero, i, soma = 0;

	// calcSomaDiv();
	memset(foivisto, false, sizeof(foivisto));
	memset(divisores, 0, sizeof(divisores));
	calcSomaDivTest();

	while (true)
	{

		scanf("%u", &numero);

		if (numero == 0)
			break;

		// Laço na funçõa main só soma os divisores do número
		for (i = 1; i <= numero; i++)
		{
			// printf("Valor de divisores[%lu]: %lu\n", i, divisores[i]);
			soma += divisores[i];
		}
		printf("%u\n", soma);
		soma = 0;

	}

}
// Função que calcula a soma dos divisores dos números de 1 até 10^6;
/*
void calcSomaDiv()
{
	unsigned long i, j;

	divisores[0] = 1;
	for (i = 2; i <= MAXSIZE; i++)
	{

		unsigned long limite = i / 2;

		for (j = 1; j <= limite; j++)
			if (i % j == 0)
				divisores[i - 1] += j;

		divisores[i - 1] += i;
	}
}
*/

// Função que calcula a soma dos divisores de 1 até 10^6 usando Crivo de Eratóstenes;

void calcSomaDivTest()
{
	unsigned long i, j, k;

	// A primeira posição é preenchida com 1, pois a soma dos divisores de 1 é
	// Igual a 1;
	divisores[1] = 1;

	for (i = 2; i <= MAXSIZE; i++)
	{
		// Se o número da posição atual ainda não foi visto, segue para o
		// Próximo laço;
		if (!foivisto[i])
		{

			// Pelo Crivo, o número na posição atual é um primo;
			// E os primos têm apenas o número 1 e ele mesmo como divisores;
			// Por isso, vetor divisores na posição atual recebe o número + 1;
			divisores[i] = i + 1;

			// printf("Soma dos divisores de %lu: %lu\n", i, divisores[i - 1]);

			// O laço seguinte verifica todos os múltiplos desse número até o
			// Limite estabelecido;
			for (j = i + i; j <= MAXSIZE; j+= i)
			{
				// Alguns números compartilham os mesmos múltiplos, nesse caso;
				// é feita uma verificação para saber se esse número já foi visto antes
				// E não fazer cálculos desnecessários;
				if (!foivisto[j])
				{
					// Caso ainda não tenha sido visto, número na posição atual
					// É marcado como visto, para evitar recalculos;
					foivisto[j] = true;

					// Os divisores de um número só vão até a sua metade;
					unsigned long limite = j / 2;

					// Verifica se um número é divisível;
					for (k = 1; k <= limite; k++)
						if (j % k == 0)
							divisores[j] += k;

					// Como o laço vai até apenas a metade do número sendo
					// Verificado, é preciso somar ao final o próprio número
					// Uma vez que um número é divisor de si próprio;
					divisores[j] += j;
					// printf("Soma dos divisores de %lu: %lu\n", j, divisores[j]);

				}
			}

		}
	}
}
