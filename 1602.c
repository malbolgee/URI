/*
	@autor: Malbolge;
	@data: 07/10/2018;
	@nome: Hiperprimos;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 2000001

// Definição de variáveis globais
// Os vetores aqui declarados poderão ser vistos por todas as
// Funções do programa;
// Dessa forma, a função calcHiperPrimes() poderá modificar os vetores
// E a função main poderá vizualizar essas modificações;
bool ehPrimo[MAXSIZE];
unsigned divisores[MAXSIZE], qtsHiperPrimes[MAXSIZE];

void calcHiperPrimes();

void main ()
{

	unsigned numero;

	calcHiperPrimes();

	// O algoritmo é rápido porque o vetor com os Hiperprimos
	// Já está cheio e eu o acesso pelo índice
	// Sem necessidade de mais cálculos adicionais;
	while (scanf("%u", &numero) != EOF)
		printf("%u\n", qtsHiperPrimes[numero]);

}

void calcHiperPrimes()
{

	unsigned i, j;
	unsigned numDivisores, tam;

	// Preenche o bloco de memória do vetor 'ehPrimo' com 'true';
	// Esse vetor guarda a informação de se o número da posição é primo ou não;
	// Inicialmente todos são primos até que se prove o contrário;
	memset(ehPrimo, true, sizeof(ehPrimo));
	// Preenche o bloco de memória do vetor 'divisores';
	memset(divisores, 0, sizeof(divisores));


	// Mescla do Crivo de Eratóstenes com um método de fatoração
	// Dos fatores primos de um número para, ao mesmo tempo, descobrir
	// Se um número é primo e a quantidade de divisores que um número tem;
	for (i = 2; i < MAXSIZE; i++)
	{
		// Se na posição atual houver um primo;
		// Note que o valor da posição ehPrimo[j] é modificada no laço a seguir;
		// Quando o índice 'i' alcançar o valor de 'j', se a posição em 'i' contiver 'false';
		// A condição não é apreciada e o laço incrementa sem fazer nenhum cálculo;
		// Uma vez que essa informação na posição de 'ehPrimo' nos diz que esse número é um multiplo;
		if (ehPrimo[i])
		{

			// Se o número na posição atual é um primo, então ele tem 2 divisores;
			// 1 e ele mesmo;
			divisores[i] = 2;
			// Aqui começa o Crivo de Eratóstenes;
			// Esse laço descarta todos os multiplos do número que está na posição 'i'
			// Uma vez que se um número é multiplo de outro, ele é divisível por esse mesmo
			// número e não mais apenas por 1 e ele mesmo;
			// Podemos nos assegurar de que esse número não é primo;
			for (j = i + i; j < MAXSIZE; j += i)
			{

				ehPrimo[j] = false;

				numDivisores = 0;
				tam = j;

				// Esse laço calcula a quantidade de divisores de um
				// número pelo método da reciprocidade;
				// Para mais informações visite o link https://bit.ly/2zVErd4;
				while (tam % i == 0)
				{

					tam /= i;
					numDivisores++;

				}

				if (divisores[j] == 0)
					divisores[j] = numDivisores + 1;
				else
					divisores[j] *= (numDivisores + 1);


			}

		}

	}

	qtsHiperPrimes[1] = 0;
	// Esse laço encherá o vetor resposta com a quantidade de
	// Hiperprimos na posição;
	for (i = 2; i <= MAXSIZE; i++)
	{
		// qtsHiperPrimes na posição atual recebe o que tinha na posição
		// anterior para acumular, se necessário;
		qtsHiperPrimes[i] = qtsHiperPrimes[i - 1];
		// o vetor 'ehPrimo' salvou quem era primo na posição atual;
		// se o valor de 'divisores' na posição atual devolver um valor
		// 'false' para 'ehPrimo', significa que na posição atual não tem um número
		// Que tenha um número primo de divisores;
		// Então 'qtsHiperPrimes' na posição autal não acumula;
		if (ehPrimo[divisores[i]])
			qtsHiperPrimes[i]++;

	}
}
