/*
	@autor: Malbolge;
	@data: 24/12/2018;
	@nome: Pedágio;
*/

#include <stdio.h>

void main ()
{

	unsigned short comprimento, distPedagios;
	unsigned short custoKm, custoPedagio;

	scanf("%hu %hu", &comprimento, &distPedagios);
	scanf("%hu %hu", &custoKm, &custoPedagio);

	printf("%u\n", (comprimento * custoKm) + ((comprimento / distPedagios) * custoPedagio));

}
