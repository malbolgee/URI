/*
	@autor: Malbolge;
	@data: 02/06/2019;
	@nome: Medianas;
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{

	double u, v, w;
	double nan = -1.000;

	while (scanf("%lf %lf %lf", &u, &v, &w) != EOF)
	{

		double s = (u + v + w) / 2;
		double ans = s * (s - u) * (s - v) * (s - w);
		printf("%.3lf\n", ans > 0 ? 4.0F * sqrt(ans) / 3.0F : nan);

	}

	return 0;

}