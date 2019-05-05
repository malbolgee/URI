/*
	@autor: Mablolge;
	@data: 05/05/2019;
	@nome: Soma de Dois Quadrados;
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0

void main ()
{

	int n;
	int x, y;
	_Bool ans;
	unsigned s;

	while (scanf("%d", &n) != EOF)
	{

		x = 0;
		y = sqrt(n);
		ans = false;
	
		while (y >= x)
		{
			
			s = x * x + y * y;
			if (s == n)
			{

				ans = true;
				break;

			}
			else if (s < n)
				++x;
			else
				--y;

		}

		printf("%s\n", ans ? "YES" : "NO");

	}

}