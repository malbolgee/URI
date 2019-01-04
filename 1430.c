/*
	@autor: Malbolge;
	@data: 04/01/2019;
	@nome: Composição de Jingles;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 205

double notas[100] = { 0 };

void preencheNotas();
unsigned short autoTune(char *);
double compassCounter(char *tmp);

void main ()
{

	preencheNotas();
	char jingle[MAXSIZE] = { 0 };

	while (true)
	{

		scanf("%s", jingle);

		if (strcmp(jingle, "*") == 0)
			break;

		printf("%hu\n", autoTune(&jingle[1]));

	}
}

unsigned short autoTune(char *jingle)
{

	char *tmp;
	unsigned short compassosCorretos = 0;

	tmp = strtok(jingle, "/");

 	if (compassCounter(tmp) == 1)
		compassosCorretos++;

	do
	{

		tmp = strtok('\0', "/");

		if (tmp)
			if (compassCounter(tmp) == 1)
				compassosCorretos++;

	} while (tmp);

	return compassosCorretos;

}

double compassCounter(char *tmp)
{

	double soma = 0;
	unsigned short i;

	i = 0;

	while (tmp[i])
		soma += notas[tmp[i++]];

	return soma;

}
void preencheNotas()
{

	notas['W'] = 1.0;
	notas['H'] = 0.5;
	notas['Q'] = 0.25;
	notas['E'] = 0.125;
	notas['S'] = 0.0625;
	notas['T'] = 0.03125;
	notas['X'] = 0.015625;

}
