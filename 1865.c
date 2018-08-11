#include <stdio.h>
#include <string.h>

int main() {

  unsigned int casos, forca;
  char nome[40];
  scanf("%d",&casos);

  do {

  	// essa questao eh uma pegadinha.
  	//aqueles que conhecem HQ's ou prestaram atencao nos casos de entrada.
  	// percebem que somente Thor por levantar o martelo**
    scanf(" %s %d", nome, &forca);

    // strcmp retorna zero se as strings forem iguais
    // eu poderia usar a negacao logica "!"
    // porem como a maioria das entradas tende a nao ser "Thor"
    // o programa vai ser mais eficiente nessa ordem
    if(strcmp(nome,"Thor"))
    	printf("N\n");
    else
    	printf("Y\n");

    casos--;
  } while(casos>0);

  return 0;
}
