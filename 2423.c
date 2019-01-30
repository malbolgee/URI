/*
	@autor: Malbolge;
	@data: 29/01/2019;
	@nome: Receita de Bolo;
*/

#include <stdio.h>
#define MIN(a, b) a < b ? a : b


void main ()
{

	int bolos;
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	n /= 2, m /= 3, k /= 5;
	printf("%d\n", MIN(n, (MIN(m, k))));

}
