/*
	@autor: Malbolge;
	@data: 07/09/2018;
	@nome: Detector de Falhas;
*/

#include <stdio.h>
#include <stdbool.h>

void main (void)
{

	unsigned numeroAtual = 1, numeroAnt = 0, numero = 0;
	bool temfalha = false;

	while (scanf("%u", &numeroAtual) != EOF)
	{
		
		
		if ((!temfalha) && (numeroAtual < numeroAnt))
		{
			temfalha = true;
			numero = numeroAnt;
			
		}

		numeroAnt = numeroAtual;
		
	}

	if (temfalha)
		printf("%u\n", numero + 1);
	else
		printf("%u\n", numeroAtual + 1);

}