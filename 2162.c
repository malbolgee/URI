/*
	@autor: Malbolge;
	@data: 13/10/2018;
	@nome: Picos e Vales;
*/

#include <stdio.h>

int main() {
  /*
    paisagens - quantidade de paisagens a ser lida
    atual - altura da paisagem atual
    anterior - altura da paisagem anterior
    ehPadrao - se as paisagens lida ate o momento estão no padrão
    pico - se a minha paisagem anterior é um pico
  */
    int paisagens, atual, anterior, ehPadrao = 1, pico;

    scanf("%d",&paisagens);
    if (paisagens == 1) {
        //se eu só tenho 1 paisagem, então já está no padrão
        scanf("%d",&atual);
        printf("%d\n", ehPadrao);
    } else if (paisagens == 2) {
        //se eu tenho 2 paisagens, elas não podem ser iguais
        scanf("%d",&anterior);
        scanf("%d",&atual);
        printf("%d\n", !(atual == anterior));
    } else {
        // caso eu tenha 3 ou mais paisagens
        // leio as duas primeiras, e decremento o contador de paisagens
        scanf("%d",&anterior);
        scanf("%d",&atual);
        paisagens -= 2;
        // verifico se as duas primeiras paisagens formam um pico.
        pico = atual > anterior;
        do {
            //leio as paisagens seguintes 1 a uma
            anterior = atual;
            scanf("%d",&atual);
            paisagens--;
            // se ate a leitura atual eu ainda estou dentro do padrão, eu devo continuar testando
            // caso contrário, só vou lendo os valores até o fim, sem realizar nenhum processamento.
            if (ehPadrao) {
                if (pico) {
                    // se eu ainda estou no padrão e minhas duas paisagens anteriores formavam um pico
                    // então meu atual deve ser menor que o anterior (vale)
                    ehPadrao = atual < anterior ;
                    //agora eu não tenho um pico e sim um vale..
                    pico = 0;
                } else {
                    // se eu ainda estou no padrão e minhas duas paisagens anteriores formavam um vale
                    // então meu atual deve ser maior que o anterior (pico)
                    ehPadrao = atual > anterior;
                    //agora eu não tenho um pico e sim um vale..
                    pico = 1;
                }
            }
        } while (paisagens > 0);
        printf("%d\n",ehPadrao);
    }
    return 0;
}
