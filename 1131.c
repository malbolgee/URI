#include <stdio.h>

int main () {

  int inter, gremio, opcao;
  int vinter = 0, vgremio = 0, cont = 0, empate = 0;

do
{
  opcao = 0;

    scanf("%d %d", &inter, &gremio);

    if (inter > gremio)
    {

      vinter++;

    }
    else
    {
      if (inter == gremio)
      {

        empate++;

      }
      else
      {

        vgremio++;

      }
    }
    cont++;
    printf("Novo grenal (1-sim 2-nao)\n");
    scanf("%d", &opcao);


  } while (opcao != 2);

  printf("%d grenais\n", cont);
  printf("Inter:%d\n", vinter);
  printf("Gremio:%d\n", vgremio);
  printf("Empates:%d\n", empate);

  if (vinter > vgremio)
  {

    printf("Inter venceu mais\n");

  }
  else
  {

    if (empate > vgremio && empate > vinter)
    {

      printf("Nao houve vencedor\n");

    }
    else
    {

      printf("Gremio venceu mais\n");

    }
  }
  }
