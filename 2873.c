/*
	@autor: Malbolge;
	@data: 14/10/2018;
	@nome: Pirâmide;
*/

#include <stdio.h>
#include <stdbool.h>

void main ()
{

	// A - Largura da Pirâmide (Comprimento da base);
	// B - Comprimento da sombra da pirâmide;
	// C - Altura de uma haste qualquer;
	// D - Comprimento da sombra da haste;

	double larguraPiramide, comprimentoSombraPiramide;
	double alturaHaste, comprimentoSombraHaste;
	double alturaPiramide;

	while (true)
	{

		scanf("%lf %lf %lf %lf", &larguraPiramide, &comprimentoSombraPiramide, &alturaHaste, &comprimentoSombraHaste);

		if (larguraPiramide == 0 && comprimentoSombraPiramide == 0 && alturaHaste == 0 && comprimentoSombraHaste == 0)
			break;

		// A haste forma uma sombra assim como a pirâmide, o comprimento dessa sombra é nos dado;
		// Também é fornecido a altura da haste;
		// Usando o teorema de semelhança de triângulos de Thales, podemos encontrar a altura da Pirâmide
		// usando a relação VH/HA = PB/BC, onde VH é a altura da piramide, HA é o comprimmento da sombra da pirâmide
		// Mais metade do comprimento da base, PB é alura da haste e BC é o comprimento da sombra da haste;
		// Mais detalhes nesse link: https://bit.ly/2IXbkZI;

		alturaPiramide = (alturaHaste / comprimentoSombraHaste) * ((larguraPiramide / 2) + comprimentoSombraPiramide);

		printf("%.5lf\n", alturaPiramide);

	}

}
