/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Gasto de Combustível;
*/

#include <stdio.h>

float main (){

float consumo, tempo, velocidade, distancia;
double litros;
consumo = 12;

scanf("%f", &tempo);
scanf("%f", &velocidade);

distancia = tempo*velocidade;

litros = distancia/consumo;

printf("%.3lf\n", litros);

}
