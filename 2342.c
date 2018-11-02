/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Overflow;
*/

#include <stdio.h>

void main ()
{

	unsigned numMax;
	unsigned numA, numB;
	char operacao;

	scanf("%u", &numMax);
	scanf("%u %c %u", &numA, &operacao, &numB);

	if (operacao == '+')
		if (numA + numB > numMax)
			printf("OVERFLOW\n");
		else
			printf("OK\n");
	else
		if (numA * numB > numMax)
			printf("OVERFLOW\n");
		else
			printf("OK\n");


}
