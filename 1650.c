/*
	@autor: Malbolge;
	@data: 19/05/2019;
	@nome: Pintura Preto e Branco;
*/

#include <stdio.h>

int main (int argc, char **argv)
{

	unsigned n, m, c;

	while (scanf("%u %u %u", &n, &m, &c), n || m || c)
		printf("%u\n", ((n - 7) * (m - 7) + c) / 2);

	return 0;

}