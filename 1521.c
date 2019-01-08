/*
	@autor: Malbolge;
	@data: 08/01/2019;
	@nome: O Culpado;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 60

unsigned short alunos[MAXSIZE];

void main ()
{

	unsigned short i;
	unsigned short lista;

	while (true)
	{

		scanf("%hu", &lista);

		if (lista == 0)
			break;

		for (i = 1; i <= lista; ++i)
			scanf("%hu", &alunos[i]);

		scanf("%hu", &i);

		while (alunos[i] != i)
			i = alunos[i];

		printf("%hu\n", i);

	}

}
