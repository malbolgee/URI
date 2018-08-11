#include <stdio.h>
#include <math.h>


int main () {

int x, cont = 0, i;
scanf("%d", &x);

for (i = 1; i <= x; i++){

  if (i % 2 == 0){
    cont = pow(i, 2);
    printf("%d^2 = %d\n", i, cont);

  }
}
}
