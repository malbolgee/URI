/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Esfera;
*/

#include <stdio.h>

float main (){

  double pi, volume;
  unsigned short int raio;
  pi = 3.14159;
  scanf("%hd", &raio);

  volume = (4/3.0)*pi*pow(raio, 3);

  printf("VOLUME = %.3lf\n", volume);

}
