/*
	@autor: Malbolge;
	@data: 18/01/2019;
	@nome: Protocolo TCP/IP;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 1005

unsigned pacotes[MAXSIZE];

void main ()
{

	unsigned inicio;
	unsigned num, i;
	char string[30];

	while (scanf("%u%*c", &inicio) != EOF)
	{

		memset(pacotes, 0, sizeof(pacotes));
		while (true)
		{

			scanf(" %[^\n^\r]", string);
			if (strcmp(string, "0") == 0)
				break;

			sscanf(&string[8], "%d%*c", &num);
			pacotes[num]++;

		}

		for (i = 1; i <= 999; ++i)
		{

			if (pacotes[i] > 1)
				while (pacotes[i]--)
					printf("Package %03u\n", i);
			else if (pacotes[i] == 1)
				printf("Package %03u\n", i);

		}

		printf("\n");

	}

}
