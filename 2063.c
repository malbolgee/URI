/*
	@autor: Malbolge;
	@data: 13/10/2018;
	@nome: Caçando Digletts;
*/

#include <stdio.h>

int mdc(int, int);

void main ()
{

	int i;
	int qtsBuracos;
	int resposta = 1;
	int tempo, buraco;

	scanf("%d", &qtsBuracos);

	short buracos[105];

	for (i = 1; i <= qtsBuracos; i++)
		scanf("%hd", &buracos[i]);

	for (i = 1; i <= qtsBuracos; i++)
	{

		tempo = 1;
		buraco = buracos[i];

		while (buraco != i)
		{

			tempo++;
			buraco = buracos[buraco];

		}

		resposta = (resposta / mdc(resposta, tempo)) * tempo;

	}

	printf("%d\n", resposta);

}

int mdc(int a, int b)
{

	int resto = a % b;

	while (resto != 0)
	{

		a = b;
		b = resto;
		resto = a % b;

	}

	return b;

}
