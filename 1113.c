#include <stdio.h>


int main () {

int x, y;
scanf("%d %d", &x, &y);

while (x != y)
{

if (y > x)
{

  printf("Crescente\n");

}
else
{

  printf("Decrescente\n");

}
scanf("%d %d", &x, &y);
}
}
