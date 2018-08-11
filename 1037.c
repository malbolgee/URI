/*
	@autor: Malbolge;
	@data: 22/07/2018;
	@nome: Intervalo;
*/

#include <stdio.h>

int main ()
{

float a = 0;
scanf("%f", &a);

if (a >= 0 && a <= 25)
  printf("Intervalo [0,25]\n");
else if (a > 25 && a <= 50)
  printf("Intervalo (25,50]\n");
else if (a > 50 && a <= 75)
  printf("Intervalo (50,75]\n");
else if (a > 75 && a <= 100)
  printf("Intervalo (75,100]\n");
else
  printf("Fora de intervalo\n");

}
