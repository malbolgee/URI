/*
	@autor: Malbolge;
	@data: 11/02/2019;
	@nome: Diferença Fácil Entre Datas;
*/

#include <stdio.h>

#define true 1
#define false 0

void main ()
{

	unsigned short i;
	unsigned short ans;
	unsigned short a, b, c, d;

	scanf("%hu %hu", &a, &b);
	scanf("%hu %hu", &c, &d);

	ans = 0;
	if (b == d)
		ans = c - a;
	else
	{

		for (i = b; i <= d; ++i)
		{

			if (i == 4 || i == 6 || i == 9 || i == 11)
			{

				if (i == b)
					ans += 30 - a;
				else if (i == d)
					ans += c;
				else
					ans += 30;

			}
			else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			{

				if (i == b)
					ans += 31 - a;
				else if (i == d)
					ans += c;
				else
					ans += 31;

			}
			else
			{

				if (i == b)
					ans += 28 - a;
				else if (i == d)
					ans += c;
				else
					ans += 28;

			}

		}

	}

	printf("%hu\n", ans);

}
