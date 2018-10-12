/*
	@autor: Malbolge;
	@data: 12/10/2018;
	@nome: Escolha Difícil;
*/

#include <stdio.h>

void main ()
{

	unsigned short frangoDisponivel, bifeDisponivel, massaDisponivel;
	unsigned short frangoRequisitado, bifeRequisitado, massaRequisitada;
	short resultadoFrango, resultadoBife, resultadoMassa;

	scanf("%hu %hu %hu", &frangoDisponivel, &bifeDisponivel, &massaDisponivel);
	scanf("%hu %hu %hu", &frangoRequisitado, &bifeRequisitado, &massaRequisitada);

	resultadoFrango = frangoDisponivel - frangoRequisitado;

	if (resultadoFrango > 0)
		resultadoFrango = 0;

	resultadoBife = bifeDisponivel - bifeRequisitado;


	if (resultadoBife > 0)
		resultadoBife = 0;

	resultadoMassa = massaDisponivel - massaRequisitada;


	if (resultadoMassa > 0)
		resultadoMassa = 0;

	printf("%hd\n", -(resultadoFrango + resultadoBife + resultadoMassa));

}
