/*
	@autor: Malbolge;
	@data: 30/12/2018;
	@nome: Getline Three - Calçados;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void main ()
{

	char lixo;
	short parada;
	char string[10000];
	unsigned short caso;
	bool japrintou = false;
	unsigned short numCalcado;
	unsigned char genero, tamCalcado;
	unsigned short qtsMatches, qtsF, qtsM;

	caso = 0;
	while (true)
	{

		parada = scanf("%hu", &numCalcado);

		// Gambiarra para resolver o problema da quebra de linha após o último caso
		if (parada == EOF)
			break;

		if (parada != EOF && japrintou)
			printf("\n");

		//
		qtsMatches = qtsF = qtsM = 0;
		while (true)
		{

			scanf("%hhu%*[ ]%c", &tamCalcado, &genero);
			scanf("%c", &lixo);

			if (tamCalcado == numCalcado)
				qtsMatches++;

			if (genero == 'F' && tamCalcado == numCalcado)
				qtsF++;
			else if (genero == 'M' && tamCalcado == numCalcado)
				qtsM++;

			if (lixo == '\n')
				break;

		}

		printf("Caso %hu:\nPares Iguais: %hu\nF: %hu\nM: %hu\n", ++caso, qtsMatches, qtsF, qtsM);
		japrintou = true;

	}

}
