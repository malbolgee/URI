#include <stdio.h>

int main () {

float a;
int i, cont = 0;

for (i = 0; i < 6; i++){

  scanf("%f", &a);
  if (a > 0){

    cont++;

  }
}
printf("%d valores positivos\n", cont);

}
