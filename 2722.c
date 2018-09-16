/*
	@autor: Malbolge;
	@data: 16/09/2018;
	@nome: Pegadinha de Evergreen;
*/

#include <stdio.h>
#include <string.h>

void main ()
{

	char nome[100], sobrenome[100], nomecmpl[300];
	unsigned short casos, i, j, k;
	unsigned contador, aux;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %[^\n] %[^\n]", nome, sobrenome);

		contador = 0;
		i = 0;
		k = 0;
		j = 0;

		aux = strlen(sobrenome);

		// Um laço que continua até que o tamanho da (talvez) menor string acabe;
		// Uma vez que a string do 'nome' sempre é iterada primeiro que a 'sobrenome';
		// A string 'sobrenome' vai acabar antes que a 'nome';
		while (aux--)
		{

			while (nome[i])
			{	
				// A string 'nomecmpl' recebe as letras em 'nome' até que 'contador' seja 2
				// 'contador' sendo == 2 significa que passei duas letras da string fonte para a string destino;
				// O laço para e o laço da string 'sobrenome' itera da mesma forma;
				nomecmpl[k++] = nome[i++];
				contador++;

				if (contador == 2)
					break;
			}

			contador = 0;
			while (sobrenome[j])
			{

				nomecmpl[k++] = sobrenome[j++];
				contador++;

				if (contador == 2)
					break;


			}

			contador = 0;
		}

		nomecmpl[k] = '\0';
		printf("%s\n", nomecmpl);
	}
}