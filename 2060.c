/*
	@autor: Malbolge;
	@data: 17/09/2018;
	@nome: Desafio de Bino;
*/


#include <stdio.h>

void main ()
{

	unsigned short casos, multi2 = 0, multi3 = 0, multi4 = 0, multi5 = 0;
	unsigned i;

	scanf("%hu", &casos);

	int numeros[casos];

	for (i = 0; i < casos; i++)
		scanf("%d", &numeros[i]);

	for (i = 0; i < casos; i++)
	{

		if (numeros[i] % 2 == 0)
			multi2++;
		if (numeros[i] % 3 == 0)
			multi3++;
		if (numeros[i] % 4 == 0)
			multi4++;
		if (numeros[i] % 5 == 0)
			multi5++;

	}

	printf("%hd Multiplo(s) de 2\n", multi2);
	printf("%hd Multiplo(s) de 3\n", multi3);
	printf("%hd Multiplo(s) de 4\n", multi4);
	printf("%hd Multiplo(s) de 5\n", multi5);

}