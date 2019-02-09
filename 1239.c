/*
	@autor: Malbolge;
	@data: 04/02/2019;
	@nome: Atalhos Bloggo;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 150
#define SET memset(string, 0, sizeof(string))

void bloggo(char *);
char string[MAXSIZE];

void main ()
{

	char lixo;

	while (fgets(string, 150, stdin) != NULL)
		bloggo(string), SET;

}

void bloggo(char *texto)
{

	unsigned short i;
	_Bool italico, negrito;

	italico = negrito = false;
	for (i = 0; texto[i]; ++i)
	{

		if (texto[i] == '_' && italico == false)
		{
			printf("<i>"), italico = true;
			continue;
		}
		if (texto[i] == '_' && italico == true)
		{
			printf("</i>"), italico = false;
			continue;
		}
		if (texto[i] == '*' && negrito == false)
		{
			printf("<b>"), negrito = true;
			continue;
		}
		if (texto[i] == '*' && negrito == true)
		{
			printf("</b>"), negrito = false;
			continue;
		}
		if (texto[i] != '_' || texto[i] != '*')
			printf("%c", texto[i]);

	}

}
