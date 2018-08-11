/*
  @autor: Malbolge;
  @data: 28/07/2018;
  @nome: Pula Sapo;
*/

#include <stdio.h>
#define TRUE 1
#define FALSE 0
int main ()
{
    unsigned short int P, N, anterior, proximo, teste, vitoria = TRUE;
    unsigned short int i;
    unsigned short int altura; // altura dos canos
    scanf ("%hd %hd",&P,&N); //P: altura do pulo do sapo e N: numero de canos
    scanf ("%hd",&altura);
    anterior = altura;
    for (i = 1; i < N; i++)
    {
        scanf ("%hd",& altura);
        proximo = altura;
        teste = proximo - anterior;
        if (teste < 0)
        {
            teste = teste * (-1);
        }
        if (teste > P)
        {
            vitoria = FALSE;
        }
        anterior = proximo;

    }
    if (vitoria == TRUE)
        printf ("YOU WIN\n");
    else
        printf ("GAME OVER\n");
}
