/*
  @autor: Micael Viana;
  @data: 14/08/2018;
  @nome: Número Primo;
*/

#include <stdio.h>
#include <math.h>
#define FALSE 0
#define TRUE 1

int main()
{

 int x;
 unsigned short numero, raiz, i, j;
 unsigned char primo;

 scanf ("%hd", &numero);

 for (i = 0; i < numero; i++)
 {

  primo = TRUE;

  scanf ("%d", &x);

  raiz = (int)sqrt(x);

  if (x != 2  && x % 2 == 0 || x == 1)
   primo = FALSE;

  for (j = 3; primo == TRUE && j <= raiz; j += 2)
    if (x % j == 0)
      primo = FALSE;

  if (primo)
   printf ("Prime\n");
  else
   printf("Not Prime\n");

 }
}
