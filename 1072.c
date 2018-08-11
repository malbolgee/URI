#include <stdio.h>


int main () {

  int x, contout = 0, contin = 0, i, y;

  scanf("%d", &x);

  for (i = 0; i < x; i++){

    scanf("%d", &y);
    if (y >= 10 && y <= 20){

      contin++;

    }
    else{

      contout++;

    }
  }

  printf("%d in\n", contin);
  printf("%d out\n", contout);

}
