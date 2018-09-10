/*
	@autor: Malbolge;
	@data: 10/09/2018;
	@nome: Coleção de Pomekon;
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


//Cria uma struct do tipo 'string';
typedef struct {

	char pokemon[1000];

} string;


void main ()
{

	unsigned short casos, aux, i = 1, j;
	short captura = 151;
	bool harepetido = false;

	scanf("%hu", &casos);
	aux = casos;
	

	//Vetor do tipo string
	string pokedex[aux + 1];

	while (casos--)
	{

		//Lê a string até que o enter seja pressionado;
		scanf(" %[^\n]", pokedex[i].pokemon);

		//Laço começca da string imediatamente anterior à posição atual;
		for (j = i - 1; j >= 1; j--)
		{	
			//Caso a string contina na posição j do vetor seja igual à contida na posição atual
			//harepetido recebe 'true' e o laõ para
			//Pois se há pelo menos um repetido na 'pokedex', não há motivo para cotinuar a procura;
			if (strcmp(pokedex[j].pokemon, pokedex[i].pokemon) == 0)
			{
				harepetido = true;
				break;
			}
		}

		//Se não há repetição, variável captura decrementa;
		if (!harepetido)
			captura--;
	
		harepetido = false;	
		
		i++;
	
	}

	printf("Falta(m) %hu pomekon(s).\n", captura);

}