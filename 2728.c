/*
	@autor: Malbolge;
	@data: 31/12/2018;
	@nome: Grace Hopper, a Vovó do Cobol;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool grace(char *);

void main ()
{

	char string[70];

	while (scanf(" %[^\n]", string) != EOF)
	{

		if (grace(string))
			printf("GRACE HOPPER\n");
		else
			printf("BUG\n");

	}

}

bool grace(char *string)
{

	char *tmp;
	unsigned short i, j;
	char _string[6] = { 0 };
	unsigned short tamString;
	short ascii[] = {0, -13, 0, -3};
	// cobol

	tmp = strtok(string, "-");
	tamString = strlen(tmp);

	j = i = 0;
	if (tolower(tmp[0]) == 'c')
		_string[j++] = tmp[0];
	else if (tolower(tmp[tamString - 1]) == 'c')
		_string[j++] = tmp[tamString - 1];

	do
	{

		tmp = strtok('\0', "-");

		if (tmp)
		{

			tamString = strlen(tmp);

			if (tolower(tmp[0]) == ('o' + ascii[i]))
				_string[j++] = tmp[0];
			else if (tolower(tmp[tamString - 1]) == ('o' + ascii[i]))
				_string[j++] = tmp[tamString - 1];

			i++;

		}

	} while (tmp);

	if (strcasecmp(_string, "cobol") == 0)
		return true;
	else
		return false;

}
