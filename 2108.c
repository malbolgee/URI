/*
	@autor: Malbolge;
	@data: 21/09/2018;
	@nome: Contando Caracters;
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main ()
{

	char texto[101], maiorPalavra[101], temp[101];
	short qtsCarac[101], maior = 0;
	unsigned short caracteres, i, j, k;
	

	while (true)
	{

		scanf(" %[^\n]", texto);


		if (strcmp(texto, "0") == 0)
			break;

		i = 0;
		j = 0;
		k = 0;
		caracteres = 0;

		// Enquanto a string não chegar ao caractere nulo;
		while (texto[i])
		{	

			while (true)
			{
				
				if (texto[i] == ' ' || texto[i] == '\0')
					break;
				// Enquanto os caracteres da string forem diferentes de espaços
				// Ou não for o final da string, passa esse(s) caractere para a 
				// tring temporária e conta quantos caracteres foram passados;
				temp[j++] = texto[i++];
				caracteres++;

			}

			// Caractere nulo na posição atual da string temporária para marcar o seu final;
			temp[j] = '\0';
			
			// Passa a quantidade de caractere(s) encontrado(s) na(s) palavra(s) da string;
			qtsCarac[k++] = caracteres;	

			// Se a quantidade de caractere(s) encontrada(s) na palvra atual
			// For maior ou igual à quantidade de caractere(s) encontrada(s) na palavra anterior
			// Então a palavra atual é maior qua a palavra anterior;
			if (caracteres >= maior)
			{
				maior = caracteres;
				strcpy(maiorPalavra, temp);
			}

			// 'i' só incrementa fora do laço se na posição atual tem um espaço;
			if (texto[i] == ' ')
				i++;


			j = 0;
			caracteres = 0;

		}

		for (int l = 0; l < k; l++)
		{
			if (l != 0)
				printf("-");
			printf("%hd", qtsCarac[l]);
		}

		printf("\n");
		memset(qtsCarac, 0, sizeof(qtsCarac));
	}
	printf("\n");
	printf("The biggest word: %s\n", maiorPalavra);
}