/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Cédulas;
*/

#include <stdio.h>

int main (){

int nota, resultado;
scanf("%d", &nota);


printf("%d\n", nota);
resultado = nota/100;
printf("%d nota(s) de R$ 100,00\n", resultado);
nota = nota % 100;

resultado = nota/50;
printf("%d nota(s) de R$ 50,00\n", resultado);
nota = nota % 50;

resultado = nota/20;
printf("%d nota(s) de R$ 20,00\n", resultado);
nota = nota % 20;

resultado = nota/10;
printf("%d nota(s) de R$ 10,00\n", resultado);
nota = nota % 10;

resultado = nota/5;
printf("%d nota(s) de R$ 5,00\n", resultado);
nota = nota % 5;

resultado = nota/2;
printf("%d nota(s) de R$ 2,00\n", resultado);
nota = nota % 2;

resultado = nota/1;
printf("%d nota(s) de R$ 1,00\n", resultado);

}
