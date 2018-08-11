#include <stdio.h>

int main ()
{

  int x, z, i, cont = 1, soma = 0;
  scanf("%d", &x);

  do{

    scanf("%d", &z);

  } while (z <= x);

//printf("Valor de X: %d\n", x);
//printf("valor de Z: %d\n\n", z);
//printf("Teste efetuado com sucesso!\n\n");

soma = x;
//printf("O valor de soma é: %d\n", soma);

do{

  ++x;
  soma += x;
  cont++;
  //printf("O valor da soma atual é: %d\n", soma);
  //printf("O valor de cont atual é: %d\n", cont);

} while (soma <= z);

  printf("%d\n", cont);

}
