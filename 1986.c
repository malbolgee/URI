/*
	@autor: Malbolge;
	@data: 29/09/2018;
	@nome: Perdido em Marte;
*/

#include <stdio.h>

void main ()
{

	unsigned short caractere, mensagemTam;

	scanf("%hu", &mensagemTam);

	do
	{
		// Lê a entrada comom hexadecimal;
		scanf("%hx", &caractere);

		// Verifica se o caractere lido é um espaço;
		// Se não for, printa esse caractere com a diretiva %c
		// O C converte o código hexa da tabela ASCII
		// Para o símbolo correspondente a esse código;
		// Como o URI só verifica a saída ao final do programa
		// Posso imprimir os caracreres assim que os leio;
		if (caractere != ' ')
		{
			printf("%c", caractere);
			mensagemTam--;
		}


	} while (mensagemTam);

	printf("\n");
}