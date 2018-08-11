#include <stdio.h>
int media();


int main () {

  media();

}

int media () {

  int opcao = 0, cont = 0;
  float nota, resultado;

    resultado = 0;

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

  cont = 0;
  printf("media = %.2f\n", resultado/2);

  opcao = 0;

  do
  {
    printf("novo calculo (1-sim 2-nao)\n");
    scanf("%d", &opcao);

    if (opcao == 1)
    {

      media();

    }

  } while ((opcao != 1) && (opcao != 2));
  }
