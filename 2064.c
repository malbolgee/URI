/*
	@autor: Malbolge;
	@data: 06/01/2019;
	@nome: Prant e a Indecisão;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define MAXSIZE 300
#define MAXSIZES 100100

int qts[MAXSIZE] = { 0 };
char fim[MAXSIZES];
char atual[100100];
_Bool favoritas[MAXSIZES] = { false };

int qtsFavoritas();

void main ()
{

	unsigned i;
	unsigned k, m, n;
	char string[MAXSIZES], a, b;
	unsigned maiorQtsLetrasFavoritas, tmp;

	scanf("%u %u %u", &k, &m, &n);

	scanf("%s", string);

	// Se for uma letra favorita, o vetor de favoritas irá
	// marcar a posição da letra como favorita;
	for (i = 0; i < k; ++i)
		favoritas[string[i]] = true;

	scanf("%s", string);

	// faz a contagem da quantidade de cada letra do nome do
	// Cachorro;
	for (i = 0; i < m; ++i)
		qts[string[i]]++;

	// as strings atual e fim salvarão, respectivamente,
	// A string formada após as trocas de caracteres e a string
	// que tem a maior quantidade de caracteres favoritos;
	// Mas ambos começam iguais;
	for (i = 'a'; i <= 'z'; ++i)
		atual[i] = fim[i] = i;

	maiorQtsLetrasFavoritas = qtsFavoritas();

	while (n--)
	{

		scanf(" %c %c", &a, &b);

		// Faz as trocas de caracteres;
		for (i = 'a'; i <= 'z'; ++i)
		{

			if (atual[i] == a)
				atual[i] = b;
			else if (atual[i] == b)
				atual[i] = a;

		}

		tmp = qtsFavoritas();

		// Se a quantidade de letras favoritas após as trocas
		// For maior do que a quantidade de letras favoritas
		// antes da troca, então a string atual se torna a string
		// final;
		if (tmp > maiorQtsLetrasFavoritas)
		{

			maiorQtsLetrasFavoritas = tmp;
			for (i = 'a'; i <= 'z'; ++i)
				fim[i] = atual[i];

		}

	}

	printf("%d\n", maiorQtsLetrasFavoritas);
	for (i = 0; i < m; ++i)
		printf("%c", fim[string[i]]);

	printf("\n");

}

// Verifica a quantiadde de letras favoritas na string;
int qtsFavoritas()
{

	int i;
	int retorno = 0;

	// Se na string atual tem uma letra que é favorita
	// Some a quantidade dela em uma variável;
	for (i = 'a'; i <= 'z'; ++i)
		retorno += qts[i] * favoritas[atual[i]];

	return retorno;

}
