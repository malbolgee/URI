/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Consumo;
*/

#include <stdio.h>

float main (){

int distancia;
float gasosa, consumo;

scanf("%d", &distancia);
scanf("%f", &gasosa);

consumo = distancia/gasosa;

printf("%.3f km/l\n", consumo);

}
