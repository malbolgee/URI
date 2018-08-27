#include <stdio.h>
#include <string.h>

void main (void)
{

    char numero1[34], numero2[34];
    unsigned short contador = 0;
    unsigned short i, j, sequencias = 0, posicao;
    unsigned short caso = 0;
    unsigned short aux = 0;


    while (scanf("%s %s", numero1, numero2) != EOF)
    {
      unsigned short tamNum1 = strlen(numero1), tamNum2 = strlen(numero2);
      printf("Valor do tamanho de da String 1: %d\n", tamNum1);
      i = 0;
      while (numero2[i])
      {
        j = 0;
        while (numero1[j])
        {

          if (numero1[j] == numero2[i])
          {

            contador++;
            printf("Valor atual de contador: %d\n", contador);
            printf("Valor atual de i: %d\n", i);
            printf("Valor atual de j: %d\n", j);
            i++;
            j++;
            if (contador == tamNum1)
            {
              sequencias++;
              printf("Valor autal de sequencias: %d\n", sequencias);
              contador = 0;
            }

          }

        }

        //printf("Valor atual de contador: %d\n", contador);
        //printf("Valor atual de sequencias: %d\n", sequencias);
      }
    }
}
