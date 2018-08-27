/*
  @autor: Malbolge;
  @data: 26/08/2018;
  @nome: Reservatório de Mel;
*/

#include <stdio.h>
#include <math.h>

void main (void)
{
  float area = 0, diametro, volume, altura;


  while (scanf("%f %f", &volume, &diametro) != EOF)
  {


    printf("ALTURA = %.2f\n", volume/(3.14*(pow((diametro/2.0), 2))));
    printf("AREA = %.2f\n", 3.14*(pow((diametro/2.0), 2)));

  }
}
