/*
	@autor: Malbolge;
	@data: 05/05/2019;
	@nome: WERTYU;
*/

#include <stdio.h>
#include <string.h>

void main ()
{
	
	unsigned i, j;
	char string[1000];
	char *keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

	while (fgets(string, 1000, stdin) != NULL)
	{

		int tam = strlen(string);
		for (i = 0; i < tam; ++i)
			for (j = 0; j < 48; ++j)
				if (string[i] == keyboard[j])
				{

					printf("%c", keyboard[j - 1]);
					break;

				}
				else if (string[i] == ' ')
				{

					printf(" ");
					break;

				}
				else if (string[i] == '\n')
				{

					printf("\n");
					break;
					
				}

	}

}