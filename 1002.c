/*
  @autor: Malbolge;
  @data: 17/07/2018;
  @nome: Área do Círculo;
*/

#include <stdio.h>

float main (){

double area, pi, raio;
pi = 3.14159;

scanf("%lf", &raio);

area = pi*raio*raio;
printf("A=%.4lf\n", area);

}
