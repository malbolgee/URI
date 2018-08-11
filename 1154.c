#include <stdio.h>


int main ()
{

  int n, i, cont = 0;
  float resultado = 0;


  do{

    scanf("%d", &n);
    if ( n < 0)
    {

      break;

    }


    resultado += n;
    cont++;


  //printf("Contador atual: %d\n", cont);
  //printf("resultado atual: %f\n", resultado);
  }while (n > 0);

  //printf("%d\n", n);
  //printf("%f\n", resultado);
  //printf("%d\n", cont);
  printf("%.2f\n", resultado/cont);

}
