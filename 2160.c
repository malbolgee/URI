/*
	@autor: Malbolge;
	@data: 11/09/2018;
	@nome: Nome no Formulário;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	char texto[500];

	scanf("%[^\n\r]", texto);

	if (strlen(texto) < 81)
		printf("YES\n");
	else
		printf("NO\n");

}	