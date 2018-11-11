/*
  @autor: Malbolge;
  @data: 11/11/2018;
  @nome: Rot13;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main ()
{

	unsigned short i;
	char texto[300] = { 0 };

	while (scanf(" %[^\n]", texto) != EOF)
	{

		i = 0;

		while (texto[i])
		{

			if (isalpha(texto[i]))
			{

				if (isupper(texto[i]))
				{

					if (texto[i] + 13 > 'Z')
						printf("%c", ('@' + (13 + texto[i] - 'Z')));
					else
						printf("%c", texto[i] + 13);

				}
				else
				{

					if (texto[i] + 13 > 'z')
						printf("%c", (96 + (13 + texto[i] - 'z')));
					else
						printf("%c", texto[i] + 13);

				}

			}
			else
				printf("%c", texto[i]);

			i++;

		}

		printf("\n");
		memset(texto, 0, sizeof(texto));

	}

}
