/*
	@autor: Malbolge;
	@data: 24/10/2018;
	@nome: Fase;
*/

#include <stdio.h>

void ordena(unsigned short *, unsigned short);

void main ()
{
	unsigned short maiorNota, numClassificados;
	unsigned short numCompetidores, i;
	short qtsDevemPassar, maior, j;

	// Leitura de variáveis
	scanf("%hu", &numCompetidores);
	scanf("%hu", &qtsDevemPassar);

	// Declaração de um vetor de tamanho proporcional ao número de competidores;
	short pontos[numCompetidores];

	// Enchimento do vetor;
	for (i = 0; i < numCompetidores; i++)
		scanf("%hd", &pontos[i]);

	// Ordena o vetor em ordem decrescente;
	ordena(pontos, numCompetidores);

	j = qtsDevemPassar;
	i = qtsDevemPassar - 1;
	// Como as maiores notas estão no inicio do vetor; quem tem que passar
	// Já está classificado, por isso, numClassificados já tem o valor de quantos
	// Devem passar;
	numClassificados = qtsDevemPassar;
	// Agora, quem tiver a nota igual ao último classificado também deve passar;
	// Verifico o vetor enquanto essa condição ocorrer;
	while (pontos[j++] == pontos[i])
		numClassificados++;

	printf("%hu\n", numClassificados);
}

// Função que ordena um vetor em ordem descrecente;
void ordena(unsigned short *vetor, unsigned short tam)
{

	short i = 1, j;
	unsigned short pivo;


	while (i < tam)
	{

		j = i - 1;
		pivo = vetor[i];

		while (j >= 0 && vetor[j] < pivo)
		{

			vetor[j + 1] = vetor[j];
			j--;

		}

		vetor[j + 1] = pivo;
		i++;

	}

}
