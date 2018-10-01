/*
	@autor: Malbolge;
	@data: 30/09/2018;
	@nome: Justificador;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct{

	char palavra[51];

} string;


void main ()
{

	unsigned short casos, maior;
	unsigned short i, aux, atual;
	
	// Leio 'casos' antes para entrar no laço;
	scanf("%hu\n", &casos);
	while (casos != 0)
	{

		// 'Aux' recebe a variável 'casos, pois 'casos' será modificada no laço;
		aux = casos;
		// Vetor de struct simulando um arraylist;
		string nomes[aux];

		i = 0;
		while (casos--)
			scanf(" %s", nomes[i++].palavra);

		maior = 0;
		// Acha o tamanho da maior string digitada;
		for(i = 0; i < aux; i++)
		{	
			atual = strlen(nomes[i].palavra);
			if (atual > maior)
				maior = atual;

		}
		// Todas as strings serão impressas com uma margem à esquerda
		// Que depende do tamanho da maior string;
		// a flag '*' antes da diretiva '%s' no printf
		// É uma forma de recuo dinâmico que o C me permite fazer;
		for (i = 0; i < aux; i++)
			printf("%*s\n", maior, nomes[i].palavra);

		scanf("%hu", &casos);
		// A questão pede uma quebra de linha na última string
		// Da última entrada, por isso essa construção
		// Com a leitura de casos ao final novamente;
		if (casos != 0)
			printf("\n");

	}	

}