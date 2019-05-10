/*
	@autor: Malbolge;
	@data: 08/07/2019;
	@nome: URI;
*/

#include <stdio.h>

#define ture 1
#define false 0

void main ()
{

	unsigned i;
	unsigned numero;
	unsigned num[3];
	unsigned ui, ri, li;

	while (scanf("%u", &numero), numero)
	{

		ui = ri = li = 0;
		while (numero--)
		{

			int pos = 0;
			int maior = 0;
			for (i = 0; i < 3; ++i)
			{

				scanf("%u", &num[i]);
				if (num[i] > maior)
					maior = num[i], pos = i;

			}

			if (!(num[0] & (num[0] - 1)))
			{

				++ui;
				if (pos == 0)
					++ui;

			}
			if (!(num[1] & (num[1] - 1)))
			{
				
				++ri;
				if (pos == 1)
					++ri;

			}
			if (!(num[2] & (num[2] - 1)))
			{

				++li;
				if (pos == 2)
					++li;

			}

		}


		if (ui > ri && ui > li)
			printf("Uilton\n");
		else if (ri > ui && ri > li)
			printf("Rita\n");
		else if (li > ui && li > ri)
			printf("Ingred\n");
		else if (li == ui || li == ri || ui == ri)
			printf("URI\n");

	}

}