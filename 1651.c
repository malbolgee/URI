/*
	@autor: Malbolge;
	@data: 20/05/2019;
	@nome: Cilindro;
*/

#include <stdio.h>
#include <math.h>

#define true 1
#define false 0
#define __PI (acos(0.0) * 4)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

double volume(double r, double h);

int main (int argc, char **argv)
{

	unsigned w, h;
	while (scanf("%u %u", &w, &h), w || h)
	{

		double r1 = MIN(w / 2.0, h / (__PI + 2));
		double res = volume(r1, w);
		double r2 = w / __PI;
		res = MAX(res, volume(r2, h - 2 * r2));
		printf("%.3f\n", res);

	}

	return 0;

}

double volume(double r, double h)
{

	return r * r * __PI / 2 * h;

}