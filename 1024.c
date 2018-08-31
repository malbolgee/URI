/*
  @autor: Malbolge;
  @data: 30/08/2018;
  @nome: Criptografia;
*/

#include <stdio.h>
#include <string.h>

void main (void)
{
  char palavra[1100], aux;
  unsigned casos;
  unsigned short i, j, tam, tamMetade;

  scanf("%u", &casos);

  while (casos)
  {

    scanf(" %[^\n]", palavra);

    tam = strlen(palavra);
    tamMetade = tam/2;

    //Primeira passada na string move caracteres minúsculos e maiúsculos 3 posições;
    for (i = 0; i < tam; i++ )
      if ((palavra[i] >= 'A' && palavra[i] <= 'Z') || (palavra[i] >= 'a' && palavra[i] <= 'z'))
        palavra[i] = palavra[i] + 3;

    //Segunda passada inverte a String;
    for (i = 0, j = tam - 1; i < tamMetade; i++, j--)
    {

      aux = palavra[j];
      palavra[j] = palavra[i];
      palavra[i] = aux;

    }
    
    //Terceira passada modifica qualquer caracrete da metade em diante em uma posição;
    for (i = tamMetade; i < tam; i++ )
      if ((palavra[i] >= 32 && palavra[i] <= 176 ))
        palavra[i] = palavra[i] - 1;
    
    printf("%s\n", palavra);

    //Reseta a string para a proxima iteração;
    memset(palavra, 0 , sizeof(palavra));

    casos--;
  }
}