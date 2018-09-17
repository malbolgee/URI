/*
	@autor: Malbolge;
	@data: 17/09/2018;
	@nome: Mensagem Oculta;
*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main ()
{

	char texto[51], resultado[51], lixo;
	unsigned short i, j;
	unsigned casos;

	scanf("%u", &casos);
	scanf("%c", &lixo); // Trata o buffer do scanf anterior;

	while (casos--)
	{
		
		scanf("%[^\n]", texto);
		scanf("%c", &lixo); // Trata o buffer do scanf anteior;
	
		i = 0;
		j = 0;

		// Laço dura até que o caractere nulo seja alcançado;
		while (texto[i])
		{

			// Se o caractere no índice atual for um espaço, simplesmente avançe;
			if (texto[i] == ' ')
				i++;
	
			else
			{	
				// Caso contrário, será uma letra
				// Então coloque essa letra na string resultado;
				resultado[j++] = texto[i++];

				// Enquanto os próximos caracteres também forem letras, apenas avançe;
				// Dessa forma, quando encontrar um espaço, cairá no primeiro 'if' e avançará os espaços
				// Até encontrar uma letra;
				while (isalpha(texto[i]))
					 i++;	
			}	
		}

		// Grava o caractere nulo ao final da string para marcar o seu final;
		resultado[j] = '\0';
		printf("%s\n", resultado);
		memset(resultado, 0, sizeof(resultado));
	}

}