#include <stdio.h>


int main () {

int i, cont = 0, a;

for (i = 0; i < 5; i++){
  scanf("%d", &a);
  if (a % 2 == 0){

    cont++;

  }
}

printf("%d valores pares\n", cont);

}
