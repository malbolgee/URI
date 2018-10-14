/*
	@autor: Malbolge;
	@data: 13/10/2018;
	@nome: Discagem de Voz;
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{

	char letra;
	unsigned char numero;

} dicionario;

char caracterSrc(dicionario *caracteres, unsigned short tam, char caractere);

void main ()
{
	// vetor de char irá receber a string com os números e letras dicados;
	char numeros[301];
	unsigned short i, j, k, contador;
	// vetor de struct irá receber as letras e os números associados a cada letra;
	dicionario caracteres[26];

	contador = 0;
	// laços para preencher o struct com as letras e seus números;
	for (i = 0, j = 2, k = 'A'; i < 15; i++)
	{

		caracteres[i].letra = k++;
		caracteres[i].numero = j;
		contador++;
		if (contador == 3)
		{
			j++;
			contador = 0;
		}

	}

	for (i = 15, j = 7, k = 'P'; i < 19; i++)
	{

		caracteres[i].letra = k++;
		caracteres[i].numero = j;

	}

	for (i = 19, j = 8, k = 'T' ; i < 22; i++)
	{

		caracteres[i].letra = k++;
		caracteres[i].numero = j;

	}

	for (i = 22, j = 9, k = 'W'; i < 26; i++)
	{

		caracteres[i].letra = k++;
		caracteres[i].numero = j;

	}

	// leitura da string de entrada;
	while (scanf(" %[^\n]", numeros) != EOF)
	{

		i = 0;
		// Percorre a string em busca dos marcadores fixados pela questão;
		// Todos os símbolos que não sejam '#' e '*' devem ser descartados;
		while (numeros[i])
		{
			// Se encontrou uma letra, ela deve ser substituída pelo seu número
			// Correspondente no teclado do celular;
			// A função caracterSrc() faz esse trabalho;
			// Ela devolve o número associado a letra na procura;
			if (isalpha(numeros[i]))
				printf("%hhd", caracterSrc(caracteres, 26, numeros[i]));
			else if (isdigit(numeros[i]))
				printf("%c", numeros[i]);
			else if (numeros[i] == '#')
				printf("%c", numeros[i]);
			else if (numeros[i] == '*')
				printf("%c", numeros[i]);

			i++;
		}

		// Reseta a string para a próxima iteração;
		// Note que a próxima iteração pode ter uma string menor
		// Do que a string da iteração atual, por isso é importante resetar;
		memset(numeros, 0, sizeof(numeros));
		printf("\n");
	}

}

// Função que procura a letra na struct e retorna seu número associado;
char caracterSrc(dicionario *caracteres, unsigned short tam, char caractere)
{

	unsigned short i;

	for (i = 0; i < tam; i++)
		if (toupper(caractere) == caracteres[i].letra)
			return caracteres[i].numero;

	return caractere;

}
