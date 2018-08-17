/*
  @autor: Malbolge;
  @data: 17/08/2018;
  @nome: Acima da Média;
*/

#include <stdio.h>

int main ()
{

  unsigned casos_teste, i, j, nota, contador = 0;
  float media = 0;
  unsigned short num_alunos;

  //A média é variada;

  scanf("%d", &casos_teste);

  for (i = 0; i < casos_teste; i++)
  {

    scanf("%hd", &num_alunos);
    
    short notas_alun[num_alunos];

    for (j = 0; j < num_alunos; j++)
      scanf("%hd", &notas_alun[j]);

    for (j = 0; j < num_alunos; j++)
      media += notas_alun[j];

    media = media/num_alunos;

    for (j = 0; j < num_alunos; j++)
      if (notas_alun[j] > media)
        contador++;

    printf("%.3f%%\n", (contador*100.0)/num_alunos);
    contador = 0;
    media = 0;

  }
}
