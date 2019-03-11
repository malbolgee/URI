/*
    @autor: Malbolge;
    @data: 10/03/2019;
    @nome: Pedra, Papel, Ataque Aéreo;
*/

#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

void main ()
{

    int n;
    char player1[10];
    char player2[10];

    scanf("%d", &n);

    while (n--)
    {

        scanf("%s %s", player1, player2);

        if (strcmp(player1, "ataque") == 0 && strcmp(player2, "ataque") == 0)
            printf("Aniquilacao mutua\n");

        if (strcmp(player1, "papel") == 0 && strcmp(player2, "papel") == 0)
            printf("Ambos venceram\n");

        if (strcmp(player1, "pedra") == 0 && strcmp(player2, "pedra") == 0)
            printf("Sem ganhador\n");

        if (strcmp(player1, "pedra") == 0 && strcmp(player2, "papel") == 0)
            printf("Jogador 1 venceu\n");

        if (strcmp(player2, "pedra") == 0 && strcmp(player1, "papel") == 0)
            printf("Jogador 2 venceu\n");

        if (strcmp(player1, "ataque") == 0 && strcmp(player2, "papel") == 0)
            printf("Jogador 1 venceu\n");

        if (strcmp(player2, "ataque") == 0 && strcmp(player1, "papel") == 0)
            printf("Jogador 2 venceu\n");
        
        if (strcmp(player1, "ataque") == 0 && strcmp(player2, "pedra") == 0)
            printf("Jogador 1 venceu\n");

        if (strcmp(player2, "ataque") == 0 && strcmp(player1, "pedra") == 0)
            printf("Jogador 2 venceu\n");

    }

}