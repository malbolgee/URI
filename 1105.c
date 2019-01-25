/*
	@autor: Malbolge;
	@data: 24/01/2019;
	@nome: Sub-prime;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 25

void main ()
{

	_Bool flag;
	unsigned short i;
	int saldoBancos[MAXSIZE], deb;
	unsigned short numBancos, numDeb;

	while (scanf("%hu %hu", &numBancos, &numDeb), numBancos && numDeb)
	{

		for (i = 1; i <= numBancos; ++i)
			scanf("%d", &saldoBancos[i]);

		while (numDeb--)
		{

			unsigned short devedor, credor;
			scanf("%hu %hu %d", &devedor, &credor, &deb);
			saldoBancos[devedor] -= deb;
			saldoBancos[credor] += deb;

		}

		flag = false;
		for (i = 1; i <= numBancos && flag == false; ++i)
			if (saldoBancos[i] < 0)
				flag = true;

		printf("%s\n", flag ? "N" : "S");

	}

}
