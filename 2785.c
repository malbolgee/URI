/*
	@autor: Malbolge;
	@data: 02/01/2019;
	@nome: Pirâmide;
*/

#include <stdio.h>
#include <string.h>

#define MAXSIZE 101
// Programação dinâmica;
int matriz[MAXSIZE][MAXSIZE];
int memoria[MAXSIZE][MAXSIZE];

int calcula(int linha, int coluna);
int mim(int a, int b);

void main ()
{

	unsigned short i, j;
	unsigned short tamMatriz;

	scanf("%hu", &tamMatriz);

	for (i = 1; i <= tamMatriz; ++i)
		for (j = 1; j <= tamMatriz; ++j)
			scanf("%d", &matriz[i][j]);

	// Preenche a matriz memória com -1 para sinalizar
	// Que o valor da célula ainda não foi calculado;
	memset(memoria, -1, sizeof(memoria));

	printf("%d\n", calcula(tamMatriz, 1));

}

int calcula(int linha, int coluna)
{

	int soma = 0;
	unsigned short i;

	// Se na posição [linha][coluna] da matriz memoria não tiver -1
	// Quer dizer que essa posição já foi calculada, retorne essa posição;
	if (memoria[linha][coluna] != -1)
		return memoria[linha][coluna];

	// Se for a primeira linha (caso base), então retorne a matriz memória
	// com o elemento da matriz nessa posição;
	if (linha == 1)
		return memoria[linha][coluna] = matriz[linha][coluna];

	// Recorrencia;
	for (i = 0; i < linha; ++i)
		soma += matriz[linha][coluna + i];

	return memoria[linha][coluna] = soma + mim(calcula(linha - 1, coluna), calcula(linha - 1, coluna + 1));

}

int mim(int a, int b)
{

	if (a < b)
		return a;
	else
		return b;

}
