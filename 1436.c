/*
	@autor: Malbolge;
	@data: 05/10/2018;
	@nome: Jogo do Tijolo;
*/

#include <stdio.h>

void main ()
{

	unsigned short casos, qtsCasos = 0;
	unsigned short i, qtsIdades;
	float mediana = 0;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &qtsIdades);

		short idades[qtsIdades];

		for (i = 0; i < qtsIdades; i++)
			scanf("%hd", &idades[i]);

		// Se a quantidade de elementos do conjunto for par;
		// Então a mediana é o elemento central;
		// Se não, a mediana é a média entre os dois elementros centrais;
		if (qtsIdades % 2 != 0)
			mediana = idades[(0 + (qtsIdades - 1)) / 2];
		else
			mediana = (idades[qtsIdades/2] + idades[(qtsIdades/2) + 1]) / 2;

		printf("Case %hu: %.f\n", ++qtsCasos, mediana);

	}

}
