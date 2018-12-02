/*
	@autor: Malbolge;
	@data: 01/12/2018;
	@nome: Dentista;
*/

typedef struct consulta{

	unsigned iniConsulta;
	unsigned fimConsulta;

} consulta;

#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b);

void main ()
{

	unsigned qtsConsultas;
	unsigned qtsConsultasMax = 1;
	unsigned i, j;

	scanf("%u", &qtsConsultas);

	// Vetor de struct;
	consulta agenda[qtsConsultas];

	for (i = 0; i < qtsConsultas; i++)
		scanf("%u %u", &agenda[i].iniConsulta, &agenda[i].fimConsulta);

	j = 0;
	// Ordena o vetor de struct em ordem crescente pelo camo "fimConsulta";
	qsort(agenda, qtsConsultas, sizeof(consulta), compara);

	// Se um inicio de consulta for maior ou igual ao fim de consulta, quer dizer
	// Que os horários não se sobrepoem;
	// 'j' recebe o valor de i e se torna a nova consulta atual;
	for (i = 1; i < qtsConsultas; i++)
	{

		if (agenda[i].iniConsulta >= agenda[j].fimConsulta)
		{

			qtsConsultasMax++;
			j = i;

		}

	}

	printf("%u\n", qtsConsultasMax);

}

// Função de comparação para o qsort;
int compara(const void *a, const void *b)
{

	if ((*(struct consulta*)a).fimConsulta == (*(struct consulta*)b).fimConsulta)
		return 0;
	else if ((*(struct consulta*)a).fimConsulta > (*(struct consulta*)b).fimConsulta)
		return 1;
	else
		return -1;


}
