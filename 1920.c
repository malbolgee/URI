/*
	@autor: Malbolge;
	@data: 31/01/2019;
	@nome: Fonte dos Desejos;
*/

#include <stdio.h>

#define true 1
#define false 0
#define POW(a) a * a
#define C chiquinha.dentro
#define CC chiquinha.borda
#define P popis.dentro
#define PP popis.borda
#define T printf("TESTE\n")

typedef struct pontos{

	int dentro;
	int borda;

} pontos;

void count(int, int, int, pontos *);

void main ()
{

	int px, py, i;
	int r1, r2, cx, cy;

	unsigned short qtsMoedas;

	while (scanf("%hu", &qtsMoedas), qtsMoedas)
	{

		scanf("%d %d %d %d", &cx, &cy, &r1, &r2);

		r1 *= r1;
		r2 *= r2;
		pontos chiquinha = { 0 }, popis = { 0 };
		for (i = 0; i < qtsMoedas; ++i)
		{

			scanf("%d %d", &px, &py);
			count(POW((px - cx)) + POW((py - cy)), r1, r2, &chiquinha);
			scanf("%d %d", &px, &py);
			count(POW((px - cx)) + POW((py - cy)), r1, r2, &popis);

		}

		printf("%s\n", C > P ? "C > P" : C < P ? "P > C" : CC > PP ? "C > P" : PP > CC ? "P > C" : "C = P");

	}

}

void count(int dist, int raio1, int raio2, pontos *tmp)
{


	if (dist < raio1)
		tmp->dentro++;
	else if (dist >= raio1 && dist <= raio2)
		tmp->borda++;

}
