/*
	@autor: Malbolge;
	@data: 14/08/2018;
	@nome: LEDS;
*/


#include <stdio.h>
#include <string.h>

int main ()
{

	unsigned short numero, i, soma, j;
	char leds[102];

	short vetor[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	scanf("%hd", &numero);

	for (j = 0; j < numero; j++)
	{
		soma = 0;
		scanf("%s", leds);

		for (i = 0; i < strlen(leds); i++)
			soma += vetor[(int)leds[i]-48];

		printf("%d leds\n", soma);
	}
}