/*
  @autor: Malbolge;
  @data: 03/08/2018;
  @nome: De Quem é a Vez?;
*/

#include <stdio.h>
#include <string.h>

int main ()
{

  unsigned short int QT;
  int n, m;

  scanf("%hd", &QT);

  for (unsigned short i = 0; i < QT; i++)
  {

    char player1[100], player2[100], escolhap1[10], escolhap2[10];

    scanf("%s %s %s %s", player1, escolhap1, player2, escolhap2);
    scanf("%d %d", &n, &m);

    if (strcmp(escolhap1, "PAR") == 0 && (m+n)%2 == 0)
        printf("%s\n", player1);
    else if (strcmp(escolhap1, "IMPAR") == 0 && (m+n)%2 != 0)
        printf("%s\n", player1);
    else
        printf("%s\n", player2);

  }
}
