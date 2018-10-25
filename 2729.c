/*
	@autor: Malbolge;
	@data: 25/10/2018;
	@nome: Lista de Compras;
*/

#include <stdio.h>
#include <string.h>

typedef struct{

	char item[21];

} lista;

void insertion(lista *listaCompras, unsigned short tam);

void main ()
{

	unsigned short casos, i, j;
	lista listaCompras[1010];
	char itens[20010], *cadaItem;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %[^\n]", itens);

		i = 0;
		// Definição de um token para quebrar a string em substrings;
		// Aqui é definido um espaço como token, isso quer dizer que toda
		// vez que a função strtok encontrar um espaço na string, ele irá
		// Devolver um ponteiro para a substring que existe antes desse espaço;
		cadaItem = strtok(itens, " ");
		// Logo após isso, a substring é salva em um campo da struct;
		strcpy(listaCompras[i++].item, cadaItem);

		// Esse laço faz esse processo para o resto da string;
		do
		{

			cadaItem = strtok('\0', " ");
			if (cadaItem == NULL)
				break;

			strcpy(listaCompras[i].item, cadaItem);

			i++;

		} while (cadaItem);

		// Ordena a struct;
		insertion(listaCompras, i);

		// Imprime os itens que são diferentes uns dos outros;
		for (j = 0; j < i; j++)
		{

			if (strcmp(listaCompras[j].item, listaCompras[j - 1].item) != 0)
			{
				if (j != 0 && j != i)
					printf(" ");

				printf("%s", listaCompras[j].item);
			}

		}

		printf("\n");
		memset(listaCompras, 0, sizeof(listaCompras));
		memset(itens, 0, sizeof(itens));

	}

}

// Função para ordenar;
void insertion(lista *listaCompras, unsigned short tam)
{

	short i = 1, j;
	lista pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = listaCompras[i];

		while (j >= 0 && strcmp(listaCompras[j].item, pivo.item) > 0)
		{

			listaCompras[j + 1] = listaCompras[j];
			j--;

		}

		listaCompras[j + 1] = pivo;
		i++;

	}

}
