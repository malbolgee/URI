/*
	@autor: Malbolge;
	@data: 22/09/2018;
	@nome: Frequência de Letras;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	short qtsAparicoes;
	short posicao;

} tipoQuantidade;


void ordenaInsercao(tipoQuantidade v[], unsigned short);

void main (void)
{

	unsigned short casos, contador = 0, i, j, k, maior;
	char texto[201];
	char cmp[] = "abcdefghijklmnopqrstuvwxyz";

	scanf("%hu", &casos);

	while (casos--)
	{
		// Vetor do tipoQuantidade;
		tipoQuantidade letras[26];

		scanf(" %[^\n]", texto);

		for (i = 0, k = 0; cmp[i]; i++, k++)
		{	
			// Compara cada letra do alfabeto com as letras da string de entrada;
			for (j = 0; texto[j]; j++)
				if (cmp[i] == texto[j] || cmp[i] == texto[j] - 32 || cmp[i] == texto[j] + 32)
					contador++;
			
			// Dessa forma posso dizer quantas vezes o caractere da posição apareceu;
			letras[k].posicao = i;
			letras[k].qtsAparicoes = contador;
			contador = 0;
		}

		// Ordeno o struct do maior para o menor;
		// Dessa forma, o caractere que mais apareceu sempre estará na primeira posição
		ordenaInsercao(letras, k);

		// Apenas os caracteres que têm uma quantidade maior ou igual a quantidade
		// Do caractere que mais apareceu serão impressos;
		for(i = 0; i < k; i++)
			if (letras[i].qtsAparicoes >= letras[0].qtsAparicoes)
				printf("%c", cmp[letras[i].posicao]);

		printf("\n");

	}
}

void ordenaInsercao(tipoQuantidade v[], unsigned short tamanho) 
{

    int i, j;
    tipoQuantidade pivot;

    for(j = 1; j < tamanho; j++ ) 
    {
    	i = j - 1;
    	pivot = v[j];

    	while((i >= 0) && (v[i].qtsAparicoes < pivot.qtsAparicoes)) 
      	{
      		v[i+1] = v[i];
      		i--;
      	}

      	v[i+1] = pivot;

    }
}