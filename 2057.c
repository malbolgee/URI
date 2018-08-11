
#include <stdio.h>

int main() {
	unsigned int saida, voo;
  int fuso;

  scanf("%d %d %d", &saida, &voo, &fuso);

  // se a saida foi as 0 hora
  // para fins de calculo
  // melhor considerar como 24h, pois se o fuso > voo
  // teriamos um valor negativo como resultado
  if (saida == 0) {
    saida = 24;
  }

    // calcula o fuso e verifica
  // se o (saida + voo - fuso) for maior que 1 dia.
  saida = ((saida + voo + fuso) % 24);

  printf("%d\n",saida);

	return 0;
}
