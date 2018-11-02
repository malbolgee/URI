/*
	@autor: Malbolge;
	@data: 02/11/2018;
	@nome: Letras;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char palavra[1100];

} dicionario;

unsigned short verificaLetra(dicionario *, unsigned short tam, char letra);

void main ()
{

	char letra, texto[1100], *aux;
	dicionario palavra[1100];
	unsigned short i, j;
	double porcentagem;

	scanf("%c", &letra);
	scanf(" %[^\n]", texto);

	i = 0;
	aux = strtok(texto, " ");
	strcpy(palavra[i++].palavra, aux);

	do{

		aux = strtok('\0', " ");
		if (aux)
			strcpy(palavra[i++].palavra, aux);

	} while (aux);

	printf("%.1f\n", (verificaLetra(palavra, i, letra) * 100.0f) / i);

}

unsigned short verificaLetra(dicionario *palavra, unsigned short tam, char letra)
{

	unsigned short i, j;
	unsigned short qtsPalavras = 0;

	for (i = 0; i < tam; i++)
	{

		j = 0;
		while (palavra[i].palavra[j])
		{

			if (palavra[i].palavra[j] == letra)
			{

				qtsPalavras++;
				break;

			}

			j++;

		}

	}

	return qtsPalavras;

}
