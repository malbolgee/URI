/*
	@autor: Malbolge;
	@data: 07/01/2019;
	@nome: Então é Natal!;
*/

#include <stdio.h>
#include <string.h>

unsigned n;
#define MAXSIZE 40100

char* entaoehnatal(char *);

void main ()
{

	char string[MAXSIZE] = { 0 };

	scanf("%u", &n);

	if (n == 1)
		printf("Entao eh Natal!\n");
	else
		printf("%s\n", entaoehnatal(string));

}

char* entaoehnatal(char *string)
{


	char string_[n];

	memset(string_, 'a', sizeof(string_));
	strcat(string, "Ent");

	strcat(strcat(strncat(string, string_, n), "o"), " eh ");
	strncat(strcat(string, "N"), string_, n);
	strcat(strncat(strcat(string, "t"), string_, n), "l!");

	return string;

}
