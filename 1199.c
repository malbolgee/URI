/*
	@autor: Malbolge;
	@data: 15/10/2018;
	@nome: Conversão Simples de Base;
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

long int HexToInt(char *);
long int StrToInt(char *);

void main(){

	char numero[12];
	while(scanf("%s", numero) && numero[0] != '-')
		if(numero[0] == '0' && numero[1] == 'x')
			printf("%ld\n", HexToInt(numero));
		else
			printf("0x%lX\n", StrToInt(numero));

}

// Função converte uma string com caracteres numéricos em um inteiro;
long int StrToInt(char *str){
	long int tamanho, ret, multiplicador;

	for(tamanho = strlen(str) - 1, multiplicador = 1, ret = 0; tamanho >= 0; tamanho--, multiplicador *= 10)
		ret +=  (str[tamanho] - 48) * multiplicador;

	return ret;
}

// Função converte um hexadecimal(string) para inteiro;
long int HexToInt(char *str){
	long int ret, i, tamanho;
	for(i = 0, tamanho = strlen(str) - 1, ret = 0; str[tamanho] != 'x'; i++, tamanho--){
		if(str[tamanho] >= 'A' && str[tamanho] <= 'F')
			ret += (str[tamanho] - 'A' + 10) * pow(16, i);
		else
			if(str[tamanho] >= 'a' && str[tamanho] <= 'f')
				ret += (str[tamanho] - 'a' + 10) * pow(16, i);
			else
				ret += (str[tamanho] - 48) * pow(16, i);
	}

	return ret;
}
