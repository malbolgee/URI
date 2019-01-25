/*
	@autor: Malbolge;
	@data: 23/01/2019;
	@nome: Notas da Prova;
*/

#include <stdio.h>

void main ()
{

	unsigned short n;

	scanf("%hu", &n);

	if (n == 0)
		printf("E\n");
	else if (n >= 1 && n <= 35)
		printf("D\n");
	else if (n >= 36 && n <= 60)
		printf("C\n");
	else if (n >= 61 && n <= 85)
		printf("B\n");
	else
		printf("A\n");

}
