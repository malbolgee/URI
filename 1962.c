/*
	@autor: Malbolge;
	@data: 15/08/2018;
	@nome: Há Muito, Muito Tempo Atrás;
*/

#include <stdio.h>
int main ()
{
	unsigned numero, entrada;
	int resultado, i;

	scanf("%d", &numero);
	for (i = 0; i < numero; i++)
	{
		scanf("%d", &entrada);

		resultado = entrada - 2015;

		if (resultado > 0)
			printf("%d A.C.\n", resultado + 1);
		else if (resultado < 0)
			printf("%d D.C.\n", -resultado);
		else
			printf("1 A.C.\n");
		
	}
}