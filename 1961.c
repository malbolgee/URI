#include <stdio.h>
#include <string.h>

int mod(int a);

int main() {

  int pulo, canos;
  char altura = -1;

  scanf("%d %d", &pulo, &canos);

  while(canos>0) {

    char cano;
    scanf("%d", &cano);

    // a logica principal da questao está aqui
    // se o pulo do sapo, para cima ou para baixo
    // for menor que o valor absoluto da altura a ser ultrapassada
    // entao e fim de jogo!
    if(pulo > mod(altura-cano)) {
      printf("GAME OVER\n");
      return 0;
    }
    // se o pulo for possivel
    // entao a nova altura do sapo, sera a altura do cano atual
    // em relacao ao solo
    // e passamos a ler a altura do proximo cano
    altura = cano;
    canos--;
  }
  printf("YOU WIN\n");
  return 0;
}

int mod(int a) {
  if(a < 0)
    return -a;
  return a;
}
