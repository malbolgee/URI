/*
	@autor: Malbolge;
	@data: 30/10/2018;
	@nome: Dígito Mais Frequente;
*/

#include <stdio.h>
#include <string.h>

short charToInt(char numero);

void main ()
{
	char numero, numerosStr[1110] = { 0 };
	short numeros[1110] = { 0 };
	short i, posiMaior, maior;

	while (scanf(" %s", numerosStr) != EOF)
	{

		for (i = 0; numerosStr[i]; i++)
			numeros[charToInt(numerosStr[i])]++;

		posiMaior = 0;
		maior = numeros[0];
		for (i = 1; i < 1110; i++)
			if (numeros[i] >= maior && posiMaior < i)
			{
				posiMaior = i;
				maior = numeros[i];
			}

		printf("%hu\n", posiMaior);
		memset(numeros, 0, sizeof(numeros));
		memset(numerosStr, 0, sizeof(numerosStr));

	}
}

short charToInt(char numero)
{

	return (numero - 48);

}
