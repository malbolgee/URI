/*
	@autor: Malbolge;
	@data: 06/05/2019;
	@nome: Jornada nas Estrelas;
*/

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 1000010

typedef long long unsigned llu;

char seen[MAXSIZE];

void main ()
{
	
	int i;
	unsigned n;	
	scanf("%u", &n);

	llu tot = 0;
	unsigned sitios[n];
	for (int i = 0; i < n; ++i)
		scanf("%u", &sitios[i]), tot += sitios[i];

	i = 0;
	llu ans = 0;
	while (i >= 0 && i < n)
	{

		if (!seen[i])
			++ans;

		seen[i] = true;

		if (sitios[i] & 1)
			--tot, --sitios[i++];
		else
		{

			if (sitios[i])
				--tot, --sitios[i];

			--i;

		}

	}

	printf("%llu %llu\n", ans, tot);

}