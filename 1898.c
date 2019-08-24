/*
	@autor: Malbolge;
	@data: 23/09/2018;
	@nome: Soma de Propina;
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

void solve();
char cpf[15], prop[30];
char string1[70], string2[70];

int main(int argc, char **argv)
{

	scanf("%s %s", string1, string2);
	solve();

	return 0;

}

void solve()
{

	double v, x;
	int i, j, c;

	i = j = c = 0;
    for (; string1[i] && c < 11; ++i)
		if (isdigit(string1[i]))	
			cpf[j++] = string1[i], ++c;

	c = j = 0;
    for (; string1[i]; ++i)
		if (isdigit(string1[i]))
			prop[j++] = string1[i];
		else if (string1[i] == '.')
		{

			prop[j++] = string1[i++];
            for (; string1[i] && c < 2; ++i)
				if (isdigit(string1[i]))
					prop[j++] = string1[i], ++c;
				
			break;
					
		}

	prop[j] = 0;
	
	if (j != 0)
		sscanf(prop, "%lf", &v);

	memset(prop, 0, sizeof(prop));

	i = j = c = 0;
    for (; string2[i]; ++i)
		if (isdigit(string2[i]))
			prop[j++] = string2[i];
		else if (string2[i] == '.')
		{

			prop[j++] = string2[i++];

            for (; string2[i] && c < 2; ++i)
				if (isdigit(string2[i]))
					prop[j++] = string2[i], ++c;

			break;

		}

	prop[j] = 0;

	if (j != 0)
		sscanf(prop, "%lf", &x), v += x;

	printf("cpf %s\n", cpf);
	printf("%.2lf\n", v);

}