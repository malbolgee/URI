/*
	@autor: Malbolge;
	@data: 18/09/2018;
	@nome: Chirrin Chirrion;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char coisa[150];

} string;

short procuraCoisa(string vet[], char str[], short);
void ordena(string vet[], short tam);

void main ()
{

	unsigned short casos, utilizacoes, aux;
	short i;
	short resultado;
	char comando[10], objeto[20];


	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%hu", &utilizacoes);

		aux = utilizacoes;
		string objetos[aux];

		i = 0;
		while(utilizacoes--)
		{

			scanf(" %s %s", objeto, comando);

			if (strcmp(comando, "chirrin") == 0)
			{	
				// Caso o comando seja "chirrin"
				// Procura na struct se o objeto já existe dentro dela;
				// Uma vez que esse comando só funciona caso Tausfo ainda não tenha o objeto;
				// Se não existir, o coloca na posição atual e incrementa o 'i';
				if (procuraCoisa(objetos, objeto, i) == -1)
					strcpy(objetos[i++].coisa, objeto);
	
			}
			// Se o comando for "chirrion"
			// Quer dizer que não quero mais esse objeto;
			// O procuro no struct para ver se o tenho;
			// Caso o tenha, substituo a string da posição do objeto por uma string qualquer "aaaaaaa";
			else if (strcmp(comando, "chirrion") == 0)
			{

				resultado = procuraCoisa(objetos, objeto, i);
				if(resultado != -1)
					strcpy(objetos[resultado].coisa, "aaaaaaa");
				
			}

			// Reseta a struct para a proxima iteração;
			memset(objeto, 0, sizeof(objeto));
		}

		ordena(objetos, i); // Ordenaçõa por ordem alfabética;

		printf("TOTAL\n");
		// Impressão final dos elementos do struct
		// A posição que contiver a string "aaaaaaa" não será impressa;
		for (int k = 0; k < i; k++)
			if (strcmp(objetos[k].coisa, "aaaaaaa") != 0)
				printf("%s\n", objetos[k].coisa);

	}

}

short procuraCoisa(string vet[], char str[], short tam)
{

	short i;

	// Caso encontre um exemploar da string 'comando' dentro do struct, retorna o índice
	// Dessa forma, conteúdo contido nessa posição pode ser alterado;
	// Se não encontrar repetição retorna -1;
	for (i = tam - 1; i >= 0; i--)
		if (strcmp(vet[i].coisa, str) == 0)
			return i;

	return -1;

}

void ordena(string vet[], short tam)
{

	short i, j, posicaoMenor;
	string temp;

	for (i = 0; i < tam - 1; i++)
	{
		posicaoMenor = i;

		// Salva a posição do menor elemento em relação ao i e o coloca em seu lugar;
		for (j = i + 1; j < tam; j++)
			if (strcmp(vet[j].coisa, vet[posicaoMenor].coisa) < 0)
				posicaoMenor = j;

		temp = vet[posicaoMenor];
		vet[posicaoMenor] = vet[i];
		vet[i] = temp;

	}

}
