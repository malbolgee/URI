/*
	@autor: Malbolge;
	@data: 03/10/2018;
	@nome: Justificador II;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct{

	char palavra[51];

} string;

typedef struct{

	char saida[51];

} saida;


void main ()
{

	unsigned short casos, aux, tam;
	unsigned short maior, atual, i, j, k;

	scanf("%hu", &casos);
	while (true)
	{	

		if (casos == 0)
			break;

		// 'aux' recebe o valor de 'casos' que será modificada no laço;
		aux = casos;

		// Vetores dos tipos 'string' e 'saida' para simular um arraylist;
		string palavra[aux];
		saida textoSaida[aux];

		i = 0;
		// Eche o vetor de strings com as entradas;
		// Note que não é necessário nos preocuparmos com os espaços que podem
		// Vir na frente da string, como não estou limpando o buffer
		// O C descarta esses espaços, poupando o nosso trabalho;
		while (casos--)
			scanf(" %[^\n]", palavra[i++].palavra);

		i = 0;
		// 'tam' recebe o valor de 'aux' que será modificada no laço;
		tam = aux;
		while (aux--)
		{
			j = 0;
			k = 0;
			while (true)
			{
				// Enquanto o caracter que estiver na posição atual for uma letra
				// O passe para a outra struct
				// A struct que recebe as letras, formará a nova palavra sem espaços sobressalentes;
				while (isalpha(palavra[i].palavra[j]))	
					textoSaida[i].saida[k++] = palavra[i].palavra[j++];

				// Se o caractere que fez o laço while sair foi o caractere de final de string,
				// Significa que a string acabou, por tanto, preciso parar o laço mais externo;
				if (palavra[i].palavra[j] == '\0')
					break;

				// Se não, entre nesse novo laço, porque se a string não acabou, foi porque
				// Encontrou um espaço;
				// Enquanto os caracteres que não forem letras forem espaços, só avança na string;
				// Se por acaso um desses caracteres for o caractere nulo
				// Significa que a string acabou, preciso parar o laço;
				while (!isalpha(palavra[i].palavra[j]))
				{	
					j++;
					if (palavra[i].palavra[j] == '\0')
						break;
				}

				// Se o caractere que que fez o while acima parar foi o caractere nulo, preciso
				// Parar o while mais externo;
				if (palavra[i].palavra[j] == '\0')
					break;

				// Se não, coloco um espaço marcando a separação
				// entre uma palavra e outra;
				textoSaida[i].saida[k++] = ' ';

			}
				
				// Caractere nulo ao final da string;
				textoSaida[i].saida[k] = '\0';
				i++;

				
		}	

				maior = 0;
				// A justificação na saída é dada em termos da maior string;
				// Por isso, esse laço acha a maior string contida no struct 
				// Com as strings de saída;
				for(i = 0; i < tam; i++)
				{
					atual = strlen(textoSaida[i].saida);
					if (atual > maior)
						maior = atual;

				}

		// Flag '*' antes da diretiva de formatação '%s'
		// Nos fornece um recuo dinâmico;
		for (i = 0; i < tam; i++)
			printf("%*s\n", maior, textoSaida[i].saida);

		scanf("%hu", &casos);

		if(casos != 0)
			printf("\n");
		
	}
}