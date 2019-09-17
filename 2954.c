/*
    @autor: Malbolge;
    @data: 17/09/2019;
    @nome: O Jogo;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 100100

int main(int argc, char **argv)
{

	char *ptr;
	int n, m, ans, tam;
	char string[MAXSIZE];

	scanf("%d", &n);

	while (n--)
	{

		scanf("%*c%[^\n]", string);
		ptr = strtok(string, " ,.");
		tam = strlen(ptr);
		ans = m = 0;

		if (strcasecmp(ptr, "jogo") == 0 || strcasecmp(ptr, "perdi") == 0)
		{

			ans += tam;

			if (ans > m)
				m = ans;

			ans = 0;

		}
		else
		{

			ans += tam;

			if (ans > m)
				m = ans;

		}

		do
		{

			ptr = strtok(NULL, " ,.");

			if (ptr)
			{	

				tam = strlen(ptr);

				if (strcasecmp(ptr, "jogo") == 0 || strcasecmp(ptr, "perdi") == 0)
				{

					ans += tam;

					if (ans > m)
						m = ans;

					ans = 0;

				}
				else
				{

					ans += tam;

					if (ans > m)
						m = ans;

				}

			}

		} while (ptr);

		printf("%d\n", m);

	}

	return 0;

}