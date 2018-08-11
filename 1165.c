/*
  @autor: Micael Viana;
  @data: 11/08/2018;
  @nome: Número Primo;
*/

#include <stdio.h>
#define FALSE 0
#define TRUE 1

int main()
{
 int x;
 unsigned short n;
 unsigned char primo;

 scanf ("%hd",&n);

 for (unsigned short i = 0; i < n; i++)
 {

  primo = TRUE;
  scanf ("%d",&x);

  if (x > 2 && x % 2 == 0 || x <= 1)
   primo = FALSE;

  for (unsigned short i = 3; primo == TRUE && i <= x/2; i += 2)
    if (x % i == 0)
      primo = FALSE;

  if (primo)
   printf ("%d eh primo\n",x);
  else
   printf("%d nao eh primo\n",x);
 }
}
