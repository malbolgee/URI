/*
	@autor: Malbolge;
	@data: 30/09/2018;
	@nome: Planejando a Energia;
*/

#include <stdio.h>
#include <math.h>	

double pa(double, double, unsigned short);

void main ()
{

	unsigned short casos;
	unsigned short anoIni, anoFim;
 	double consumoIni, consumoFim, resultado, fracao;
 	int inteiro;

 	scanf("%hu", &casos);

	while (casos--)
	{

		// O problema da questão é mais a impressão do que o cálculo em si;
		// Para imprimir um número decimal com vírgula é necessário uma gambiarra;
		// Primeiro separar as partes inteira e fracionaria em variáveis diferentes;
		// Depois multiplicar a parte fracionária por 100 para que esta também fique inteira;
		// No fim, imprimir os dois resultados separados por uma vírgula no próprio printf;
		// Atenção para os 0's à esquerda na parte que era para ser a fracionária;
		scanf("%hu %lf %hu %lf", &anoIni, &consumoIni, &anoFim, &consumoFim);

		resultado = pa(consumoIni, consumoFim, (anoFim - anoIni));

		inteiro = resultado;

		fracao = trunc((resultado - inteiro)*100);

		printf("%d,%02.f\n", inteiro, fracao);



	}
}

double pa(double a1, double an, unsigned short posicao)
{
	// Simples caso de PA;
	return ((an - a1) / posicao); 

}