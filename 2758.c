/*
	@autor: Malbolge;
	@data: 05/01/2019;
	@nome: Entrada e Saída com Números Reais;
*/

#include <stdio.h>

void main ()
{

	float a, b;
	double c, d;

	scanf("%f %f", &a, &b);
	scanf("%lf %lf", &c, &d);

	printf("A = %f, B = %f\n", a, b); // 7
	printf("C = %lf, D = %lf\n", c, d); // 8
	printf("A = %.1f, B = %.1f\n", a, b); // 9
	printf("C = %.1lf, D = %.1lf\n", c, d); // 10
	printf("A = %.2f, B = %.2f\n", a, b); // 11
	printf("C = %.2lf, D = %.2lf\n", c, d); // 12
	printf("A = %.3f, B = %.3f\n", a, b); // 13
	printf("C = %.3lf, D = %.3lf\n", c, d); // 14
	printf("A = %.3E, B = %.3E\n", a, b); // 15
	printf("C = %.3E, D = %.3E\n", c, d); // 16
	printf("A = %.0f, B = %.0f\n", a, b); // 17
	printf("C = %.0lf, D = %.0lf\n", c, d); // 18

}
