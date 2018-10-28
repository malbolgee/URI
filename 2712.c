/*
	@autor: Malbolge;
	@data: 25/10/2018;
	@nome: Rodízio Veicular;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{

	char dias[10];

} semana;

bool verificaPlaca(char *);
char rodizio(char *);

void main ()
{
	semana dia[5] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY" };
	unsigned short casos, i;
	char placa[110];

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %s", placa);

		if (verificaPlaca(placa))
			printf("%s\n", dia[rodizio(placa)].dias);
		else
			printf("FAILURE\n");

		memset(placa, 0, sizeof(placa));
	}

}
bool verificaPlaca(char *placa)
{

	unsigned short i = 0;
	unsigned short contador;

	if (strlen(placa) != 8)
		return false;

	if (placa[3] != '-')
		return false;

	i = 0;
	contador = 0;
	while (placa[i] != '-')
	{
		if (isalpha(placa[i]) && isupper(placa[i]))
			contador++;
		i++;
	}
	if (contador != 3)
		return false;

	i++;
	while (placa[i])
		if (!isdigit(placa[i++]))
			return false;

	return true;

}

char rodizio(char *placa)
{

	unsigned short i;
	i = strlen(placa) - 1;

	switch (placa[i]) {
		case '1': case '2':
			return 0;
		case '3': case '4':
			return 1;
		case '5': case '6':
			return 2;
		case '7': case '8':
			return 3;
		case '9': case '0':
			return 4;
	}

}
