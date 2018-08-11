#include <stdio.h>


int main () {

int x, y, i, z;
int l, m, n, cont = 0, cont2 = 0;
scanf("%d ", &x);

for (i = 0; i < x; i++){
  scanf("%d %d", &m, &n);
  cont = 0;
  if (m > n){
  for (l = n + 1; l < m; l++){
      if (l % 2 != 0){

        cont += l;

      }
    }
    printf("%d\n", cont);
  }
  else{
    for (l = m + 1; l < n; l++){
      if (l % 2 != 0){

        cont2 += l;

      }
    }
    printf("%d\n", cont2);
  }
}
}
