/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Cartas;
*/

#include <stdio.h>
#include <stdbool.h>

bool verificaOrdCresc(short *, unsigned short);
bool verificaOrdDecre(short *, unsigned short);

void main ()
{

	short cartas[5], i;

	for (i = 0; i < 5; i++)
		scanf("%hd", &cartas[i]);

	if (verificaOrdCresc(cartas, 5))
		printf("C\n");
	else if (verificaOrdDecre(cartas, 5))
		printf("D\n");
	else
		printf("N\n");


}

bool verificaOrdCresc(short *vetor, unsigned short tam)
{

	short i;
	bool ordenado = true;

	for (i = 1; i < tam; i++)
		if (vetor[i] < vetor[i - 1] && ordenado == true)
			ordenado = false;

	if (ordenado)
		return true;
	else
		return false;
}

bool verificaOrdDecre(short *vetor, unsigned short tam)
{

	short i;
	bool ordenado = true;

	for (i = 1; i < tam; i++)
		if (vetor[i] > vetor[i - 1] && ordenado == true)
			ordenado = false;

	if (ordenado)
		return true;
	else
		return false;

}
