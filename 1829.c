/*
	@autor: Malbolge;
	@data: 25/12/2018;
	@nome: Jogo do Maior Número;
*/

#include <stdio.h>
#include <math.h>

#define E 2.71828182846
#define M_PI 3.14159265358979323846
#define PEDRO 1
#define LUCAS 0

void main ()
{


	char operacao;
	unsigned short i, casos;
	long long numA, numB, numC;
	unsigned qtsPedrosWins, qtsLucasWins;

	scanf("%hu", &casos);
	char ganhador[casos];
	qtsLucasWins = qtsPedrosWins = 0;

	for (i = 0; i < casos; ++i)
	{

		scanf("%lld%c%lld", &numA, &operacao, &numB);
		scanf("%lld%c", &numC, &operacao);

		if ((double)numC / E > numA && numC > numB)
			qtsPedrosWins++, ganhador[i] = 1;
		else if (numB * log(numA) < log(2 * M_PI) / 2.0f + (numC + (1 / 2.0f)) * log(numC) - numC) // Fórmula de Stirling
			qtsPedrosWins++, ganhador[i] = 1;
		else
			qtsLucasWins++, ganhador[i] = 0;

	}

	if (qtsPedrosWins > qtsLucasWins)
		printf("Campeao: Pedro!\n");
	else if (qtsPedrosWins < qtsLucasWins)
		printf("Campeao: Lucas!\n");
	else
		printf("A competicao determinou empatada!\n");

	for (i = 0; i < casos; ++i)
		if (ganhador[i])
			printf("Rodada #%hu: Pedro foi o vencedor\n", i + 1);
		else
			printf("Rodada #%hu: Lucas foi o vencedor\n", i + 1);

}
