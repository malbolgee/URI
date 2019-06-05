/*
	@autor: Malbolge;
	@data: 04/06/2019;
	@nome: Loop Musical;
*/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int main(int argc, char **argv)
{

	int n, i, ans;
	int ondas[10050];

	while (scanf("%d", &n), n)
	{

		for (i = 0; i < n; ++i)
			scanf("%d", &ondas[i]);

		ans = 0;
		for (i = 1; i < n - 1; ++i)
			if ((ondas[i] - ondas[i - 1]) * (ondas[i] - ondas[i + 1]) > 0)
				++ans;

		if ((ondas[0] - ondas[n - 1]) * (ondas[0] - ondas[1]) > 0)
			++ans;
		if ((ondas[n - 1] - ondas[n - 2]) * (ondas[n - 1] - ondas[0]) > 0)
			++ans;

		printf("%d\n", ans);

	}

	return 0;

}