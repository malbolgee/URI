/*
	@autor: Malbolge;
	@data: 11/10/2018;
	@nome: Xenlongão;
*/

#include <stdio.h>
#include <math.h>

void main ()
{

	unsigned numero;
	unsigned casos;

	scanf("%u", &casos);

	while (casos--)
	{

		scanf("%u", &numero);
		// A questão pede que sejam excluídos os números
		// Que têm número par de divisores;
		// Podemos achar a quantidade de divisores de um números
		// Com a decomposição em fatores primos;
		// Podemos encontrar a quantidade de divisores pares
		// com uma técnica de soma e multiplicação dos expoentes dos
		// Fatores. Mais informações neste link https://bit.ly/2CaFK9K;
		// Um número é par quando todos os expoentes são ímpares.
		// Então esse número precisa ser um quadrado perfeito Para
		// Que o número de divisores seja par.
		// No final das contas, devemos excluir todos os números
		// Que são quadrados perfeitos. A quantidade de números que são
		// Quadrados pefeitos em um intervalo [1...N] é exatamente
		// a raiz quadrada de N;

		printf("%u\n",  (unsigned)(numero - (floor(sqrt(numero)))));

	}
}
