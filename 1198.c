/*
  @autor: Malbolge;
  @data 15/08/2018;
  @nome: Bravo Guerreiro Hashmat;
*/

#include <stdio.h>

int main ()
{

  long long int exercito1, exercito2;

  while (scanf("%lld %lld", &exercito1, &exercito2) != EOF)
  {
    if (exercito2 > exercito1)
      printf("%lld\n", exercito2-exercito1);
    else
      printf("%lld\n", exercito1-exercito2);
  }
}
