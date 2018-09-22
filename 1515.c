/*
	@autor: Malbolge;
	@data: 22/09/2018;
	@nome: Hello Galaxy;
*/


typedef struct{

	char planetas[51];
	unsigned short anosGastos;

} string;

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	unsigned short i, aux, ano, anos;
	unsigned short menor, posiMenor, casos;

	while (true)
	{
		scanf(" %hu", &casos);

		if (casos == 0)
			break;

		aux = casos;
		// Vetor do tipo string;
		string nomePlaneta[aux];

		i = 0;
		while (casos--)
		{

			scanf(" %s %hu %hu", nomePlaneta[i].planetas, &ano, &anos);
			// O ano de chegada menos a quantidade de anos que levou para chegar
			// Nos dá o ano original em que a mensagem foi enviada;
			// Usaremos esse resultado para comparação mais adiante;
			nomePlaneta[i].anosGastos = (ano - anos);
			i++;

		}

		menor = nomePlaneta[0].anosGastos;
		posiMenor = 0;

		for (i = 1; i < aux; i++)
		{
			// Se quem está na posição atual é menor do que o 'menor'
			// Então eu salvo esse novo menor e sua posição;
			if (nomePlaneta[i].anosGastos < menor)
			{	
				menor = nomePlaneta[i].anosGastos;
				posiMenor = i;

			}
		}

		printf("%s\n", nomePlaneta[posiMenor].planetas);		
	}
}