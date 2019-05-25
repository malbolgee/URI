/*
	@autor: Malbolge;
	@data: 25/05/2019;
	@nome: Brincando com Conjuntos;
*/

#include <stdio.h>

#define true 1
#define false 0

typedef long long unsigned llu;

llu grid[10010];

void scanff(int *a);
unsigned csb(llu x);
void print_dln(int n);

int main (int argc, char **argv)
{

	int t, n, i, j, k;
	
	scanff(&t);
	while (t--)
	{

		scanff(&n);
		for (i = 1; i <= n; ++i)
		{

			grid[i] = 0;
			scanff(&j);
			while (j--)
				scanff(&k), grid[i] |= (1LL << k);

		}

		scanff(&n);
		while (n--)
		{

			scanff(&k), scanff(&i), scanff(&j);
			if (k == 1)
				print_dln(csb(grid[i] & grid[j]));
			else
				print_dln(csb(grid[i] | grid[j]));

		}

	}

	return 0;

}

unsigned csb(llu x)
{

	unsigned ans = 0;
	while (x)
		ans += x & 1, x >>= 1;

	return ans;

}

inline void scanff(int *a)
{

    register char c = 0;
    *a = 0;
	c = getchar_unlocked();
    while (c >= 48)
        *a = *a * 10 + (c - '0'), c = getchar_unlocked();

}

inline void print_dln(int n) 
{

	char i = 10;
	char output_buffer[11];
	output_buffer[10] = '\n';
	do{

		output_buffer[--i] = (n % 10) + '0', n /= 10;

	}while(n);

	do{

		putchar_unlocked(output_buffer[i]);

	}while(++i < 11);

}