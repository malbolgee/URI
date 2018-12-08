/*
	@autor: Malbolge;
	@data: 05/12/2018;
	@nome: Detetive Watson;
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct suspeito{

	unsigned short suspeito;
	unsigned short posicao;

} suspeito;


int compara(const void *a, const void *b);

void main ()
{


	unsigned short i;
	unsigned short qtsSuspeitos;


	while (true)
	{

		scanf("%hu", &qtsSuspeitos);

		if (qtsSuspeitos == 0)
			break;

		suspeito suspeitos[qtsSuspeitos];

		for (i = 0; i < qtsSuspeitos; i++)
		{
			scanf("%hu", &suspeitos[i].suspeito);
			suspeitos[i].posicao = i;
		}

		qsort(suspeitos, qtsSuspeitos, sizeof(suspeito), compara);

		printf("%hu\n", suspeitos[1].posicao + 1);

	}

}

int compara(const void *a, const void *b)
{


	if ((*(struct suspeito *)a).suspeito == (*(struct suspeito *)b).suspeito)
		return 0;
	else if ((*(struct suspeito *)a).suspeito > (*(struct suspeito *)b).suspeito)
		return -1;
	else
		return 1;


}
