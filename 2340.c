/*
  @autor: Malbolge;
  @data: 04/08/2018;
  @nome: Feira de Bactérias;
*/


#include <stdio.h>
#include <math.h>


int n,id, i;
double max_atual,d,c,res;

int main() {
    scanf("%d", &n);

    for(i = 0; i < n; i++){

        scanf("%lf %lf", &d, &c);
        res = c * log10(d);

        if(res > max_atual){
            max_atual = res;
            id = i;
        }
    }
    printf("%d\n",id);
	return 0;
}
