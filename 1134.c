#include <stdio.h>

int main () {

int x, alcool = 0, gasolina = 0, diesel = 0;

do
{
scanf("%d", &x);
switch (x)
{

  case 1:

    alcool++;
    break;

  case 2:

    gasolina++;
    break;

  case 3:

    diesel++;
    break;

}

} while(x != 4);

printf("MUITO OBRIGADO\n");
printf("Alcool: %d\n", alcool);
printf("Gasolina: %d\n", gasolina);
printf("Diesel: %d\n", diesel);

}
