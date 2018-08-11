#include <stdio.h>

int main () {

  float nota, resultado = 0;
  int i = 0, cont = 0;

  while (cont != 2)
  {
    scanf("%f", &nota);

    if (nota < 0 || nota > 10)
    {

      printf("nota invalida\n");

    }
    else
    {

      resultado += nota;
      cont++;

    }
  }

  printf("media = %.2f\n", resultado/2);
  
}
