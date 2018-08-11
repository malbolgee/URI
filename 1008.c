/*
	@autor: Malbolge;
	@data: 19/07/2018;
	@nome: Salário;
*/

#include <stdio.h>

float main (){

unsigned short int funcionario, horas;
float valor, salario;

scanf("%hd", &funcionario);
scanf("%hd", &horas);
scanf("%f", &valor);

salario = horas*valor;

printf("NUMBER = %d\n", funcionario);
printf("SALARY = U$ %.2f\n", salario);


}
