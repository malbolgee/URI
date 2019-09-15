/*
    @autor: Malbolge;
    @data: 14/09/2019;
    @nome: Futebol;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

int diffn[MAXSIZE];

void print_d(int n);
char scanff(int *);
int compare(int *, int *);

int main(int argc, char **argv)
{

	int n, g, i;
	int s, r, x, k;

	while (~scanf("%d %d%*c", &n, &g))
	{

		int ans = 0;

		for (i = k = 0; i < n; ++i)
		{

			scanff(&s);
			scanff(&r);

			x = s - r;	
			if (x == 0)
			{

				if (g > 0)
					ans += 3, --g;
				else
					++ans;
				
			}
			else if (x < 0)
				diffn[k++] = x;
			else
				ans += 3;

		}

		qsort(diffn, k, sizeof(int), compare);

        i = 0;
        while (g > 0 && i < k)
        {

            if (g - (-(diffn[i] - 1)) >= 0)
                g -= (-(diffn[i] - 1)), ans += 3;
            else if (g - (-(diffn[i] - 1)) < 0)
                if (diffn[i] + g == 0)
                    ++ans, g = -1;
            
            ++i;

        }

		print_d(ans);
		putchar_unlocked('\n');

	}

	return 0;

}

int compare(int *a, int *b)
{

	return *b - *a;

}

inline char scanff(int *a)
{

	register char c = 0;
	*a = 0;
	c = getchar_unlocked();

	while (c >= 48)
    	*a = *a * 10 + (c - '0'), c = getchar_unlocked();

    return c;

}

inline void print_d(int n) 
{

	int i = 10;
	char output_buffer[10];
	do{

		output_buffer[--i] = (n % 10) + '0';
		n /= 10;

	}while(n);

	do
	{
		putchar_unlocked(output_buffer[i]);

	}while(++i < 10);

}