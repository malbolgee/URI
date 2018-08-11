/*
	@autor: Malbolge;
	@data: 20/07/2018;
	@nome: Experiências;
*/

#include "stdio.h"
#include "string.h"


int main (){

int testes, coelho = 0, sapo = 0, rato = 0, i, temp = 0, total = 0;
float pcoelho, psapo, prato;
char letra;

scanf("%d", &testes);

for (i = 0; i < testes; i++){

	scanf("%d %c", &temp, &letra);

	if (letra == 'C'){

		coelho += temp;

	}else if (letra == 'R'){

		rato += temp;

	}else if (letra == 'S'){

		sapo += temp;

	}

	total += temp;
}

	printf("Total: %d cobaias\n", total);
	printf("Total de coelhos: %d\n", coelho);
	printf("Total de ratos: %d\n", rato);
	printf("Total de sapos: %d\n", sapo);

	pcoelho = coelho*100.0/total;
	prato = rato*100.0/total;
	psapo = sapo*100.0/total;


	printf("Percentual de coelhos: %.2f %%\n", pcoelho);
	printf("Percentual de ratos: %.2f %%\n", prato);
	printf("Percentual de sapos: %.2f %%\n", psapo);

}
