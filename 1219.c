/*
	@autor: Malbolge;
	@data: 28/12/2018;
	@nome: Flores Colorida;
*/

#include <stdio.h>
#include <math.h>

#define MPI 3.1415926535897
double areaTriangulo, areaCirculoExterno, areaCirculoInterno;

void calcAreas(double, double, double);

void main ()
{

	double a, b, c;

	while (scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{

		calcAreas(a, b, c);

		printf("%.4lf %.4lf %.4lf\n", areaCirculoExterno, areaTriangulo, areaCirculoInterno);

	}

}

void calcAreas(double a, double b, double c)
{

	double raioCirculoInterno;
	double raioCirculoExterno, semiPerimetro;

	// http://www.mathopenref.com/trianglecircumcircle.html
	raioCirculoExterno = ((a * b * c) / sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c)));

	semiPerimetro = (a + b + c) / 2;
	// Fórmula de Herão
	areaTriangulo = sqrt(semiPerimetro * ((semiPerimetro - a) * (semiPerimetro - b) * (semiPerimetro - c)));

	raioCirculoInterno = areaTriangulo / semiPerimetro;
	areaCirculoExterno = (raioCirculoExterno * raioCirculoExterno * MPI) - areaTriangulo;
	areaCirculoInterno = (raioCirculoInterno * raioCirculoInterno) * MPI;
	areaTriangulo = areaTriangulo - areaCirculoInterno;

}
