/*
	@autor: Malbolge;
	@data: 27/04/2019;
	@nome: Bolhas e Baldes;
*/

#include <stdio.h>
#include <string.h>

int merge(int *a, int n, int *inv);

void main ()
{

	int i, n, inv;
	while(scanf("%d", &n), n)
	{

	    int a[n];
	    for(i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		inv = 0;
	    merge(a, n, &inv);
	    printf("%s\n", inv & 1 ? "Marcelo" : "Carlos");

	}

}
int merge(int *a, int n, int *inv)
{

	if (n > 1)
	{

		merge(a, n / 2, inv);
		merge(a + (n / 2), (n + 1) / 2, inv);
		int i = 0, k;
		int j = n / 2;
		int b[n];

		for (k = 0; k < n; ++k)
		{

			if (i < n / 2 && j < n)
			{

				if (a[i] < a[j])
					b[k] = a[i], ++i;
				else if (a[j] < a[i])
					b[k] = a[j], ++j, *inv += (n / 2) - i;
				else
					b[k] = a[i], ++i;
				
			}
			else if (i < n / 2)
				b[k] = a[i], ++i;
			else
				b[k] = a[j], ++j;

		}

		memcpy(a, b, sizeof(int) * n);
	
	}

}
