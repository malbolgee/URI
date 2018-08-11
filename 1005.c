/*
  @autor: Malbolge;
  @data: 19/07/2018;
  @nome: Média I;
*/

#include <stdio.h>

double main (){

  double a, b, media;

  scanf("%lf", &a);
  scanf("%lf", &b);

  media = (a*3.5 + b*7.5)/11;

  printf("MEDIA = %.5lf\n", media);

}
