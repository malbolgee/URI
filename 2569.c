/*
	@autor: Malbolge;
	@data: 29/10/2018;
	@nome: A Bruxa do 7 x 1;
*/

#include <stdio.h>
#include <string.h>

void retiraZero(const char *, char *);
long int StrToInt(char *str);
void IntToStr(unsigned short, char *);

void main ()
{

	char operandoA[11], operandoB[11], resultadoStr[100];
	char operandoASem7[11], operandoBSem7[11], resultadoStrSem7[100];
	long int resultado;
	char operacao;

	scanf("%s %c %s", operandoA, &operacao, operandoB);

 	retiraZero(operandoA, operandoASem7);
	retiraZero(operandoB, operandoBSem7);

	if (operacao == '+')
		resultado = StrToInt(operandoASem7) + StrToInt(operandoBSem7);
	else if (operacao == '*')
		resultado = StrToInt(operandoASem7) * StrToInt(operandoBSem7);

	sprintf(resultadoStr, "%ld", resultado);

	retiraZero(resultadoStr, resultadoStrSem7);
	printf("%s\n", resultadoStrSem7);

}

void retiraZero(const char *operando, char *operandoSem7)
{

	unsigned short i = 0;
	unsigned short j = 0;

	while (operando[i])
	{

		if (operando[i] == '7')
			operandoSem7[j++] = '0';
		else
			operandoSem7[j++] = operando[i];

		i++;
	}

	operandoSem7[j] = '\0';

}

long int StrToInt(char *str)
{

	long int i, multiplicador = 1, numero = 0;

	for(i = strlen(str) - 1; i >= 0; i--, multiplicador *= 10)
		numero +=  (str[i] - 48) * multiplicador;

	return numero;
}
