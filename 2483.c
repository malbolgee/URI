/*
	@autor: Malbolge;
	@data: 23/12/2018;
	@nome: Feliz Nataaal!;
*/

#include <stdio.h>
#include <string.h>

char* feliznatal(unsigned short, char *);

void main ()
{

	char _string[] = "Feliz natal!";
	char string[10100] = { 0 };
	unsigned short index;

	scanf("%hu", &index);

	if (index == 1)
		printf("%s\n", _string);
	else
		printf("%s\n", feliznatal(index, string));

}

char* feliznatal(unsigned short index, char *string)
{

	char __string[index];
	memset(__string, 'a', sizeof(__string));

	// Série de concatenações para montar a string final;
	return strcat(strncat(strcat(string, "Feliz nat"), __string, index), "l!");

}
