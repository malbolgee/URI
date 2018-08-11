#include <stdio.h>

int main () {

float a, media = 0, contm = 0;
int i, cont = 0;

for (i = 0; i < 6; i++){

  scanf("%f", &a);
  if (a > 0){

    cont++;
    contm += a;

  }
}

media = contm/cont;
printf("%d valores positivos\n", cont);
printf("%.1f\n", media);

}
