/*
	@autor: Malbolge;
	@data: 31/10/2018;
	@nome: Frequencia na Aula;
*/

#include <stdio.h>

void qSortInterno(unsigned *registros, int inicio, int fim);
void qSortI(unsigned *registros, int tam);

void main ()
{

	unsigned qtsRegistros;
	int i, presencas;

	scanf("%u", &qtsRegistros);

	unsigned registros[qtsRegistros];

	for (i = 0; i < qtsRegistros; i++)
		scanf("%u", &registros[i]);

	qSortI(registros, qtsRegistros);

	presencas = 0;
	for (i = 0; i < qtsRegistros; i++)
		if (registros[i] != registros[i - 1])
			presencas++;

	printf("%u\n", presencas);

}

void qSortInterno(unsigned *registros, int inicio, int fim)
{

	unsigned pivo;
	unsigned temp;
	int i, j;

	if (fim - inicio > 0)
	{
		if (inicio < fim)
		{
			i = inicio;
			j = fim;
			pivo = registros[(i + j) / 2];

			do
			{

				while (registros[i] < pivo)
					i++;
				while (registros[j] > pivo)
					j--;

				if (i <= j)
				{

					temp = registros[i];
					registros[i] = registros[j];
					registros[j] = temp;
					i++; j--;

				}

			} while (i <= j);

			qSortInterno(registros, inicio, j);
			qSortInterno(registros, i, fim);
		}
	}
}

void qSortI(unsigned *registros, int tam)
{

	qSortInterno(registros, 0, tam - 1);

}
