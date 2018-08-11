/*
	@autor: Malbolge;
	@data: 09/08/2018;
	@nome: Vitõria e a Indecisão;
*/

#include <stdio.h>
#include <string.h>

int main ()
{

	unsigned short int intervalo;
	char cursos[100];

	scanf("%hd", &intervalo);

	while (intervalo != 0)
	{

		scanf("%s", cursos);
		intervalo--;
	}
	printf("Ciencia da Computacao\n");
}
