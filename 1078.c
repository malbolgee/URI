#include <stdio.h>


int main () {

int x, i, resultado = 0;
scanf("%d", &x);

for (i = 1; i <= 10; i++){
  resultado = i*x;
  printf("%d x %d = %d\n", i, x, resultado);

}
}
