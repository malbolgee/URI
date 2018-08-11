#include <stdio.h>


int main () {

int x, i, anterior = 0, proximo = 0, posicao = 0;

for (i = 1; i < 10; i++){

  scanf("%d", &x);

  anterior = x;
  if (anterior < proximo){
    proximo = anterior;
    posicao = i;

  }
}
printf("%d\n", anterior);
printf("%d\n", posicao);
}
