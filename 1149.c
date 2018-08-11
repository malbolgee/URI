/*
  @autor: Malbolge;
  @data: 06/08/2018;
  @nome: Somando Inteiros Consecutivos;
*/

#include "stdio.h"


int main ()
{

	int a ,n, soma = 0;

	scanf("%d", &a);

	do
	{

		scanf("%d", &n);

	} while(n <= 0);

	for(unsigned short i = 0; i < n; i++)
		soma += a + i;

	printf("%d\n", soma);

}
