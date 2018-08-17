/*
  @autor: Malbolge;
  @data: 17/08/2018;
  @nome: Trigo no Tabuleiro;
*/

#include <stdio.h>
#include <math.h>

int main ()
{

  unsigned int casas, casos_teste, i;
  double resultado;

  scanf("%d", &casos_teste);

  for (i = 0; i < casos_teste; i++)
  {

    scanf("%d", &casas);

    resultado = pow(2, casas);

    //Valor truncado, pois no caso de valores 13++;
    //há discrepância de casas decimais;
    
    printf("%.lf kg\n", trunc(resultado/12000));

  }
}
