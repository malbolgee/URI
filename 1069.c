/*
	@autor: Malbolge;
	@data: 11/02/2019;
	@nome: Diamantes e Areia;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned short us;

us diamonds(char *);

void main ()
{

	us n;
	int lixo;
	char string[1005];

	scanf("%hu", &n);
	scanf("%d", &lixo);

	while (n--)
	{

		fgets(string, 1005, stdin);
		string[strlen(string) - 1] = '\0';
		printf("%hu\n", diamonds(string));
		memset(string, 0, sizeof(string));

 	}
}

us diamonds(char *string)
{

	short x = 0;
	us qtsDiamonds = 0;

	us i, j;
	for (i = 0; string[i]; ++i)
	{

		if (string[i] != '<')
			continue;

		for (j = i + 1; string[j]; ++j)
			if (string[j] == '>')
			{

				++qtsDiamonds;
				string[i] = 'x';
				string[j] = 'x';
				break;

			}

	}

	return qtsDiamonds;

}
