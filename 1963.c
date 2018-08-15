/*
	@autor: Malbolge;
	@data: 15/08/2018;
	@nome: O Filme;
*/

#include <stdio.h>

int main ()
{

	float valorIinicial, ValorFinal, resultado;
	scanf("%f %f", &valorIinicial, &ValorFinal);

	if (valorIinicial == ValorFinal)
		printf("0.00%%\n");
	else
	{
		resultado = ((ValorFinal*100.0)/valorIinicial)-100;
		printf("%.2f%%\n", resultado);
	}

}