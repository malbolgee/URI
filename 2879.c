/*
	@autor: Malbolge;
	@data: 03/06/2019;
	@nome: Desvendando Monty Hall
*/

#include <stdio.h>

int main(int argc, char **argv)
{


	unsigned n, m, ans = 0;
	scanf("%u", &n);
	while (n--)
	{

		scanf("%u", &m);
		if (m != 1)
			++ans;

	}

	printf("%u\n", ans);

	return 0;

}