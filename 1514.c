/*
	@autor: Malbolge;
	@data: 05/06/2019;
	@nome: Competição;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

unsigned s_grid[101];
unsigned p_grid[101];

int main(int argc, char **argv)
{

	unsigned n, m;
	unsigned i, j, tmp;
	_Bool flag1, flag2, flag3, flag4;

	while (scanf("%u %u", &n, &m), n && m)
	{

		flag1 = flag2 = flag3 = flag4 = true;
		memset(p_grid, 0, sizeof(p_grid));
		memset(s_grid, 0, sizeof(s_grid));

		for (i = 0; i < n; ++i)
			for (j = 0; j < m; ++j)
			{
				
				scanf("%u", &tmp);
				s_grid[i] += tmp;
				p_grid[j] += tmp;

			}

		for (i = 0; i < n; ++i)
		{

			if (s_grid[i] == m)
				flag1 = false;
			
			if (s_grid[i] == 0)
				flag4 = false;
		
		}

		for (i = 0; i < m; ++i)
		{

			if (p_grid[i] == 0)
				flag2 = false;
			
			if (p_grid[i] == n)
				flag3 =false;

		}

		printf("%u\n", flag1 + flag2 + flag3 + flag4);

	}

	return 0;

}