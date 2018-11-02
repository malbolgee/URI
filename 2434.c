/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Saldo do Vovô;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	unsigned short numDias, i;
	int saldoInicial, menorSaldo, movimentacao;
	int saldoAtual = 0;

	scanf("%hu %d", &numDias, &saldoInicial);

	menorSaldo = saldoInicial;
	for (i = 0; i < numDias; i++)
	{

		scanf("%d", &movimentacao);
		saldoInicial += movimentacao;

		if (saldoInicial < menorSaldo)
			menorSaldo = saldoInicial;

	}

	printf("%d\n", menorSaldo);

}
