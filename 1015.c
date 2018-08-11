/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Distância Entre Dois Pontos;
*/

#include <stdio.h>
#include <math.h>

float main (){

double x1, y1, x2, y2, distancia;
scanf("%lf %lf", &x1, &y1);
scanf("%lf %lf", &x2, &y2);


distancia = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

printf("%.4lf\n", distancia);

}
