/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Tempo de Jogo;
*/

#include <stdio.h>

int main () {

  int inicio, fim, resultado;
  scanf("%d %d", &inicio, &fim);

  if (inicio < fim){

    resultado = (fim - inicio);
    printf("O JOGO DUROU %d HORA(S)\n", resultado);

  }

  else{

    if (inicio == fim){

      printf("O JOGO DUROU 24 HORA(S)\n");

    }

    else{

      resultado = (24 - inicio + fim);
      printf("O JOGO DUROU %d HORA(S)\n", resultado);

    }
  }
}
