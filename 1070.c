#include <stdio.h>


int main () {

  int a, i, cont = 0;
  scanf("%d", &a);

  for (i = a; cont < 6; i++){

    if (i % 2 != 0){

      printf("%d\n", i);
      cont++;
      
    }
  }
}
