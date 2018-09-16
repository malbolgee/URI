/*
	@autor: Malbolge;
	@data: 15/09/2018;
	@nome: Problema com a Calculadora;
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

short somaNum(char *);

void main ()
{

	unsigned casos, i; 
	char caracteres[15], caractere, lixo;

	scanf("%u", &casos);
	scanf("%c", &lixo); // Trata o buffer do scanf anterior;

	while (casos--)
	{

		// Trata caractere a caractere na entrada;
		// Caso o caractere seja um número, 'i' incrementa para escrever na próxima posição esse caractere;
		// Se não for um número, é feito uma verificação se na posição atual já tem um número
		// Caso seja verdadeiro, um espaço é escrito na próxima posição;
		// Caso contrário, um espaço é escrito na posição atual;
		// Esse método resultará em uma string com apenas um espaço entre os conjuntos de números;

		i = 0;
		do
		{
			scanf("%c", &caractere);

			if(isdigit(caractere))
			{	
				i++;
				caracteres[i] = caractere;
			}
			else
				if(isdigit(caracteres[i]))
				{
					i++;
					caracteres[i] = ' ';
				}
				else
					caracteres[i] = ' ';
			
		} while (caractere != '\n');

		// Grava o caractere nulo ao final da string formada;
		caracteres[i] = '\0';

    	printf("%hd\n", somaNum(caracteres));

    	memset(caracteres, 0, sizeof(caracteres));
	}
}

short somaNum(char *str)
{

	unsigned short i, j, k, tam;
	unsigned short aux, contador = 0, l, z;
	short numeros[5], soma = 0;

	tam = strlen(str);

	aux = tam;
	j = 1;
	while (aux--)
	{
		k = 0;
		// Esse laço transforma todos os caracteres que são números na string em inteiro e os salva num vetor de inteiros;
		for (i = j; i < tam; i++)
		{	
			if (isdigit(str[i]))
			{	
				contador++;
				numeros[k++] = (int)(str[i] - 48);
			}
			else
			{	
				// Se entrou no else, foi porque encontrou um espaço
				// E uma vez que há exatamente e apenas um espaço entre os números
				// 'i' incrementa, porque da próxima vez que o laço começar a rodar
				// Vai com certeza começar de um número
				// Caso contrário, entraria em um loop;
				i++;
				break;
			}
		}
		
		// A próxima vez que o laço rodar, tem que começar da onde parou;
		// Por isso, ao final, 'j' recebe o valor de 'i';
		j = i;

		// 'z' vai controlar se o dígito analisado vai estar na casa das centenas, dezenas ou unidade;
		// A variável 'contador' no laço anterior controla quantos dígitos o número terá;
		for (l = 0, z = contador; l < contador; l++, z--)
		{

			if (z == 1)
				soma += numeros[l];
			else if (z == 2)
				soma += numeros[l] * 10;
			else if (z == 3)
				soma += numeros[l] * 100;

		}

		memset(numeros, 0, sizeof(numeros));
		contador = 0;

	}

	return soma;
	
}